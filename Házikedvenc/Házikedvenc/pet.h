

#ifndef PET_H
#define PET_H

#include "string.h"

enum Típus { KUTYA, MACSKA, MADAR, HULLO };

enum Szortipus { ROVIDSZORU, HOSSZUSZORU, KOPASZ };

enum Meret{ EXTRAKICSI, KICSI, KOZEPES, NAGY, EXTRANAGY };

// Abstrakt osztály a házikedvencek számára
class Pet {
	String nev;
	size_t elettartam;
	String szarmazas;
	size_t tipus; // 0: kutya, 1: macska, 2: madár, 3: hüllő
public:
	Pet() : nev(""), elettartam(-1), szarmazas(""), tipus(-1) {} // default konstruktor
	Pet(String nev, size_t elettartam, String szarmazas, size_t tipus) : nev(nev), elettartam(elettartam), szarmazas(szarmazas), tipus(tipus) {} // konstruktor
	virtual void kiir() = 0; // tisztán virtuális függvény a kiíráshoz
	bool operator==(const Pet& other) const { // egyenlőség operátor a pet osztályhoz
		return nev == other.nev && elettartam == other.elettartam && szarmazas == other.szarmazas && tipus == other.tipus;
	}
	bool eq_nev(const Pet& other) const { // név alapján egyenlőség vizsgálata
		return nev == other.nev;
	}
	bool eq_szarmazas(const Pet& other) const { // származás alapján egyenlőség vizsgálata
		return szarmazas == other.szarmazas;
	}
	bool eq_tipus(const Pet& other) const { // típus alapján egyenlőség vizsgálata
		return tipus == other.tipus;
	}
	bool eq_elettartam(const Pet& other) const { // élettartam alapján egyenlőség vizsgálata
		return elettartam == other.elettartam;
	}
	virtual ~Pet() {} // virtuális destruktor

	//setterek
	void setNev(String nev) {
		this->nev = nev;
	}
	void setElettartam(size_t elettartam) {
		this->elettartam = elettartam;
	}
	void setSzarmazas(String szarmazas) {
		this->szarmazas = szarmazas;
	}
	void setTipus(size_t tipus) {
		this->tipus = tipus;
	}

	//getterek
	String getNev() const {
		return nev;
	}
	size_t getElettartam() const {
		return elettartam;
	}
	String getSzarmazas() const {
		return szarmazas;
	}
	size_t getTipus() const {
		return tipus;
	}


};


#endif
