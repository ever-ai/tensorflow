#ifndef EVERAI_SDK_H_
#define EVERAI_SDK_H_

#include "model.h"

namespace EverAI {

const std::string kAcceptableTensor{"acceptable"};
const std::string kBlurrinessTensor{"blurriness"};
const std::string kBoundingBoxesTensor{"bounding_boxes"};
const std::string kBrightnessTensor{"brightness"};
const std::string kEmbeddingsTensor{"embeddings"};
const std::string kLandmarksTensor{"landmarks"};

const uint32_t embedding_dimension = 512;
const uint32_t embedding_size = embedding_dimension * sizeof(float);

class Image {
 public:
  Image(unsigned char *, uint16_t, uint16_t, uint16_t);
  ~Image();

  uint16_t height, width, channels;
  std::shared_ptr<unsigned char> data;
};

class Embedding {
 public:
  Embedding();
  Embedding(float *);
  ~Embedding();

  bool Empty() const;

  std::shared_ptr<float> data;
};

class Point {
 public:
  Point();
  Point(float, float);
  ~Point();

  uint16_t x, y;
};

class Landmarks {
 public:
  Landmarks();
  Landmarks(Point, Point, Point, Point, Point);
  ~Landmarks();

  Point left_eye;
  Point right_eye;
  Point nose;
  Point left_mouth;
  Point right_mouth;
};

class BoundingBox {
 public:
  BoundingBox();
  BoundingBox(uint16_t, uint16_t, uint16_t, uint16_t);
  ~BoundingBox();

  uint16_t x, y, width, height;
};

class Face {
 public:
  Face();
  ~Face();

  Landmarks landmarks;
  BoundingBox bounding_box;
  Embedding embedding;
  bool acceptable;
  float bluriness, brightness;
};

class SDK {
 public:
  SDK();
  ~SDK();

  bool initialize();

  std::vector<BoundingBox> DetectBoundingBoxes(const Image &image);
  std::vector<Face> DetectFaces(const Image &image);
  std::vector<Face> ComputeEmbeddings(const Image &image);

 private:
  Model model;
};
}

#endif
