

#include "dog.h"

Dog::Dog() : Pet(), szortipus(0), meret(0), FCI(0) {}
Dog::Dog(String nev, size_t elettartam, String szarmazas, size_t tipus, size_t szortipus, size_t meret, size_t FCI)
    : Pet(nev, elettartam, szarmazas, tipus), szortipus(szortipus), meret(meret), FCI(FCI) {}

void Dog::kiir() {
    std::cout << "Nev: " << getNev() << std::endl;
    std::cout << "Elettartam: " << getElettartam() << std::endl;
    std::cout << "Szarmazas: " << getSzarmazas() << std::endl;
    std::cout << "Tipus: " << getTipus() << std::endl;
    if (szortipus == ROVIDSZORU) {
        std::cout << "Szortipus: Rovid szoru" << std::endl;
    } else if (szortipus == HOSSZUSZORU) {
        std::cout << "Szortipus: Hosszu szoru" << std::endl;
    } else if (szortipus == KOPASZ) {
        std::cout << "Szortipus: Kopasz" << std::endl;
    } else {
        std::cout << "Szortipus: Ismeretlen" << std::endl;
    }
    if (meret == EXTRAKICSI) {
        std::cout << "Meret: Extrakicsi" << std::endl;
    } else if (meret == KICSI) {
        std::cout << "Meret: Kicsi" << std::endl;
    } else if (meret == KOZEPES) {
        std::cout << "Meret: Kozepes" << std::endl;
    } else if (meret == NAGY) {
        std::cout << "Meret: Nagy" << std::endl;
    } else if (meret == EXTRANAGY) {
        std::cout << "Meret: Extranagy" << std::endl;
    } else {
        std::cout << "Meret: Ismeretlen" << std::endl;
    }
    switch (FCI) {
        case 1:
            std::cout << "FCI 1: Juhasz- és pasztorkutyak (kiveve svajci pasztorkutyak)" << std::endl;
            break;
        case 2:
            std::cout << "FCI 2: Pinscherek, schnauzerek - molosszerek - svajci hegyi- és pasztorkutyak" << std::endl;
            break;
        case 3:
            std::cout << "FCI 3: Terrierek" << std::endl;
            break;
        case 4:
            std::cout << "FCI 4: Tacskok" << std::endl;
            break;
        case 5:
            std::cout << "FCI 5: Spiccek és osi tipusu kutyak" << std::endl;
            break;
        case 6:
            std::cout << "FCI 6: Kopok és rokon fajtak" << std::endl;
            break;
        case 7:
            std::cout << "FCI 7: Vizslak és szetterek" << std::endl;
            break;
        case 8:
            std::cout << "FCI 8: Retrieverek - hajtokutyak - vizi vadaszok" << std::endl;
            break;
        case 9:
            std::cout << " (FCI 9: Tarsasagi kutyak" << std::endl;
            break;
        case 10:
            std::cout << "FCI 10: Agarak" << std::endl;
            break;
        default:
            std::cout << "Ismeretlen FCI csoport" << std::endl;
    }
}