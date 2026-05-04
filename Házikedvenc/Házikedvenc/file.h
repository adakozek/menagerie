#ifndef FILE_H
#define FILE_H

#include "pet.h"
#include "string.h"
#include "hetero.hpp"

class File {
    String filename;
public:
    File(String filename) : filename(filename) {}
    Hetero<Pet> load();
};

#endif // FILE_H

