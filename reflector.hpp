#ifndef REFLECTOR
#define REFLECTOR

#include "util.hpp"
#include "segment.hpp"

class Reflector: public segment {
public:
  Reflector(const char *path);
  void set_mapping(const char* path);
};

#endif
