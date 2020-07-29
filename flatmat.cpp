#include "flatmat.h"

std::string FlatMaterial::toString () {
  std::ostringstream ss;

  ss << "Flat Material with color" << color.toString();

  return ss.str();
};
