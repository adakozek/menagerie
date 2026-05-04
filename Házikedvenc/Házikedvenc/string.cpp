#include <iostream>
#include <cstring>
#include "string.h"
#include <cctype>

String::String() {
	str = nullptr;
	length = 0;
}
String::String(const char* s) {
	length = strlen(s);
	str = new char[length + 1];
	strcpy(str, s);
	str[length] = '\0';
}
String::String(const String& other) {
	length = other.length;
	str = new char[length + 1];
	strcpy(str, other.str);
	str[length] = '\0';
}
String::~String() {
	delete[] str;
}

String& String::operator=(const String& other) {
	if (this != &other) {
		delete[] str;
		length = other.length;
		str = new char[length + 1];
		strcpy(str, other.str);
		str[length] = '\0';
	}
	return *this;
}

size_t String::size() const {
	return length;
}
const char* String::c_str() const {
	return str;
}

char& String::operator[](size_t i) {
	if (i >= length) {
		throw "Rossz index";
	}
	return str[i];
}
const char& String::operator[](size_t i) const {
	if (i >= length) {
		throw "Rossz index";
	}
	return str[i];
}

bool String::operator==(const String& other) const {
	if (this == &other) {
		return true;
	}
	if (length != other.length) {
		return false;
	}
	if (strcmp(str, other.str)) {
		return false;
	}
	return true;
}
bool String::operator!=(const String& other) const {
	if (!(*this == other)) {
		return true;
	}
	return false;
}

String String::operator+(const char* s) const {
	String temp;
	temp.length = length + strlen(s);
	temp.str = new char[temp.length + 1];
	strcpy(temp.str, str);
	strcat(temp.str, s);
	temp.str[temp.length] = '\0';
	return temp;
}
String String::operator+(char c) const {
	String temp;
	temp.length = length + 1;
	temp.str = new char[temp.length + 1];
	strcpy(temp.str, str);
	temp.str[length] = c;
	temp.str[temp.length] = '\0';
	return temp;
}


String String::operator+(const String& other) const{
	String temp;
	temp.length = length + other.length;
	temp.str = new char[temp.length + 1];
	strcpy(temp.str, str);
	strcat(temp.str, other.str);
	temp.str[temp.length] = '\0';
	return temp;
}
String& String::operator+=(const String& other){
	String temp = *this + other;
	this->length = temp.length;	
	this->str = temp.str;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const String& s) {
	os << s.c_str();
	return os;

}
std::istream& operator>>(std::istream& is, String& s) {
	unsigned char ch;
	s = String("");
	std::ios_base::fmtflags fl = is.flags();
	is.setf(std::ios_base::skipws);
	while (is >> ch) {
		is.unsetf(std::ios_base::skipws);
		if (ch == ';') {
			is.putback(ch);
			break;
		}
		else {
			s = s + ch;
		}
	}
	is.setf(fl);
	return is;

}