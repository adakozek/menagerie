#ifndef REPT_H
#define REPT_H

#include "pet.h"

class Rept : public Pet {
	size_t hossz;
	bool merges;
	size_t labakszama;
public:
	Rept(): hossz(-1), merges(true), labakszama(-1) {}
	Rept(String nev, size_t elettartam, String szarmazas, size_t tipus, size_t hossz, bool merges, size_t labakszama);
	void kiir() override;
	virtual ~Rept() {}
};

#endif
