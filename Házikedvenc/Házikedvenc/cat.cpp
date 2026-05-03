

#include "cat.h"

Cat::Cat() {
	minta = nullptr;
}
Cat::Cat(String nev, size_t elettartam, String szarmazas, size_t tipus, size_t szortipus, size_t meret /*String* minta*/)
	: Pet(nev, elettartam, szarmazas, tipus), szortipus(szortipus), meret(meret) {
	
}