#ifndef PLUGBOARD
#define PLUGBOARD

#include "util.hpp"
#include "segment.hpp"

class Plugboard: public segment {
public:
  Plugboard(const char *path);
  void set_mapping(const char* path);
};

#endif
