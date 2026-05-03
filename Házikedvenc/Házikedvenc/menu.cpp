
#include "menu.h"
#include "string.h"

template<typename T>
T beolv(T ell) {
	T temp;
	cin >> temp;
	return temp;
}

template<>
String beolv<String>(String ell) {
	String temp;
	cin >> temp;
	return temp;
}


Pet* adatbevitel() {
	Pet* temp;
	String str;
	size_t t;
	cout << "Adja meg a kedvenc nevét: ";
	temp->setNev(beolv(str));
	cout << endl << "Adja meg a kedvenc élettartamát: ";
	temp->setElettartam(beolv(t));
	cout << endl << "Adja meg a kedvenc nevét: ";
	temp->setSzarmazas(beolv(str));
	cout << endl << "Adja meg a kedvence típusát: ";
	cin >> str;
	if (str == "KUTYA") {
		temp->setTipus(KUTYA);
		cout << endl<< "Adja meg az FCI. csoportot: ";
		temp;
		cout << endl << "Adja meg a kutya méretét: ";

		cout << endl << "Adja meg a kutya szőrtípusát: ";

	}
	else if (str == "MACSKA") {
		temp->setTipus(MACSKA);
		cout << endl << "Adja meg a macska szőrtípusát: ";

		t = beolv(t);
		//StringTomb;
		for (size_t i = 0; i < 3; i++) {
			
		}

		cout << endl << "Adja meg a kutya méretét: ";

	}
	else if (str == "MADAR") {
		temp->setTipus(MADAR);
		cout << endl << "Adja meg hogy a madár tud-e repülni (Y/n): ";

		if (beolv(str) == "Y") {
			//madár tud repülni
		}else if (beolv(str) == "n") {
			//nem tud repülni
		}
		else {
			cout << "Hibás adat!" << endl;
			return nullptr;
		}
		cout << endl << "Adja meg a madár szárnyfesztávolságát: ";

	}
	else if (str == "HULLO") {
		temp->setTipus(HULLO);
		cout << endl << "Adja mega lábak számát: ";

		cout << endl << "Adja meg hogy a hüllő mérgező-e (Y/n): ";
		if (beolv(str) == "Y") {
			//mérgező
		}
		else if (beolv(str) == "n") {
			//nem nem mérgező
		}
		else {
			cout << "Hibás adat!" << endl;
			return nullptr;
		}
		cout << endl << "Adja meg a hüllő hosszát helyét: ";

	}
	else {
		cout << "Hibás típus!" << endl;
		return nullptr;
	}


}