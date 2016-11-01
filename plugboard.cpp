#include "plugboard.hpp"

Plugboard::Plugboard(const char *path) {
  set_mapping(path);
}

void Plugboard::set_mapping(const char* path) {
  std::istringstream ss = util.get_file_contents(path);
  std::string token, token1;
  mapping = util.initialsed_map();

  while(std::getline(ss, token, util.delimeter)) {
    std::getline(ss, token1, util.delimeter);
    int token_int = std::stoi(token), token1_int = std::stoi(token1);
    mapping[token_int] = token1_int;
    mapping[token1_int] = token_int;
  }
}
