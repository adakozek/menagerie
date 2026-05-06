

#include "cat.h"

Cat::Cat() {
	minta = Hetero<String>();
}
Cat::Cat(String nev, size_t elettartam, String szarmazas, size_t tipus, size_t szortipus, size_t meret, Hetero<String> minta)
	: Pet(nev, elettartam, szarmazas, tipus), szortipus(szortipus), meret(meret), minta(minta) {}
	
void Cat::kiir() {
	std::cout << "Nev: " << getNev() << std::endl;
	std::cout << "Elettartam: " << getElettartam() << std::endl;
	std::cout << "Szarmazas: " << getSzarmazas() << std::endl;
	std::cout << "Tipus: " << "Macska" << std::endl;
	if (szortipus == ROVIDSZORU) {
        std::cout << "Szortipus: Rovid szoru" << std::endl;
    } else if (szortipus == HOSSZUSZORU) {
        std::cout << "Szortipus: Hosszu szoru" << std::endl;
    } else if (szortipus == KOPASZ) {
        std::cout << "Szortipus: Kopasz" << std::endl;
    } else {
        std::cout << "Szortipus: Ismeretlen" << std::endl;
    }
	if (meret == 1) {
		std::cout << "Meret: Kicsi" << std::endl;
	}
	else if (meret == 2) {
		std::cout << "Meret: Kozepes" << std::endl;
	}
	else if (meret == 3) {
		std::cout << "Meret: Nagy" << std::endl;
	}
	else {
		std::cout << "Meret: Ismeretlen" << std::endl;
	}
	std::cout << "Minta: " << minta << std::endl;
}