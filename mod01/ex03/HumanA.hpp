#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA{
    private:
        std::string name;
        Weapon& weapon; //her zaman silahlı, ondan null olamaz ya da değiştirilemez
    public:
        HumanA(std::string name, Weapon& weapon);
        void attack();
};

#endif