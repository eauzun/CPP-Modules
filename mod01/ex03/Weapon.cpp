#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(std::string type) : type(type) {}

const std::string& Weapon::getType() const{
    return type;
}
void Weapon::setType(std::string value){
    type = value;
}

