#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() : name(name) {}

void Zombie::setName(std::string name)
{
    this->name = name;
}

Zombie::~Zombie() 
{
    std::cout << name << " destroyed." << std::endl;
}

void Zombie::announce() const 
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}