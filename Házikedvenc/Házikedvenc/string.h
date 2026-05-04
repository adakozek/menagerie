#ifndef STRING_H
#define STRING_H

#include <iostream>

class String {
	char* str;
	size_t length;
public:
	String(); // default constructor
	String(const char* s); // construkltor char*-ból
	String(const String& other); // copy constructor
	~String(); // destructor
	String& operator=(const String& other); // egyenlőség operator

	size_t size() const; // hossz lekérdezése
	const char* c_str() const; // C-string lekérdezése

	char& operator[](size_t i); // indexelő operator
	const char& operator[](size_t i) const; // const indexelő operator

	bool operator==(const String& other) const; // egyenlőség operator
	bool operator!=(const String& other) const; // nem egyenlőség operator

	String operator+(const String& other) const; // konkatenáció operator
	String operator+(const char* s) const; // konkatenáció operator char*-al
	String operator+(char c) const; // konkatenáció operator char-al
	String& operator+=(const String& other); // konkatenáció és hozzárendelés operator

	friend std::ostream& operator<<(std::ostream& os, const String& s); // kiírás operator
	friend std::istream& operator>>(std::istream& is, String& s); // beolvasás operator
};

#endif
