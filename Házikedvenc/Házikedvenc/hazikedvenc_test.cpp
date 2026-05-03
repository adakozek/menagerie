#include "string.h"

int main() {
	String s1("Hello");
	String s2("World");
	String s3 = s1 + ' ' + s2;
	std::cout << s3 << std::endl; // HelloWorld
}