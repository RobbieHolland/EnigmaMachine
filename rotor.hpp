#ifndef ROTOR
#define ROTOR

#include <math.h>
#include <vector>
#include "util.hpp"
#include "segment.hpp"

class Rotor: public segment {
public:
  Rotor(const char *path, int position);
  void rotate();
  int back_propagate(int index);

private:
  int count = 0;
  int rotate_limit = util.number_in_alphabet;
  std::vector<int> inverse_mapping;
  void set_mapping(const char *path);
};

#endif
