// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: tensorflow/core/framework/tensor_shape.proto

#ifndef PROTOBUF_tensorflow_2fcore_2fframework_2ftensor_5fshape_2eproto__INCLUDED
#define PROTOBUF_tensorflow_2fcore_2fframework_2ftensor_5fshape_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3002000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3002000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
namespace tensorflow {
class TensorShapeProto;
class TensorShapeProtoDefaultTypeInternal;
extern TensorShapeProtoDefaultTypeInternal _TensorShapeProto_default_instance_;
class TensorShapeProto_Dim;
class TensorShapeProto_DimDefaultTypeInternal;
extern TensorShapeProto_DimDefaultTypeInternal _TensorShapeProto_Dim_default_instance_;
}  // namespace tensorflow

namespace tensorflow {

namespace protobuf_tensorflow_2fcore_2fframework_2ftensor_5fshape_2eproto {
// Internal implementation detail -- do not call these.
struct TableStruct {
  static const ::google::protobuf::uint32 offsets[];
  static void InitDefaultsImpl();
  static void Shutdown();
};
void AddDescriptors();
void InitDefaults();
}  // namespace protobuf_tensorflow_2fcore_2fframework_2ftensor_5fshape_2eproto

// ===================================================================

class TensorShapeProto_Dim : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:tensorflow.TensorShapeProto.Dim) */ {
 public:
  TensorShapeProto_Dim();
  virtual ~TensorShapeProto_Dim();

  TensorShapeProto_Dim(const TensorShapeProto_Dim& from);

  inline TensorShapeProto_Dim& operator=(const TensorShapeProto_Dim& from) {
    CopyFrom(from);
    return *this;
  }

  inline ::google::protobuf::Arena* GetArena() const PROTOBUF_FINAL {
    return GetArenaNoVirtual();
  }
  inline void* GetMaybeArenaPointer() const PROTOBUF_FINAL {
    return MaybeArenaPtr();
  }
  static const ::google::protobuf::Descriptor* descriptor();
  static const TensorShapeProto_Dim& default_instance();

  static inline const TensorShapeProto_Dim* internal_default_instance() {
    return reinterpret_cast<const TensorShapeProto_Dim*>(
               &_TensorShapeProto_Dim_default_instance_);
  }

  void UnsafeArenaSwap(TensorShapeProto_Dim* other);
  void Swap(TensorShapeProto_Dim* other);

  // implements Message ----------------------------------------------

  inline TensorShapeProto_Dim* New() const PROTOBUF_FINAL { return New(NULL); }

  TensorShapeProto_Dim* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const TensorShapeProto_Dim& from);
  void MergeFrom(const TensorShapeProto_Dim& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output)
      const PROTOBUF_FINAL {
    return InternalSerializeWithCachedSizesToArray(
        ::google::protobuf::io::CodedOutputStream::IsDefaultSerializationDeterministic(), output);
  }
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(TensorShapeProto_Dim* other);
  protected:
  explicit TensorShapeProto_Dim(::google::protobuf::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::google::protobuf::Arena* arena);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string name = 2;
  void clear_name();
  static const int kNameFieldNumber = 2;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);
  ::std::string* unsafe_arena_release_name();
  void unsafe_arena_set_allocated_name(
      ::std::string* name);

  // int64 size = 1;
  void clear_size();
  static const int kSizeFieldNumber = 1;
  ::google::protobuf::int64 size() const;
  void set_size(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:tensorflow.TensorShapeProto.Dim)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  friend class ::google::protobuf::Arena;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  ::google::protobuf::int64 size_;
  mutable int _cached_size_;
  friend struct  protobuf_tensorflow_2fcore_2fframework_2ftensor_5fshape_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class TensorShapeProto : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:tensorflow.TensorShapeProto) */ {
 public:
  TensorShapeProto();
  virtual ~TensorShapeProto();

  TensorShapeProto(const TensorShapeProto& from);

  inline TensorShapeProto& operator=(const TensorShapeProto& from) {
    CopyFrom(from);
    return *this;
  }

  inline ::google::protobuf::Arena* GetArena() const PROTOBUF_FINAL {
    return GetArenaNoVirtual();
  }
  inline void* GetMaybeArenaPointer() const PROTOBUF_FINAL {
    return MaybeArenaPtr();
  }
  static const ::google::protobuf::Descriptor* descriptor();
  static const TensorShapeProto& default_instance();

  static inline const TensorShapeProto* internal_default_instance() {
    return reinterpret_cast<const TensorShapeProto*>(
               &_TensorShapeProto_default_instance_);
  }

  void UnsafeArenaSwap(TensorShapeProto* other);
  void Swap(TensorShapeProto* other);

  // implements Message ----------------------------------------------

  inline TensorShapeProto* New() const PROTOBUF_FINAL { return New(NULL); }

  TensorShapeProto* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const TensorShapeProto& from);
  void MergeFrom(const TensorShapeProto& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output)
      const PROTOBUF_FINAL {
    return InternalSerializeWithCachedSizesToArray(
        ::google::protobuf::io::CodedOutputStream::IsDefaultSerializationDeterministic(), output);
  }
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(TensorShapeProto* other);
  protected:
  explicit TensorShapeProto(::google::protobuf::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::google::protobuf::Arena* arena);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  typedef TensorShapeProto_Dim Dim;

  // accessors -------------------------------------------------------

  // repeated .tensorflow.TensorShapeProto.Dim dim = 2;
  int dim_size() const;
  void clear_dim();
  static const int kDimFieldNumber = 2;
  const ::tensorflow::TensorShapeProto_Dim& dim(int index) const;
  ::tensorflow::TensorShapeProto_Dim* mutable_dim(int index);
  ::tensorflow::TensorShapeProto_Dim* add_dim();
  ::google::protobuf::RepeatedPtrField< ::tensorflow::TensorShapeProto_Dim >*
      mutable_dim();
  const ::google::protobuf::RepeatedPtrField< ::tensorflow::TensorShapeProto_Dim >&
      dim() const;

  // bool unknown_rank = 3;
  void clear_unknown_rank();
  static const int kUnknownRankFieldNumber = 3;
  bool unknown_rank() const;
  void set_unknown_rank(bool value);

  // @@protoc_insertion_point(class_scope:tensorflow.TensorShapeProto)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  friend class ::google::protobuf::Arena;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::google::protobuf::RepeatedPtrField< ::tensorflow::TensorShapeProto_Dim > dim_;
  bool unknown_rank_;
  mutable int _cached_size_;
  friend struct  protobuf_tensorflow_2fcore_2fframework_2ftensor_5fshape_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// TensorShapeProto_Dim

// int64 size = 1;
inline void TensorShapeProto_Dim::clear_size() {
  size_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 TensorShapeProto_Dim::size() const {
  // @@protoc_insertion_point(field_get:tensorflow.TensorShapeProto.Dim.size)
  return size_;
}
inline void TensorShapeProto_Dim::set_size(::google::protobuf::int64 value) {
  
  size_ = value;
  // @@protoc_insertion_point(field_set:tensorflow.TensorShapeProto.Dim.size)
}

// string name = 2;
inline void TensorShapeProto_Dim::clear_name() {
  name_.ClearToEmpty(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline const ::std::string& TensorShapeProto_Dim::name() const {
  // @@protoc_insertion_point(field_get:tensorflow.TensorShapeProto.Dim.name)
  return name_.Get();
}
inline void TensorShapeProto_Dim::set_name(const ::std::string& value) {
  
  name_.Set(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value, GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set:tensorflow.TensorShapeProto.Dim.name)
}
inline void TensorShapeProto_Dim::set_name(const char* value) {
  
  name_.Set(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set_char:tensorflow.TensorShapeProto.Dim.name)
}
inline void TensorShapeProto_Dim::set_name(const char* value,
    size_t size) {
  
  name_.Set(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set_pointer:tensorflow.TensorShapeProto.Dim.name)
}
inline ::std::string* TensorShapeProto_Dim::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:tensorflow.TensorShapeProto.Dim.name)
  return name_.Mutable(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline ::std::string* TensorShapeProto_Dim::release_name() {
  // @@protoc_insertion_point(field_release:tensorflow.TensorShapeProto.Dim.name)
  
  return name_.Release(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline ::std::string* TensorShapeProto_Dim::unsafe_arena_release_name() {
  // @@protoc_insertion_point(field_unsafe_arena_release:tensorflow.TensorShapeProto.Dim.name)
  GOOGLE_DCHECK(GetArenaNoVirtual() != NULL);
  
  return name_.UnsafeArenaRelease(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      GetArenaNoVirtual());
}
inline void TensorShapeProto_Dim::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    
  } else {
    
  }
  name_.SetAllocated(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name,
      GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set_allocated:tensorflow.TensorShapeProto.Dim.name)
}
inline void TensorShapeProto_Dim::unsafe_arena_set_allocated_name(
    ::std::string* name) {
  GOOGLE_DCHECK(GetArenaNoVirtual() != NULL);
  if (name != NULL) {
    
  } else {
    
  }
  name_.UnsafeArenaSetAllocated(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      name, GetArenaNoVirtual());
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:tensorflow.TensorShapeProto.Dim.name)
}

// -------------------------------------------------------------------

// TensorShapeProto

// repeated .tensorflow.TensorShapeProto.Dim dim = 2;
inline int TensorShapeProto::dim_size() const {
  return dim_.size();
}
inline void TensorShapeProto::clear_dim() {
  dim_.Clear();
}
inline const ::tensorflow::TensorShapeProto_Dim& TensorShapeProto::dim(int index) const {
  // @@protoc_insertion_point(field_get:tensorflow.TensorShapeProto.dim)
  return dim_.Get(index);
}
inline ::tensorflow::TensorShapeProto_Dim* TensorShapeProto::mutable_dim(int index) {
  // @@protoc_insertion_point(field_mutable:tensorflow.TensorShapeProto.dim)
  return dim_.Mutable(index);
}
inline ::tensorflow::TensorShapeProto_Dim* TensorShapeProto::add_dim() {
  // @@protoc_insertion_point(field_add:tensorflow.TensorShapeProto.dim)
  return dim_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::tensorflow::TensorShapeProto_Dim >*
TensorShapeProto::mutable_dim() {
  // @@protoc_insertion_point(field_mutable_list:tensorflow.TensorShapeProto.dim)
  return &dim_;
}
inline const ::google::protobuf::RepeatedPtrField< ::tensorflow::TensorShapeProto_Dim >&
TensorShapeProto::dim() const {
  // @@protoc_insertion_point(field_list:tensorflow.TensorShapeProto.dim)
  return dim_;
}

// bool unknown_rank = 3;
inline void TensorShapeProto::clear_unknown_rank() {
  unknown_rank_ = false;
}
inline bool TensorShapeProto::unknown_rank() const {
  // @@protoc_insertion_point(field_get:tensorflow.TensorShapeProto.unknown_rank)
  return unknown_rank_;
}
inline void TensorShapeProto::set_unknown_rank(bool value) {
  
  unknown_rank_ = value;
  // @@protoc_insertion_point(field_set:tensorflow.TensorShapeProto.unknown_rank)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


}  // namespace tensorflow

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_tensorflow_2fcore_2fframework_2ftensor_5fshape_2eproto__INCLUDED
