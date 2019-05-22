#include "parser.h"

std::vector<std::string> parser::getPlaylist(std::string filePath){

  std::vector<std::string> playlist;
  std::ifstream input(filePath);

  std::string line;
  while (input >> line)
    {
      playlist.push_back(line);
    }

  return playlist;
}
