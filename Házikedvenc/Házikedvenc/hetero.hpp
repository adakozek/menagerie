#ifndef HETERO_H
#define HETERO_H

#include "pet.h"
#include "string.h"

template<typename T>
class Hetero {
	T* tomb;
	size_t meret;
public:
	Hetero() {
		tomb = nullptr;
		meret = 0;
	}
	Hetero(size_t meret) {
		this->meret = meret;
		tomb = new T[meret];
	}
	Hetero(const Hetero& other) {
		this->meret = other.meret;
		this->tomb = new T[other.meret];
		for (size_t i = 0; i < other.meret; i++) {
			this->tomb[i] = other.tomb[i];
		}
	}
	~Hetero() {
		delete[] tomb;
	}

	Hetero& operator=(const Hetero& other) {
		if (this != &other) {
			delete[] tomb;
			this->meret = other.meret;
			this->tomb = new T[other.meret];
			for (size_t i = 0; i < other.meret; i++) {
				this->tomb[i] = other.tomb[i];
			}
		})
	}
	Hetero operator+(const Hetero& other) const {
		Hetero result(this->meret + other.meret);
		for (size_t i = 0; i < this->meret; i++) {
			result.tomb[i] = this->tomb[i];
		}
		for (size_t i = 0; i < other.meret; i++) {
			result.tomb[this->meret + i] = other.tomb[i];
		}
		return result;
	}
	Hetero& operator+=(const Hetero& other) {
		*this = *this + other;
		return *this;
	}

	size_t size() const {
		return meret;
	}
	T& operator[](size_t i) {
		return tomb[i];
	}
	const T& operator[](size_t i) const {
		return tomb[i];
	}
};

#endif
