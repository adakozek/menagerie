#ifndef DOG_H
#define DOG_H

#include "pet.h"

class Dog : public Pet {
	size_t szortipus;
	size_t meret;
	size_t FCI;
public:
	Dog();
	Dog(String nev, size_t elettartam, String szarmazas, size_t tipus, size_t szortipus, size_t meret, size_t FCI);
	void kiir() override;
	virtual ~Dog() {}
};

#endif
