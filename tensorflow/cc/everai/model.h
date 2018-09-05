#ifndef EVERAI_MODEL_H_
#define EVERAI_MODEL_H_

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "tensorflow/core/framework/tensor.h"
#include "tensorflow/cc/saved_model/loader.h"

namespace EverAI {
class Model {
 public:
  Model();
  ~Model();

  bool initialize();
  std::vector<tensorflow::Tensor> run(std::shared_ptr<uint8_t>, uint16_t,
                                      uint16_t, uint16_t,
                                      std::vector<std::string>);

 private:
  std::map<std::string, std::string> input_tensors;
  std::map<std::string, std::string> output_tensors;
  std::unique_ptr<tensorflow::SavedModelBundle> bundle;
};
}

#endif
