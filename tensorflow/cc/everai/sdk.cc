#include <memory>

#include "sdk.h"

using namespace EverAI;

SDK::SDK() {}
SDK::~SDK() {}

bool SDK::initialize() { return this->model.initialize(); }

std::vector<BoundingBox> SDK::DetectBoundingBoxes(const Image &image) {
  auto outputs = this->model.run(image.data, image.height, image.width,
                                 image.channels, {"bounding_boxes"});

  auto count = outputs[0].dim_size(0);
  auto matrix = outputs[0].matrix<float>();

  std::vector<BoundingBox> bboxes;
  bboxes.reserve(count);
  auto start = bboxes.begin();

  for (auto i = 0; i < count; ++i) {
    float x1 = matrix(i, 0);
    float y1 = matrix(i, 1);
    float x2 = matrix(i, 2);
    float y2 = matrix(i, 3);

    BoundingBox bbox(static_cast<uint16_t>(x1), static_cast<uint16_t>(y1),
                     static_cast<uint16_t>(x2 - x1),
                     static_cast<uint16_t>(y2 - y1));
    bboxes.insert(start + i, bbox);
  }

  return bboxes;
}

std::vector<Face> SDK::DetectFaces(const Image &image) {
  auto outputs = this->model.run(
      image.data, image.height, image.width, image.channels,
      {kAcceptableTensor, kBlurrinessTensor, kBoundingBoxesTensor,
       kBrightnessTensor, kLandmarksTensor, });
  auto count = outputs[0].dim_size(0);

  std::vector<Face> faces;
  faces.reserve(count);
  auto start = faces.begin();

  auto acceptable = outputs[0].flat<bool>();
  auto bluriness = outputs[1].flat<float>();
  auto bounding_boxes = outputs[2].tensor<float, 2>();
  auto brightness = outputs[3].flat<float>();
  auto landmarks = outputs[4].tensor<float, 3>();

  for (auto i = 0; i < count; ++i) {
    Face face;
    {
      face.brightness = brightness(i);
      face.bluriness = bluriness(i);
      face.acceptable = acceptable(i);
    }

    {
      float x1 = bounding_boxes(i, 0);
      float y1 = bounding_boxes(i, 1);
      float x2 = bounding_boxes(i, 2);
      float y2 = bounding_boxes(i, 3);

      face.bounding_box = BoundingBox(
          static_cast<uint16_t>(x1), static_cast<uint16_t>(y1),
          static_cast<uint16_t>(x2 - x1), static_cast<uint16_t>(y2 - y1));
    }

    {
      auto l = landmarks;
      face.landmarks = Landmarks(
          Point(l(i, 0, 0), l(i, 0, 1)), Point(l(i, 1, 0), l(i, 1, 1)),
          Point(l(i, 2, 0), l(i, 2, 1)), Point(l(i, 3, 0), l(i, 3, 1)),
          Point(l(i, 4, 0), l(i, 4, 1)));
    }

    faces.insert(start + i, face);
  }

  return faces;
}

std::vector<Face> SDK::ComputeEmbeddings(const Image &image) {
  auto outputs = this->model.run(
      image.data, image.height, image.width, image.channels,
      {kAcceptableTensor, kBlurrinessTensor, kBoundingBoxesTensor,
       kBrightnessTensor, kLandmarksTensor,  kEmbeddingsTensor, });
  auto count = outputs[0].dim_size(0);

  std::vector<Face> faces;
  faces.reserve(count);
  auto start = faces.begin();

  auto acceptable = outputs[0].flat<bool>();
  auto bluriness = outputs[1].flat<float>();
  auto bounding_boxes = outputs[2].tensor<float, 2>();
  auto brightness = outputs[3].flat<float>();
  auto landmarks = outputs[4].tensor<float, 3>();
  auto embeddings = outputs[5].flat<float>();

  for (auto i = 0; i < count; ++i) {
    Face face;
    {
      face.brightness = brightness(i);
      face.bluriness = bluriness(i);
      face.acceptable = acceptable(i);
    }

    {
      float x1 = bounding_boxes(i, 0);
      float y1 = bounding_boxes(i, 1);
      float x2 = bounding_boxes(i, 2);
      float y2 = bounding_boxes(i, 3);

      face.bounding_box = BoundingBox(
          static_cast<uint16_t>(x1), static_cast<uint16_t>(y1),
          static_cast<uint16_t>(x2 - x1), static_cast<uint16_t>(y2 - y1));
    }

    {
      auto l = landmarks;
      face.landmarks = Landmarks(
          Point(l(i, 0, 0), l(i, 0, 1)), Point(l(i, 1, 0), l(i, 1, 1)),
          Point(l(i, 2, 0), l(i, 2, 1)), Point(l(i, 3, 0), l(i, 3, 1)),
          Point(l(i, 4, 0), l(i, 4, 1)));
    }

    {
      float *e = new float[embedding_dimension];
      std::memcpy(e, embeddings.data() + i * embedding_size, embedding_size);
      face.embedding = Embedding(e);
    }

    faces.insert(start + i, face);
  }

  return faces;
}

Embedding::Embedding() {}
Embedding::Embedding(float *data) { this->data = std::shared_ptr<float>(data); }
Embedding::~Embedding() {}

bool Embedding::Empty() const { return this->data == nullptr; }

Point::Point() {}
Point::Point(float y, float x) {
  this->x = static_cast<uint16_t>(x);
  this->y = static_cast<uint16_t>(y);
}
Point::~Point() {}

Face::Face() {}
Face::~Face() {}

Landmarks::Landmarks() {}
Landmarks::Landmarks(Point left_eye, Point right_eye, Point nose,
                     Point left_mouth, Point right_mouth) {
  this->left_eye = left_eye;
  this->right_eye = right_eye;
  this->nose = nose;
  this->left_mouth = left_mouth;
  this->right_mouth = right_mouth;
}

Landmarks::~Landmarks() {}

BoundingBox::BoundingBox() {}
BoundingBox::BoundingBox(uint16_t x, uint16_t y, uint16_t width,
                         uint16_t height) {
  this->x = x;
  this->y = y;
  this->width = width;
  this->height = height;
}
BoundingBox::~BoundingBox() {}

Image::Image(unsigned char *data, uint16_t height, uint16_t width,
             uint16_t channels) {
  this->data = std::shared_ptr<unsigned char>(data);
  this->height = height;
  this->width = width;
  this->channels = channels;
}
Image::~Image() {}
