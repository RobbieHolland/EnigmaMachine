#ifndef UTIL
#define UTIL

#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <fstream>

class Util {
public:
  std::istringstream get_file_contents(const char* path);
  std::vector<int> initialsed_map();
  int mod(int a, int b);
  int char_to_int(char c);
  void print_vector(std::vector<int> vector, int n);

  int number_in_alphabet = 26;
  char delimeter = ' ';
};
#endif
