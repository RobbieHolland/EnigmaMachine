#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <fstream>
#include "util.hpp"

std::istringstream Util::get_file_contents(const char* path) {
  std::ifstream infile(path);
  if (infile.is_open()) {
    std::string str((std::istreambuf_iterator<char>(infile)),
    std::istreambuf_iterator<char>());
    std::istringstream ss(str);

    infile.close();
    return ss;
  } else {
    fprintf(stderr, "Error opening file");
  }
}

std::vector<int> Util::initialsed_map() {
  std::vector<int> map;
  for (int i = 0; i < number_in_alphabet; i++)
    map.push_back(i);
  return map;
}

int Util::mod(int a, int b) {
  return (((a+b) % number_in_alphabet) + number_in_alphabet) % number_in_alphabet;
}

void Util::print_vector(std::vector<int> vector, int n) {
  for (int i = 0; i < n; i++) {
    std::cout << vector[i] << " ";
  }
  std::cout << std::endl;
}

int Util::char_to_int(char c) {
  return (int) c - (int) 'A';
}

int number_in_alphabet = 26;
char delimeter = ' ';
