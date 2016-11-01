#include <math.h>
#include "rotor.hpp"

Rotor::Rotor(const char *path, int position) {
  set_mapping(path);
  rotate_limit = pow(util.number_in_alphabet, position);
}

void Rotor::rotate() {
  count ++;
  if (count % rotate_limit == 0)
    shift ++;
}

int Rotor::back_propagate(int index) {
  if (index < 0 || index >= util.number_in_alphabet)
    std::cerr << "Attempted to back-propagate negative value!";

  index = util.mod(index, shift);

  int i = inverse_mapping[index];
  return util.mod(i, -shift);


};

void Rotor::set_mapping(const char *path) {
  std::istringstream ss = util.get_file_contents(path);
  std::string token;
  while(std::getline(ss, token, util.delimeter))
    mapping.push_back(std::stoi(token));

  for(int i = 0; i < util.number_in_alphabet; i++)
    inverse_mapping.push_back(i);

  for(int i = 0; i < util.number_in_alphabet; i++) {
    for(int j = 0; j < util.number_in_alphabet; j++) {
      if (mapping[i] == j)
        inverse_mapping[j] = i;
    }
  }
}
