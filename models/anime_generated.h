// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_ANIME_H_
#define FLATBUFFERS_GENERATED_ANIME_H_

#include "flatbuffers/flatbuffers.h"

struct Anime;
struct AnimeBuilder;

enum Origin {
  Origin_Ranobe = 1,
  Origin_Manga = 2,
  Origin_Manhva = 3,
  Origin_Manhua = 4,
  Origin_Game = 5,
  Origin_Other = 6,
  Origin_MIN = Origin_Ranobe,
  Origin_MAX = Origin_Other
};

inline const Origin (&EnumValuesOrigin())[6] {
  static const Origin values[] = {
    Origin_Ranobe,
    Origin_Manga,
    Origin_Manhva,
    Origin_Manhua,
    Origin_Game,
    Origin_Other
  };
  return values;
}

inline const char * const *EnumNamesOrigin() {
  static const char * const names[7] = {
    "Ranobe",
    "Manga",
    "Manhva",
    "Manhua",
    "Game",
    "Other",
    nullptr
  };
  return names;
}

inline const char *EnumNameOrigin(Origin e) {
  if (flatbuffers::IsOutRange(e, Origin_Ranobe, Origin_Other)) return "";
  const size_t index = static_cast<size_t>(e) - static_cast<size_t>(Origin_Ranobe);
  return EnumNamesOrigin()[index];
}

struct Anime FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef AnimeBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_TITLE = 4,
    VT_STUDIO = 6,
    VT_YEAR = 8,
    VT_ORIGIN = 10
  };
  const flatbuffers::String *title() const {
    return GetPointer<const flatbuffers::String *>(VT_TITLE);
  }
  const flatbuffers::String *studio() const {
    return GetPointer<const flatbuffers::String *>(VT_STUDIO);
  }
  int16_t year() const {
    return GetField<int16_t>(VT_YEAR, 0);
  }
  Origin origin() const {
    return static_cast<Origin>(GetField<int16_t>(VT_ORIGIN, 6));
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffsetRequired(verifier, VT_TITLE) &&
           verifier.VerifyString(title()) &&
           VerifyOffset(verifier, VT_STUDIO) &&
           verifier.VerifyString(studio()) &&
           VerifyField<int16_t>(verifier, VT_YEAR) &&
           VerifyField<int16_t>(verifier, VT_ORIGIN) &&
           verifier.EndTable();
  }
};

struct AnimeBuilder {
  typedef Anime Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_title(flatbuffers::Offset<flatbuffers::String> title) {
    fbb_.AddOffset(Anime::VT_TITLE, title);
  }
  void add_studio(flatbuffers::Offset<flatbuffers::String> studio) {
    fbb_.AddOffset(Anime::VT_STUDIO, studio);
  }
  void add_year(int16_t year) {
    fbb_.AddElement<int16_t>(Anime::VT_YEAR, year, 0);
  }
  void add_origin(Origin origin) {
    fbb_.AddElement<int16_t>(Anime::VT_ORIGIN, static_cast<int16_t>(origin), 6);
  }
  explicit AnimeBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  AnimeBuilder &operator=(const AnimeBuilder &);
  flatbuffers::Offset<Anime> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Anime>(end);
    fbb_.Required(o, Anime::VT_TITLE);
    return o;
  }
};

inline flatbuffers::Offset<Anime> CreateAnime(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> title = 0,
    flatbuffers::Offset<flatbuffers::String> studio = 0,
    int16_t year = 0,
    Origin origin = Origin_Other) {
  AnimeBuilder builder_(_fbb);
  builder_.add_studio(studio);
  builder_.add_title(title);
  builder_.add_origin(origin);
  builder_.add_year(year);
  return builder_.Finish();
}

inline flatbuffers::Offset<Anime> CreateAnimeDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *title = nullptr,
    const char *studio = nullptr,
    int16_t year = 0,
    Origin origin = Origin_Other) {
  auto title__ = title ? _fbb.CreateString(title) : 0;
  auto studio__ = studio ? _fbb.CreateString(studio) : 0;
  return CreateAnime(
      _fbb,
      title__,
      studio__,
      year,
      origin);
}

inline const Anime *GetAnime(const void *buf) {
  return flatbuffers::GetRoot<Anime>(buf);
}

inline const Anime *GetSizePrefixedAnime(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<Anime>(buf);
}

inline bool VerifyAnimeBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<Anime>(nullptr);
}

inline bool VerifySizePrefixedAnimeBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<Anime>(nullptr);
}

inline void FinishAnimeBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Anime> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedAnimeBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Anime> root) {
  fbb.FinishSizePrefixed(root);
}

#endif  // FLATBUFFERS_GENERATED_ANIME_H_
