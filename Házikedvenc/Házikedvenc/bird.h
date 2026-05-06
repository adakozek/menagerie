#ifndef BIRD_H
#define BIRD_H

#include "pet.h"
#include "string.h"

class Bird : public Pet {
	size_t szarnyfesztav;
	bool ropkepes;
public:
	Bird(): szarnyfesztav(-1), ropkepes(true) {}
	Bird(String nev, size_t elettartam, String szarmazas, size_t tipus, size_t szarnyfesztav, bool ropkepes): Pet(nev, elettartam, szarmazas,tipus), szarnyfesztav(-1), ropkepes(true) {}

	void kiir() override;
	virtual ~Bird() {}

	//getterek
	size_t getSzarnyfesztav() const {
		return szarnyfesztav;
	}
	bool getRopkepes() const {
		return ropkepes;
	}
	//setterek
	void setSzarnyfesztav(size_t szarnyfesztav) {
		this->szarnyfesztav = szarnyfesztav;
	}
	void setRopkepes(bool ropkepes) {
		this->ropkepes = ropkepes;
	}
};

#endif