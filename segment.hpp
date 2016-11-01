#ifndef SEGMENT
#define SEGMENT

#include "util.hpp"

class segment {
  public:
    int propagate(int index);
    virtual void set_mapping(const char* path) =0;
    void print_map();

  protected:
    std::vector<int> mapping;
    int shift = 0;
    Util util;
};

#endif
