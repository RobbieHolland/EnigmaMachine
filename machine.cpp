#include "machine.hpp"

Machine::Machine(std::vector<Rotor*> rs, Reflector* r, Plugboard* pb) {
  rotors = rs;
  reflector = r;
  plugboard = pb;
}

char Machine::propagate(char c) {
  //Convert char to int for machine
  int n = util.char_to_int(c);

  //Go through plugboard
  n = plugboard->propagate(n);

  //Go through rotors forwards
  for (Rotor* rotor : rotors)
    n = rotor->propagate(n);

  //Go through reflector
  n = reflector->propagate(n);

  //Go through rotors backwards and rotate them
  for (int i = rotors.size() - 1; i >= 0; i--) {
    n = rotors[i]->back_propagate(n);

    rotors[i]->rotate();
  }

  //Go back through plugboard
  n = plugboard->propagate(n);

  //Convert int back to char for output
  return (char) (n + (int) 'A');
}
