#ifndef CAT_H
#define CAT_H

#include "pet.h"
#include "hetero.hpp"

class Cat : public Pet {
	size_t szortipus;
	size_t meret;
	Hetero<String> minta;
public:
	Cat();
	Cat(String nev, size_t elettartam, String szarmazas, size_t tipus, size_t szortipus, size_t meret, Hetero<String> minta);
	void kiir() override;
	virtual ~Cat() {}

	//setterek

};


#endif
