#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "pet.h"
using namespace std;

void fo() {
	cout << "1. Kereses" << endl;
	cout << "2. Adatbevitel" << endl;
}

void keres(){
	cout << "1. nev szerint" << endl;
	cout << "2. eletkor szerint" << endl;
	cout << "3. szarmazas szerint" << endl;
}

template<typename T>
T beolv();

template<>
String beolv<String>(String ell);

Pet* adatbevitel();

#endif
