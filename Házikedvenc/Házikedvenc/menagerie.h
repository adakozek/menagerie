#ifndef MENAGERIE_H
#define MENAGERIE_H

#include "pet.h"
#include "hetero.hpp"

// kereséshez szükséges függvények

//új rekord
void add(Hetero<Pet>& menagerie, const Pet& pet);

Pet* find(const Hetero<Pet>& menagerie, size_t tipus, const String& nev);

#endif
