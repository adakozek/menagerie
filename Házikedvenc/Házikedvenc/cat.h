#ifndef CAT_H
#define CAT_H

#include "pet.h"
#include "hetero.hpp"
#include "string.h"

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
	void setSzortipus(size_t szortipus) {
		this->szortipus = szortipus;
	}
	void setMeret(size_t meret) {
		this->meret = meret;
	}
	void setMinta(Hetero<String> minta) {
		this->minta = minta;
	}

	//getterek
	size_t getSzortipus() const {
		return szortipus;
	}
	size_t getMeret() const {
		return meret;
	}
	Hetero<String> getMinta() const {
		return minta;
	}

};


#endif
