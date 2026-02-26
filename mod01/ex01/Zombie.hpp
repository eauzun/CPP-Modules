#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie 
{
private:
    std::string name;

public:
    Zombie();
    void setName(std::string name); //array allocation için
    ~Zombie();
    void announce() const; //state değişmemesi için const
};

Zombie* zombieHorde(int N, std::string name);

#endif