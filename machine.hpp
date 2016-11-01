#include "rotor.hpp"
#include "plugboard.hpp"
#include "reflector.hpp"
#include "util.hpp"

class Machine {
public:
  Machine(std::vector<Rotor*> rs, Reflector* r, Plugboard* pb);
  char propagate(char c);

private:
  std::vector<Rotor*> rotors;
  Reflector* reflector;
  Plugboard* plugboard;
  Util util;
};
