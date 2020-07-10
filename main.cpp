#include <iostream>
#include <fstream>
#include "models/anime_generated.h"

using std::cin, std::cout;

void RunTest1() {
    flatbuffers::FlatBufferBuilder builder;

    const auto TITLE = "Anime #1";
    const auto STUDIO = "Ghibli";

    auto title = builder.CreateString(TITLE);
    auto studio = builder.CreateString(STUDIO);

    auto bufferedAnime = CreateAnime(builder, title, studio, 2020, Origin_Manga);
    builder.Finish(bufferedAnime);

    auto anime = GetAnime(builder.GetBufferPointer());
    assert(anime->title()->str() == TITLE);
    assert(anime->studio()->str() == STUDIO);
    assert(anime->year() == 2020);
}

void RunTest2() {
    flatbuffers::FlatBufferBuilder builder;

    const auto STUDIO = "Perriot";
    const auto TITLE = "Anime #2";

    auto studio = builder.CreateString(STUDIO);
    auto title = builder.CreateString(TITLE);

    auto bufferedAnime = CreateAnime(builder, title, studio, 2020);
    builder.Finish(bufferedAnime);

    // Saving buffered data
    std::ofstream outfile;
    outfile.open("anime.data", std::ios::binary | std::ios::out);
    outfile.write(reinterpret_cast<const char*>(builder.GetBufferPointer()), builder.GetSize());
    outfile.close();

    // Loading data
    std::ifstream infile;
    infile.open("anime.data", std::ios::binary | std::ios::in);
    infile.seekg(0,std::ios::end);
    int length = infile.tellg();
    infile.seekg(0,std::ios::beg);
    char *data = new char[length];
    infile.read(data, length);
    infile.close();

    cout << length << std::endl;
    auto *ptr = reinterpret_cast<uint8_t*>(data);
    auto verifier = flatbuffers::Verifier(ptr, length);

    // Checking if the loaded data is correct
    bool ok = VerifyAnimeBuffer(verifier);
    cout << "Valid buffer: " << std::boolalpha << ok << std::endl;

    auto anime = GetAnime(data);
    assert(anime->title()->str() == TITLE);
    assert(anime->studio()->str() == STUDIO);
    assert(anime->year() == 2020);
}

int main() {
    RunTest1();
    RunTest2();
}
