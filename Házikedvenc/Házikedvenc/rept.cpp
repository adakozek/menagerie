

#include "rept.h"

void Rept::kiir() {
    std::cout << "Nev: " << getNev() << std::endl;
    std::cout << "Elettartam: " << getElettartam() << std::endl;
    std::cout << "Szarmazas: " << getSzarmazas() << std::endl;
    std::cout << "Tipus: " << getTipus() << std::endl;
    std::cout << "Hossz: " << hossz << std::endl;
    std::cout << "Merges: " << (merges ? "igen" : "nem") << std::endl;
    std::cout << "Labakszama: " << labakszama << std::endl;
}