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

	//GETTEREK
	size_t getSzortipus() const {
		return szortipus;
	}
	size_t getMeret() const {
		return meret;
	}
	size_t getFCI() const {
		return FCI;
	}
	virtual ~Dog() {}

	//SETTEREK
	void setSzortipus(size_t szortipus) {
		this->szortipus = szortipus;
	}
	void setMeret(size_t meret) {
		this->meret = meret;
	}
	void setFCI(size_t FCI) {
		this->FCI = FCI;
	}
};

#endif
