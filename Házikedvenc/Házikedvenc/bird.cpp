

#include "bird.h"
#include <iostream>
#include "string.h"
#include "hetero.hpp"
#include "pet.h"

void Bird::kiir() {
    std::cout << "Nev: " << getNev() << std::endl;
    std::cout << "Elettartam: " << getElettartam() << std::endl;
    std::cout << "Szarmazas: " << getSzarmazas() << std::endl;
    std::cout << "Tipus: " << getTipus() << std::endl;
    std::cout << "Szarnyfesztav: " << szarnyfesztav << std::endl;
    std::cout << "Ropkepes: " << (ropkepes ? "igen" : "nem") << std::endl;
}