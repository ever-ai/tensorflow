#include <string>
#include <vector>

#include "tensorflow/cc/saved_model/loader.h"
#include "tensorflow/cc/saved_model/signature_constants.h"
#include "tensorflow/cc/saved_model/tag_constants.h"
#include "tensorflow/core/framework/tensor.h"

#include "model.h"

using namespace EverAI;

Model::Model() {}
Model::~Model() {}

std::vector<tensorflow::Tensor> Model::run(
    std::shared_ptr<unsigned char> image, uint16_t height, uint16_t width,
    uint16_t channels, std::vector<std::string> output_names) {
  tensorflow::TensorShape shape({height, width, channels});
  tensorflow::Tensor tensor(tensorflow::DT_UINT8, shape);

  auto tensor_data = tensor.tensor<uint8_t, 3>();
  std::memcpy(tensor_data.data(), image.get(), height * width * channels);

  std::vector<tensorflow::Tensor> outputs;
  tensorflow::RunMetadata run_metadata;
  tensorflow::RunOptions run_options;

  std::vector<std::string> output_tensors;

  for (auto const &output_name : output_names) {
    auto t = this->output_tensors.find(output_name);

    if (t == this->output_tensors.end()) continue;

    output_tensors.emplace_back(t->second);
  }

  auto status = this->bundle->session->Run(
      run_options, {{this->input_tensors["image"], tensor}}, output_tensors, {},
      &outputs, &run_metadata);

  if (!status.ok()) {
    return {};
  }

  return outputs;
}

bool Model::initialize() {
  this->bundle = std::unique_ptr<tensorflow::SavedModelBundle>(
      new tensorflow::SavedModelBundle());

  tensorflow::SessionOptions sessionOptions;
  tensorflow::RunOptions runOptions;

  tensorflow::Status status = tensorflow::LoadSavedModel(
      sessionOptions, runOptions, "model", {tensorflow::kSavedModelTagServe},
      this->bundle.get());

  if (!status.ok()) {
    return false;
  }

  tensorflow::SignatureDef signature =
      this->bundle->meta_graph_def.signature_def()
          .find(tensorflow::kDefaultServingSignatureDefKey)
          ->second;

  for (auto const &i : signature.inputs()) {
    this->input_tensors[i.first] = i.second.name();
  }

  for (auto const &i : signature.outputs()) {
    this->output_tensors[i.first] = i.second.name();
  }

  return true;
}
