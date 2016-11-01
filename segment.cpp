#include <stdexcept>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <stdexcept>
#include "segment.hpp"

int segment::propagate(int index) {
  index = util.mod(index, shift);
  if (index < 0 || index >= util.number_in_alphabet)
    std::cerr << "Attempted to propagate negative value!";

  int result = mapping[(index) % util.number_in_alphabet];
  return util.mod(result, -shift);
};

void segment::print_map() {
  util.print_vector(mapping, util.number_in_alphabet);
}
