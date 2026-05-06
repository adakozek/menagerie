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

	//getterek
	size_t getHossz() const {
		return hossz;
	}
	bool getMerges() const {
		return merges;
	}
	size_t getLabakszama() const {
		return labakszama;
	}

	//setterek
	void setHossz(size_t hossz) {
		this->hossz = hossz;
	}
	void setMerges(bool merges) {
		this->merges = merges;
	}
	void setLabakszama(size_t labakszama) {
		this->labakszama = labakszama;
	}
};

#endif
