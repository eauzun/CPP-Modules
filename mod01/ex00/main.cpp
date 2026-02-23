#include "Zombie.hpp"
#include <iostream>

int main() {
    Zombie* heap = newZombie("HeapZombie");
    heap->announce();
    delete heap;

    randomChump("StackZombie");

    return 0;
}