#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB{
    private:
        std::string name;
        Weapon* weapon; //silahsız olabilir yani null olabilir ya da sonradan atama yapılabilir
    public:
        HumanB(std::string name);
        void setWeapon(Weapon& weapon);
        void attack();
};


#endif