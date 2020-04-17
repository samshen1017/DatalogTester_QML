// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Sensor.proto

#ifndef PROTOBUF_Sensor_2eproto__INCLUDED
#define PROTOBUF_Sensor_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3003000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3003000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
namespace com {
namespace shanghai3h {
namespace protobuf {
class PressureSensorOption;
class PressureSensorOptionDefaultTypeInternal;
extern PressureSensorOptionDefaultTypeInternal _PressureSensorOption_default_instance_;
class SensorData;
class SensorDataDefaultTypeInternal;
extern SensorDataDefaultTypeInternal _SensorData_default_instance_;
class SensorInfo;
class SensorInfoDefaultTypeInternal;
extern SensorInfoDefaultTypeInternal _SensorInfo_default_instance_;
class SensorInfoList;
class SensorInfoListDefaultTypeInternal;
extern SensorInfoListDefaultTypeInternal _SensorInfoList_default_instance_;
}  // namespace protobuf
}  // namespace shanghai3h
}  // namespace com

namespace com {
namespace shanghai3h {
namespace protobuf {

namespace protobuf_Sensor_2eproto {
// Internal implementation detail -- do not call these.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[];
  static const ::google::protobuf::uint32 offsets[];
  static void InitDefaultsImpl();
  static void Shutdown();
};
void AddDescriptors();
void InitDefaults();
}  // namespace protobuf_Sensor_2eproto

enum PressureUnit {
  Pa = 0,
  KPa = 1,
  MPa = 2,
  bar = 3,
  psi = 4,
  PressureUnit_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  PressureUnit_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool PressureUnit_IsValid(int value);
const PressureUnit PressureUnit_MIN = Pa;
const PressureUnit PressureUnit_MAX = psi;
const int PressureUnit_ARRAYSIZE = PressureUnit_MAX + 1;

const ::google::protobuf::EnumDescriptor* PressureUnit_descriptor();
inline const ::std::string& PressureUnit_Name(PressureUnit value) {
  return ::google::protobuf::internal::NameOfEnum(
    PressureUnit_descriptor(), value);
}
inline bool PressureUnit_Parse(
    const ::std::string& name, PressureUnit* value) {
  return ::google::protobuf::internal::ParseNamedEnum<PressureUnit>(
    PressureUnit_descriptor(), name, value);
}
enum SensorType {
  Sensor_ZSC31014 = 0,
  SensorType_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  SensorType_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool SensorType_IsValid(int value);
const SensorType SensorType_MIN = Sensor_ZSC31014;
const SensorType SensorType_MAX = Sensor_ZSC31014;
const int SensorType_ARRAYSIZE = SensorType_MAX + 1;

const ::google::protobuf::EnumDescriptor* SensorType_descriptor();
inline const ::std::string& SensorType_Name(SensorType value) {
  return ::google::protobuf::internal::NameOfEnum(
    SensorType_descriptor(), value);
}
inline bool SensorType_Parse(
    const ::std::string& name, SensorType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<SensorType>(
    SensorType_descriptor(), name, value);
}
enum SensorDriverType {
  Sensor_I2C0 = 0,
  Sensor_I2C1 = 1,
  Sersor_I2C3 = 2,
  Sensor_SPI0 = 3,
  Sensor_SPI1 = 4,
  Sensor_USB0 = 5,
  Sensor_USB1 = 6,
  Sensor_Serial0 = 7,
  Sensor_Serial1 = 8,
  SensorDriverType_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  SensorDriverType_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool SensorDriverType_IsValid(int value);
const SensorDriverType SensorDriverType_MIN = Sensor_I2C0;
const SensorDriverType SensorDriverType_MAX = Sensor_Serial1;
const int SensorDriverType_ARRAYSIZE = SensorDriverType_MAX + 1;

const ::google::protobuf::EnumDescriptor* SensorDriverType_descriptor();
inline const ::std::string& SensorDriverType_Name(SensorDriverType value) {
  return ::google::protobuf::internal::NameOfEnum(
    SensorDriverType_descriptor(), value);
}
inline bool SensorDriverType_Parse(
    const ::std::string& name, SensorDriverType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<SensorDriverType>(
    SensorDriverType_descriptor(), name, value);
}
// ===================================================================

class SensorInfo : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:com.shanghai3h.protobuf.SensorInfo) */ {
 public:
  SensorInfo();
  virtual ~SensorInfo();

  SensorInfo(const SensorInfo& from);

  inline SensorInfo& operator=(const SensorInfo& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const SensorInfo& default_instance();

  enum OptionCase {
    kPressOpt = 6,
    OPTION_NOT_SET = 0,
  };

  static inline const SensorInfo* internal_default_instance() {
    return reinterpret_cast<const SensorInfo*>(
               &_SensorInfo_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(SensorInfo* other);

  // implements Message ----------------------------------------------

  inline SensorInfo* New() const PROTOBUF_FINAL { return New(NULL); }

  SensorInfo* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const SensorInfo& from);
  void MergeFrom(const SensorInfo& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(SensorInfo* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string sensorName = 4;
  void clear_sensorname();
  static const int kSensorNameFieldNumber = 4;
  const ::std::string& sensorname() const;
  void set_sensorname(const ::std::string& value);
  #if LANG_CXX11
  void set_sensorname(::std::string&& value);
  #endif
  void set_sensorname(const char* value);
  void set_sensorname(const char* value, size_t size);
  ::std::string* mutable_sensorname();
  ::std::string* release_sensorname();
  void set_allocated_sensorname(::std::string* sensorname);

  // string partNumber = 5;
  void clear_partnumber();
  static const int kPartNumberFieldNumber = 5;
  const ::std::string& partnumber() const;
  void set_partnumber(const ::std::string& value);
  #if LANG_CXX11
  void set_partnumber(::std::string&& value);
  #endif
  void set_partnumber(const char* value);
  void set_partnumber(const char* value, size_t size);
  ::std::string* mutable_partnumber();
  ::std::string* release_partnumber();
  void set_allocated_partnumber(::std::string* partnumber);

  // uint32 id = 1;
  void clear_id();
  static const int kIdFieldNumber = 1;
  ::google::protobuf::uint32 id() const;
  void set_id(::google::protobuf::uint32 value);

  // .com.shanghai3h.protobuf.SensorType type = 2;
  void clear_type();
  static const int kTypeFieldNumber = 2;
  ::com::shanghai3h::protobuf::SensorType type() const;
  void set_type(::com::shanghai3h::protobuf::SensorType value);

  // .com.shanghai3h.protobuf.SensorDriverType drv_type = 3;
  void clear_drv_type();
  static const int kDrvTypeFieldNumber = 3;
  ::com::shanghai3h::protobuf::SensorDriverType drv_type() const;
  void set_drv_type(::com::shanghai3h::protobuf::SensorDriverType value);

  // uint32 interval = 7;
  void clear_interval();
  static const int kIntervalFieldNumber = 7;
  ::google::protobuf::uint32 interval() const;
  void set_interval(::google::protobuf::uint32 value);

  // uint32 rawCount = 8;
  void clear_rawcount();
  static const int kRawCountFieldNumber = 8;
  ::google::protobuf::uint32 rawcount() const;
  void set_rawcount(::google::protobuf::uint32 value);

  // .com.shanghai3h.protobuf.PressureSensorOption press_opt = 6;
  bool has_press_opt() const;
  void clear_press_opt();
  static const int kPressOptFieldNumber = 6;
  const ::com::shanghai3h::protobuf::PressureSensorOption& press_opt() const;
  ::com::shanghai3h::protobuf::PressureSensorOption* mutable_press_opt();
  ::com::shanghai3h::protobuf::PressureSensorOption* release_press_opt();
  void set_allocated_press_opt(::com::shanghai3h::protobuf::PressureSensorOption* press_opt);

  OptionCase option_case() const;
  // @@protoc_insertion_point(class_scope:com.shanghai3h.protobuf.SensorInfo)
 private:
  void set_has_press_opt();

  inline bool has_option() const;
  void clear_option();
  inline void clear_has_option();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr sensorname_;
  ::google::protobuf::internal::ArenaStringPtr partnumber_;
  ::google::protobuf::uint32 id_;
  int type_;
  int drv_type_;
  ::google::protobuf::uint32 interval_;
  ::google::protobuf::uint32 rawcount_;
  union OptionUnion {
    OptionUnion() {}
    ::com::shanghai3h::protobuf::PressureSensorOption* press_opt_;
  } option_;
  mutable int _cached_size_;
  ::google::protobuf::uint32 _oneof_case_[1];

  friend struct protobuf_Sensor_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class PressureSensorOption : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:com.shanghai3h.protobuf.PressureSensorOption) */ {
 public:
  PressureSensorOption();
  virtual ~PressureSensorOption();

  PressureSensorOption(const PressureSensorOption& from);

  inline PressureSensorOption& operator=(const PressureSensorOption& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const PressureSensorOption& default_instance();

  static inline const PressureSensorOption* internal_default_instance() {
    return reinterpret_cast<const PressureSensorOption*>(
               &_PressureSensorOption_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(PressureSensorOption* other);

  // implements Message ----------------------------------------------

  inline PressureSensorOption* New() const PROTOBUF_FINAL { return New(NULL); }

  PressureSensorOption* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const PressureSensorOption& from);
  void MergeFrom(const PressureSensorOption& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(PressureSensorOption* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // int32 coefficient = 1;
  void clear_coefficient();
  static const int kCoefficientFieldNumber = 1;
  ::google::protobuf::int32 coefficient() const;
  void set_coefficient(::google::protobuf::int32 value);

  // int32 offset = 2;
  void clear_offset();
  static const int kOffsetFieldNumber = 2;
  ::google::protobuf::int32 offset() const;
  void set_offset(::google::protobuf::int32 value);

  // int32 rangeMax = 3;
  void clear_rangemax();
  static const int kRangeMaxFieldNumber = 3;
  ::google::protobuf::int32 rangemax() const;
  void set_rangemax(::google::protobuf::int32 value);

  // int32 rangeMin = 4;
  void clear_rangemin();
  static const int kRangeMinFieldNumber = 4;
  ::google::protobuf::int32 rangemin() const;
  void set_rangemin(::google::protobuf::int32 value);

  // .com.shanghai3h.protobuf.PressureUnit unit = 8;
  void clear_unit();
  static const int kUnitFieldNumber = 8;
  ::com::shanghai3h::protobuf::PressureUnit unit() const;
  void set_unit(::com::shanghai3h::protobuf::PressureUnit value);

  // @@protoc_insertion_point(class_scope:com.shanghai3h.protobuf.PressureSensorOption)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::int32 coefficient_;
  ::google::protobuf::int32 offset_;
  ::google::protobuf::int32 rangemax_;
  ::google::protobuf::int32 rangemin_;
  int unit_;
  mutable int _cached_size_;
  friend struct protobuf_Sensor_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class SensorData : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:com.shanghai3h.protobuf.SensorData) */ {
 public:
  SensorData();
  virtual ~SensorData();

  SensorData(const SensorData& from);

  inline SensorData& operator=(const SensorData& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const SensorData& default_instance();

  static inline const SensorData* internal_default_instance() {
    return reinterpret_cast<const SensorData*>(
               &_SensorData_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    2;

  void Swap(SensorData* other);

  // implements Message ----------------------------------------------

  inline SensorData* New() const PROTOBUF_FINAL { return New(NULL); }

  SensorData* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const SensorData& from);
  void MergeFrom(const SensorData& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(SensorData* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated int32 value = 2;
  int value_size() const;
  void clear_value();
  static const int kValueFieldNumber = 2;
  ::google::protobuf::int32 value(int index) const;
  void set_value(int index, ::google::protobuf::int32 value);
  void add_value(::google::protobuf::int32 value);
  const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
      value() const;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
      mutable_value();

  // int32 size = 1;
  void clear_size();
  static const int kSizeFieldNumber = 1;
  ::google::protobuf::int32 size() const;
  void set_size(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:com.shanghai3h.protobuf.SensorData)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 > value_;
  mutable int _value_cached_byte_size_;
  ::google::protobuf::int32 size_;
  mutable int _cached_size_;
  friend struct protobuf_Sensor_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class SensorInfoList : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:com.shanghai3h.protobuf.SensorInfoList) */ {
 public:
  SensorInfoList();
  virtual ~SensorInfoList();

  SensorInfoList(const SensorInfoList& from);

  inline SensorInfoList& operator=(const SensorInfoList& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const SensorInfoList& default_instance();

  static inline const SensorInfoList* internal_default_instance() {
    return reinterpret_cast<const SensorInfoList*>(
               &_SensorInfoList_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    3;

  void Swap(SensorInfoList* other);

  // implements Message ----------------------------------------------

  inline SensorInfoList* New() const PROTOBUF_FINAL { return New(NULL); }

  SensorInfoList* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const SensorInfoList& from);
  void MergeFrom(const SensorInfoList& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(SensorInfoList* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .com.shanghai3h.protobuf.SensorInfo list = 1;
  int list_size() const;
  void clear_list();
  static const int kListFieldNumber = 1;
  const ::com::shanghai3h::protobuf::SensorInfo& list(int index) const;
  ::com::shanghai3h::protobuf::SensorInfo* mutable_list(int index);
  ::com::shanghai3h::protobuf::SensorInfo* add_list();
  ::google::protobuf::RepeatedPtrField< ::com::shanghai3h::protobuf::SensorInfo >*
      mutable_list();
  const ::google::protobuf::RepeatedPtrField< ::com::shanghai3h::protobuf::SensorInfo >&
      list() const;

  // @@protoc_insertion_point(class_scope:com.shanghai3h.protobuf.SensorInfoList)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::com::shanghai3h::protobuf::SensorInfo > list_;
  mutable int _cached_size_;
  friend struct protobuf_Sensor_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// SensorInfo

// uint32 id = 1;
inline void SensorInfo::clear_id() {
  id_ = 0u;
}
inline ::google::protobuf::uint32 SensorInfo::id() const {
  // @@protoc_insertion_point(field_get:com.shanghai3h.protobuf.SensorInfo.id)
  return id_;
}
inline void SensorInfo::set_id(::google::protobuf::uint32 value) {
  
  id_ = value;
  // @@protoc_insertion_point(field_set:com.shanghai3h.protobuf.SensorInfo.id)
}

// .com.shanghai3h.protobuf.SensorType type = 2;
inline void SensorInfo::clear_type() {
  type_ = 0;
}
inline ::com::shanghai3h::protobuf::SensorType SensorInfo::type() const {
  // @@protoc_insertion_point(field_get:com.shanghai3h.protobuf.SensorInfo.type)
  return static_cast< ::com::shanghai3h::protobuf::SensorType >(type_);
}
inline void SensorInfo::set_type(::com::shanghai3h::protobuf::SensorType value) {
  
  type_ = value;
  // @@protoc_insertion_point(field_set:com.shanghai3h.protobuf.SensorInfo.type)
}

// .com.shanghai3h.protobuf.SensorDriverType drv_type = 3;
inline void SensorInfo::clear_drv_type() {
  drv_type_ = 0;
}
inline ::com::shanghai3h::protobuf::SensorDriverType SensorInfo::drv_type() const {
  // @@protoc_insertion_point(field_get:com.shanghai3h.protobuf.SensorInfo.drv_type)
  return static_cast< ::com::shanghai3h::protobuf::SensorDriverType >(drv_type_);
}
inline void SensorInfo::set_drv_type(::com::shanghai3h::protobuf::SensorDriverType value) {
  
  drv_type_ = value;
  // @@protoc_insertion_point(field_set:com.shanghai3h.protobuf.SensorInfo.drv_type)
}

// string sensorName = 4;
inline void SensorInfo::clear_sensorname() {
  sensorname_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& SensorInfo::sensorname() const {
  // @@protoc_insertion_point(field_get:com.shanghai3h.protobuf.SensorInfo.sensorName)
  return sensorname_.GetNoArena();
}
inline void SensorInfo::set_sensorname(const ::std::string& value) {
  
  sensorname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:com.shanghai3h.protobuf.SensorInfo.sensorName)
}
#if LANG_CXX11
inline void SensorInfo::set_sensorname(::std::string&& value) {
  
  sensorname_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:com.shanghai3h.protobuf.SensorInfo.sensorName)
}
#endif
inline void SensorInfo::set_sensorname(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  sensorname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:com.shanghai3h.protobuf.SensorInfo.sensorName)
}
inline void SensorInfo::set_sensorname(const char* value, size_t size) {
  
  sensorname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:com.shanghai3h.protobuf.SensorInfo.sensorName)
}
inline ::std::string* SensorInfo::mutable_sensorname() {
  
  // @@protoc_insertion_point(field_mutable:com.shanghai3h.protobuf.SensorInfo.sensorName)
  return sensorname_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* SensorInfo::release_sensorname() {
  // @@protoc_insertion_point(field_release:com.shanghai3h.protobuf.SensorInfo.sensorName)
  
  return sensorname_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SensorInfo::set_allocated_sensorname(::std::string* sensorname) {
  if (sensorname != NULL) {
    
  } else {
    
  }
  sensorname_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), sensorname);
  // @@protoc_insertion_point(field_set_allocated:com.shanghai3h.protobuf.SensorInfo.sensorName)
}

// string partNumber = 5;
inline void SensorInfo::clear_partnumber() {
  partnumber_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& SensorInfo::partnumber() const {
  // @@protoc_insertion_point(field_get:com.shanghai3h.protobuf.SensorInfo.partNumber)
  return partnumber_.GetNoArena();
}
inline void SensorInfo::set_partnumber(const ::std::string& value) {
  
  partnumber_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:com.shanghai3h.protobuf.SensorInfo.partNumber)
}
#if LANG_CXX11
inline void SensorInfo::set_partnumber(::std::string&& value) {
  
  partnumber_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:com.shanghai3h.protobuf.SensorInfo.partNumber)
}
#endif
inline void SensorInfo::set_partnumber(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  partnumber_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:com.shanghai3h.protobuf.SensorInfo.partNumber)
}
inline void SensorInfo::set_partnumber(const char* value, size_t size) {
  
  partnumber_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:com.shanghai3h.protobuf.SensorInfo.partNumber)
}
inline ::std::string* SensorInfo::mutable_partnumber() {
  
  // @@protoc_insertion_point(field_mutable:com.shanghai3h.protobuf.SensorInfo.partNumber)
  return partnumber_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* SensorInfo::release_partnumber() {
  // @@protoc_insertion_point(field_release:com.shanghai3h.protobuf.SensorInfo.partNumber)
  
  return partnumber_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SensorInfo::set_allocated_partnumber(::std::string* partnumber) {
  if (partnumber != NULL) {
    
  } else {
    
  }
  partnumber_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), partnumber);
  // @@protoc_insertion_point(field_set_allocated:com.shanghai3h.protobuf.SensorInfo.partNumber)
}

// uint32 interval = 7;
inline void SensorInfo::clear_interval() {
  interval_ = 0u;
}
inline ::google::protobuf::uint32 SensorInfo::interval() const {
  // @@protoc_insertion_point(field_get:com.shanghai3h.protobuf.SensorInfo.interval)
  return interval_;
}
inline void SensorInfo::set_interval(::google::protobuf::uint32 value) {
  
  interval_ = value;
  // @@protoc_insertion_point(field_set:com.shanghai3h.protobuf.SensorInfo.interval)
}

// uint32 rawCount = 8;
inline void SensorInfo::clear_rawcount() {
  rawcount_ = 0u;
}
inline ::google::protobuf::uint32 SensorInfo::rawcount() const {
  // @@protoc_insertion_point(field_get:com.shanghai3h.protobuf.SensorInfo.rawCount)
  return rawcount_;
}
inline void SensorInfo::set_rawcount(::google::protobuf::uint32 value) {
  
  rawcount_ = value;
  // @@protoc_insertion_point(field_set:com.shanghai3h.protobuf.SensorInfo.rawCount)
}

// .com.shanghai3h.protobuf.PressureSensorOption press_opt = 6;
inline bool SensorInfo::has_press_opt() const {
  return option_case() == kPressOpt;
}
inline void SensorInfo::set_has_press_opt() {
  _oneof_case_[0] = kPressOpt;
}
inline void SensorInfo::clear_press_opt() {
  if (has_press_opt()) {
    delete option_.press_opt_;
    clear_has_option();
  }
}
inline  const ::com::shanghai3h::protobuf::PressureSensorOption& SensorInfo::press_opt() const {
  // @@protoc_insertion_point(field_get:com.shanghai3h.protobuf.SensorInfo.press_opt)
  return has_press_opt()
      ? *option_.press_opt_
      : ::com::shanghai3h::protobuf::PressureSensorOption::default_instance();
}
inline ::com::shanghai3h::protobuf::PressureSensorOption* SensorInfo::mutable_press_opt() {
  if (!has_press_opt()) {
    clear_option();
    set_has_press_opt();
    option_.press_opt_ = new ::com::shanghai3h::protobuf::PressureSensorOption;
  }
  // @@protoc_insertion_point(field_mutable:com.shanghai3h.protobuf.SensorInfo.press_opt)
  return option_.press_opt_;
}
inline ::com::shanghai3h::protobuf::PressureSensorOption* SensorInfo::release_press_opt() {
  // @@protoc_insertion_point(field_release:com.shanghai3h.protobuf.SensorInfo.press_opt)
  if (has_press_opt()) {
    clear_has_option();
    ::com::shanghai3h::protobuf::PressureSensorOption* temp = option_.press_opt_;
    option_.press_opt_ = NULL;
    return temp;
  } else {
    return NULL;
  }
}
inline void SensorInfo::set_allocated_press_opt(::com::shanghai3h::protobuf::PressureSensorOption* press_opt) {
  clear_option();
  if (press_opt) {
    set_has_press_opt();
    option_.press_opt_ = press_opt;
  }
  // @@protoc_insertion_point(field_set_allocated:com.shanghai3h.protobuf.SensorInfo.press_opt)
}

inline bool SensorInfo::has_option() const {
  return option_case() != OPTION_NOT_SET;
}
inline void SensorInfo::clear_has_option() {
  _oneof_case_[0] = OPTION_NOT_SET;
}
inline SensorInfo::OptionCase SensorInfo::option_case() const {
  return SensorInfo::OptionCase(_oneof_case_[0]);
}
// -------------------------------------------------------------------

// PressureSensorOption

// int32 coefficient = 1;
inline void PressureSensorOption::clear_coefficient() {
  coefficient_ = 0;
}
inline ::google::protobuf::int32 PressureSensorOption::coefficient() const {
  // @@protoc_insertion_point(field_get:com.shanghai3h.protobuf.PressureSensorOption.coefficient)
  return coefficient_;
}
inline void PressureSensorOption::set_coefficient(::google::protobuf::int32 value) {
  
  coefficient_ = value;
  // @@protoc_insertion_point(field_set:com.shanghai3h.protobuf.PressureSensorOption.coefficient)
}

// int32 offset = 2;
inline void PressureSensorOption::clear_offset() {
  offset_ = 0;
}
inline ::google::protobuf::int32 PressureSensorOption::offset() const {
  // @@protoc_insertion_point(field_get:com.shanghai3h.protobuf.PressureSensorOption.offset)
  return offset_;
}
inline void PressureSensorOption::set_offset(::google::protobuf::int32 value) {
  
  offset_ = value;
  // @@protoc_insertion_point(field_set:com.shanghai3h.protobuf.PressureSensorOption.offset)
}

// int32 rangeMax = 3;
inline void PressureSensorOption::clear_rangemax() {
  rangemax_ = 0;
}
inline ::google::protobuf::int32 PressureSensorOption::rangemax() const {
  // @@protoc_insertion_point(field_get:com.shanghai3h.protobuf.PressureSensorOption.rangeMax)
  return rangemax_;
}
inline void PressureSensorOption::set_rangemax(::google::protobuf::int32 value) {
  
  rangemax_ = value;
  // @@protoc_insertion_point(field_set:com.shanghai3h.protobuf.PressureSensorOption.rangeMax)
}

// int32 rangeMin = 4;
inline void PressureSensorOption::clear_rangemin() {
  rangemin_ = 0;
}
inline ::google::protobuf::int32 PressureSensorOption::rangemin() const {
  // @@protoc_insertion_point(field_get:com.shanghai3h.protobuf.PressureSensorOption.rangeMin)
  return rangemin_;
}
inline void PressureSensorOption::set_rangemin(::google::protobuf::int32 value) {
  
  rangemin_ = value;
  // @@protoc_insertion_point(field_set:com.shanghai3h.protobuf.PressureSensorOption.rangeMin)
}

// .com.shanghai3h.protobuf.PressureUnit unit = 8;
inline void PressureSensorOption::clear_unit() {
  unit_ = 0;
}
inline ::com::shanghai3h::protobuf::PressureUnit PressureSensorOption::unit() const {
  // @@protoc_insertion_point(field_get:com.shanghai3h.protobuf.PressureSensorOption.unit)
  return static_cast< ::com::shanghai3h::protobuf::PressureUnit >(unit_);
}
inline void PressureSensorOption::set_unit(::com::shanghai3h::protobuf::PressureUnit value) {
  
  unit_ = value;
  // @@protoc_insertion_point(field_set:com.shanghai3h.protobuf.PressureSensorOption.unit)
}

// -------------------------------------------------------------------

// SensorData

// int32 size = 1;
inline void SensorData::clear_size() {
  size_ = 0;
}
inline ::google::protobuf::int32 SensorData::size() const {
  // @@protoc_insertion_point(field_get:com.shanghai3h.protobuf.SensorData.size)
  return size_;
}
inline void SensorData::set_size(::google::protobuf::int32 value) {
  
  size_ = value;
  // @@protoc_insertion_point(field_set:com.shanghai3h.protobuf.SensorData.size)
}

// repeated int32 value = 2;
inline int SensorData::value_size() const {
  return value_.size();
}
inline void SensorData::clear_value() {
  value_.Clear();
}
inline ::google::protobuf::int32 SensorData::value(int index) const {
  // @@protoc_insertion_point(field_get:com.shanghai3h.protobuf.SensorData.value)
  return value_.Get(index);
}
inline void SensorData::set_value(int index, ::google::protobuf::int32 value) {
  value_.Set(index, value);
  // @@protoc_insertion_point(field_set:com.shanghai3h.protobuf.SensorData.value)
}
inline void SensorData::add_value(::google::protobuf::int32 value) {
  value_.Add(value);
  // @@protoc_insertion_point(field_add:com.shanghai3h.protobuf.SensorData.value)
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
SensorData::value() const {
  // @@protoc_insertion_point(field_list:com.shanghai3h.protobuf.SensorData.value)
  return value_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
SensorData::mutable_value() {
  // @@protoc_insertion_point(field_mutable_list:com.shanghai3h.protobuf.SensorData.value)
  return &value_;
}

// -------------------------------------------------------------------

// SensorInfoList

// repeated .com.shanghai3h.protobuf.SensorInfo list = 1;
inline int SensorInfoList::list_size() const {
  return list_.size();
}
inline void SensorInfoList::clear_list() {
  list_.Clear();
}
inline const ::com::shanghai3h::protobuf::SensorInfo& SensorInfoList::list(int index) const {
  // @@protoc_insertion_point(field_get:com.shanghai3h.protobuf.SensorInfoList.list)
  return list_.Get(index);
}
inline ::com::shanghai3h::protobuf::SensorInfo* SensorInfoList::mutable_list(int index) {
  // @@protoc_insertion_point(field_mutable:com.shanghai3h.protobuf.SensorInfoList.list)
  return list_.Mutable(index);
}
inline ::com::shanghai3h::protobuf::SensorInfo* SensorInfoList::add_list() {
  // @@protoc_insertion_point(field_add:com.shanghai3h.protobuf.SensorInfoList.list)
  return list_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::com::shanghai3h::protobuf::SensorInfo >*
SensorInfoList::mutable_list() {
  // @@protoc_insertion_point(field_mutable_list:com.shanghai3h.protobuf.SensorInfoList.list)
  return &list_;
}
inline const ::google::protobuf::RepeatedPtrField< ::com::shanghai3h::protobuf::SensorInfo >&
SensorInfoList::list() const {
  // @@protoc_insertion_point(field_list:com.shanghai3h.protobuf.SensorInfoList.list)
  return list_;
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


}  // namespace protobuf
}  // namespace shanghai3h
}  // namespace com

#ifndef SWIG
namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::com::shanghai3h::protobuf::PressureUnit> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::com::shanghai3h::protobuf::PressureUnit>() {
  return ::com::shanghai3h::protobuf::PressureUnit_descriptor();
}
template <> struct is_proto_enum< ::com::shanghai3h::protobuf::SensorType> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::com::shanghai3h::protobuf::SensorType>() {
  return ::com::shanghai3h::protobuf::SensorType_descriptor();
}
template <> struct is_proto_enum< ::com::shanghai3h::protobuf::SensorDriverType> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::com::shanghai3h::protobuf::SensorDriverType>() {
  return ::com::shanghai3h::protobuf::SensorDriverType_descriptor();
}

}  // namespace protobuf
}  // namespace google
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_Sensor_2eproto__INCLUDED
