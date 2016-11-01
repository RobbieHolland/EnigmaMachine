#include "reflector.hpp"

  Reflector::Reflector(const char *path) {
    set_mapping(path);
  }

  void Reflector::set_mapping(const char* path) {
    for (int i = 0; i < util.number_in_alphabet; i++)
      mapping.push_back((i + util.number_in_alphabet / 2)
                         % util.number_in_alphabet);
  }
