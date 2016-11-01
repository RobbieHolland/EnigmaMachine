#include <vector>
#include <stdexcept>
#include <iostream>
#include <ctype.h>
#include <fstream>
#include "util.hpp"
#include "rotor.hpp"
#include "plugboard.hpp"
#include "reflector.hpp"
#include "machine.hpp"

int main(int argc, char **argv){
  Util util;
  int last_rotor_index = argc - 2;
  int plugboard_index = argc - 1;

  //Create rotors
  std::vector<Rotor*> rotors;
  for (int i = 0; i < last_rotor_index; i++)
    rotors.push_back(new Rotor(argv[i + 1], i));

  //Create plugboard
  Plugboard* plugboard = new Plugboard(argv[plugboard_index]);

  //Create reflector
  Reflector* reflector = new Reflector(NULL);

  //Create the enigma machine
  Machine* machine = new Machine(rotors, reflector, plugboard);

  //Propagate plain text through machine, output encoded text
  char c;
  while (std::cin >> std::ws >> c) {
    if (isupper(c)) {
      std::cout << machine->propagate(c);
    } else {
      exit(-1);
    }
  }

  return 0;
}
