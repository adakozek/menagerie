#include "string.h"
#include "gtest_lite.h"
#include "pet.h"
#include "dog.h"
#include "cat.h"
#include "rept.h"
#include "bird.h"
#include "file.h"
#include "menagerie.h"

int main() {
	TEST(String, Konstruktor) {
		String s("Hello");
		EXPECT_EQ("Hello", s.c_str()) << "A konstruktor nem helyesen inicializálta a String objektumot.";
		String s2(s);
		EXPECT_EQ("Hello", s2.c_str()) << "A copy konstruktor nem helyesen inicializálta a String objektumot.";
		String s3;
		EXPECT_EQ("", s3.c_str()) << "A default konstruktor nem helyesen inicializálta a String objektumot.";
	}END

	TEST(String, OperatorPlus) {
		String s1("Hello");
		String s2(" World");
		String s3 = s1 + s2;
		EXPECT_EQ("Hello World", s3.c_str()) << "Az operator+ nem helyesen konkatenálta a String objektumokat.";
		String s4 = s1 + " C++";
		EXPECT_EQ("Hello C++", s4.c_str()) << "Az operator+ nem helyesen konkatenálta a String objektumot egy char*-al.";
		String s5 = s1 + '!';
		EXPECT_EQ("Hello!", s5.c_str()) << "Az operator+ nem helyesen konkatenálta a String objektumot egy char-al.";
	}END

	TEST(String, OperatorPlusEquals) {
		String s1("Hello");
		String s2(" World");
		s1 += s2;
		EXPECT_EQ("Hello World", s1.c_str()) << "Az operator+= nem helyesen konkatenálta a String objektumokat.";
	}END

	TEST(String, OperatorIndex) {
		String s("Hello");
		EXPECT_EQ('H', s[0]) << "Az operator[] nem helyesen adta vissza a karaktert a String objektumból.";
		EXPECT_EQ('o', s[4]) << "Az operator[] nem helyesen adta vissza a karaktert a String objektumból.";
		try {
			char c = s[5];
			(void)c; // elkerüljük a "nem használt változó" figyelmeztetést
			EXPECT_TRUE(false) << "Az operator[] nem dobott kivételt rossz index esetén.";
		} catch (const char* e) {
			EXPECT_STREQ("Rossz index", e) << "Az operator[] nem dobott megfelelő kivételt rossz index esetén.";
		}
	}END

	TEST(String, OperatorEquals) {
		String s1("Hello");
		String s2("Hello");
		String s3("World");
		EXPECT_TRUE(s1 == s2) << "Az operator== nem helyesen hasonlította össze a String objektumokat.";
		EXPECT_FALSE(s1 == s3) << "Az operator== nem helyesen hasonlította össze a String objektumokat.";	
	}END

	TEST(String, OperatorNotEquals) {
		String s1("Hello");
		String s2("Hello");
		String s3("World");
		EXPECT_FALSE(s1 != s2) << "Az operator!= nem helyesen hasonlította össze a String objektumokat.";
		EXPECT_TRUE(s1 != s3) << "Az operator!= nem helyesen hasonlította össze a String objektumokat.";
	}END

	TEST(File, Load) {
		String filename = "test_pet.txt";
		File file(filename);
		Pet* pet = new Dog(String("Bodri"), 10, String("Magyarország"), KUTYA, ROVIDSZORU, KICSI, 10);
		Hetero<Pet> menagerie = file.load();
		EXPECT_EQ(1, menagerie.size()) << "A load függvény nem helyesen töltötte be a házikedvenceket a fájlból.";	
	}END

	TEST(UjRekord, UjRekord) {
		Hetero<Pet> menagerie;
		String filename = "test_pet.txt";
		File file(filename);
		Pet* pet = new Dog(String("Bodri"), 10, String("Magyarország"), KUTYA, ROVIDSZORU, KICSI, 10);
		add(menagerie, *pet);
		EXPECT_EQ(1, menagerie.size()) << "Az add függvény nem helyesen adta hozzá a házikedvencet a menagerie-hez.";
		EXPECT_EQ(pet->getNev(), menagerie[0].getNev()) << "Az add függvény nem helyesen adta hozzá a házikedvencet a menagerie-hez.";
		EXPECT_EQ(pet->getElettartam(), menagerie[0].getElettartam()) << "Az add függvény nem helyesen adta hozzá a házikedvencet a menagerie-hez.";
		EXPECT_EQ(pet->getSzarmazas(), menagerie[0].getSzarmazas()) << "Az add függvény nem helyesen adta hozzá a házikedvencet a menagerie-hez.";
		EXPECT_EQ(pet->getTipus(), menagerie[0].getTipus()) << "Az add függvény nem helyesen adta hozzá a házikedvencet a menagerie-hez.";		
		EXPECT_EQ(ROVIDSZORU, menagerie[0].eq_tipus(*pet)) << "Az add függvény nem helyesen adta hozzá a házikedvencet a menagerie-hez.";
		EXPECT_EQ(KICSI, menagerie[0].eq_tipus(*pet)) << "Az add függvény nem helyesen adta hozzá a házikedvencet a menagerie-hez.";
		EXPECT_EQ(10, menagerie[0].eq_tipus(*pet)) << "Az add függvény nem helyesen adta hozzá a házikedvencet a menagerie-hez.";
		delete pet;
	}END

	TEST(UjRekord, UjRekord2) {
		Hetero<Pet> menagerie;
		String filename = "test_pet.txt";
		File file(filename);
		Pet* pet1 = new Dog(String("Bodri"), 10, String("Magyarország"), KUTYA, ROVIDSZORU, KICSI, 10);
		add(menagerie, *pet1);
		EXPECT_EQ(find(menagerie, 0, "Bodri") , pet1) << "A find függvény nem helyesen találta meg a házikedvencet a menagerie-ben.";
		delete pet1;
	}END

	TEST(Pet, absztrakt) {
	}END

	TEST(Kerses, nev) {
		Hetero<Pet> menagerie;
		add(menagerie, Dog(String("Bodri"), 10, String("Magyarország"), KUTYA, ROVIDSZORU, KICSI, 10));
		EXPECT_EQ(find(menagerie, 0, "Bodri")->getNev(), "Bodri") << "A find függvény nem helyesen találta meg a házikedvencet a menagerie-ben név alapján.";
		EXPECT_EQ(nullptr, find(menagerie, 0, "Labi")) << "Nem létező elemre nullptr-t kell visszaadni a find függvénynek.";
	}END

	TEST(Kerses, tipus) {
		Hetero<Pet> menagerie;
		add(menagerie, Dog(String("Bodri"), 10, String("Magyarország"), KUTYA, ROVIDSZORU, KICSI, 10));
		EXPECT_EQ(find(menagerie, 0, "Bodri")->getTipus(), 0) << "A find függvény nem helyesen találta meg a házikedvencet a menagerie-ben típus alapján.";
		EXPECT_EQ(nullptr, find(menagerie, 1, "Bodri")) << "Nem létező elemre nullptr-t kell visszaadni a find függvénynek.";
	}END

	TEST(Kerses, szarmazas) {
		Hetero<Pet> menagerie;
		add(menagerie, Dog(String("Bodri"), 10, String("Magyarország"), KUTYA, ROVIDSZORU, KICSI, 10));
		EXPECT_EQ(find(menagerie, 0, "Bodri")->getSzarmazas(), "Magyarország") << "A find függvény nem helyesen találta meg a házikedvencet a menagerie-ben származás alapján.";
		EXPECT_EQ(nullptr, find(menagerie, 0, "Labi")) << "Nem létező elemre nullptr-t kell visszaadni a find függvénynek.";
	}END

	TEST(Kerses, elettartam) {
		Hetero<Pet> menagerie;
		add(menagerie, Dog(String("Bodri"), 10, String("Magyarország"), KUTYA, ROVIDSZORU, KICSI, 10));
		EXPECT_EQ(find(menagerie, 0, "Bodri")->getElettartam(), 10) << "A find függvény nem helyesen találta meg a házikedvencet a menagerie-ben élettartam alapján.";
		EXPECT_EQ(nullptr, find(menagerie, 0, "Labi")) << "Nem létező elemre nullptr-t kell visszaadni a find függvénynek.";	
	}END

	TEST(UjRekord, ugyanaz) {
		Hetero<Pet> menagerie;
		String filename = "test_pet.txt";
		File file(filename);
		Pet* pet1 = new Dog(String("Bodri"), 10, String("Magyarország"), KUTYA, ROVIDSZORU, KICSI, 10);
		add(menagerie, *pet1);
		add(menagerie, *pet1);
		EXPECT_EQ(2, menagerie.size()) << "Az add függvény nem helyes";
	}END

	TEST(Dog, konstruktor){
		Dog d(String("Bodri"), 10, String("Magyarország"), KUTYA, ROVIDSZORU, KICSI, 10);
		EXPECT_EQ("Bodri", d.getNev()) << "A Dog konstruktor nem helyesen inicializálta a nev attribútumot.";
		EXPECT_EQ(10, d.getElettartam()) << "A Dog konstruktor nem helyesen inicializálta az elettartam attribútumot.";
		EXPECT_EQ("Magyarország", d.getSzarmazas()) << "A Dog konstruktor nem helyesen inicializálta a szarmazas attribútumot.";
		EXPECT_EQ(KUTYA, d.getTipus()) << "A Dog konstruktor nem helyesen inicializálta a tipus attribútumot.";
		EXPECT_EQ(ROVIDSZORU, d.getSzortipus()) << "A Dog konstruktor nem helyesen inicializálta a szortipus attribútumot.";
		EXPECT_EQ(KICSI, d.getMeret()) << "A Dog konstruktor nem helyesen inicializálta a meret attribútumot.";
		EXPECT_EQ(10, d.getFCI()) << "A Dog konstruktor nem helyesen inicializálta az FCI attribútumot.";
	}END

	TEST(Cat, konstruktor){
		Hetero<String> minta(3);
		minta[0] = String("foltos");
		Cat c(String("Cirmi"), 15, String("Magyarország"), MACSKA, HOSSZUSZORU, KOZEPES, minta);
		EXPECT_EQ("Cirmi", c.getNev()) << "A Cat konstruktor nem helyesen inicializálta a nev attribútumot.";
		EXPECT_EQ(15, c.getElettartam()) << "A Cat konstruktor nem helyesen inicializálta az elettartam attribútumot.";
		EXPECT_EQ("Magyarország", c.getSzarmazas()) << "A Cat konstruktor nem helyesen inicializálta a szarmazas attribútumot.";
		EXPECT_EQ(MACSKA, c.getTipus()) << "A Cat konstruktor nem helyesen inicializálta a tipus attribútumot.";
		EXPECT_EQ(HOSSZUSZORU, c.getSzortipus()) << "A Cat konstruktor nem helyesen inicializálta a szortipus attribútumot.";
		EXPECT_EQ(KOZEPES, c.getMeret()) << "A Cat konstruktor nem helyesen inicializálta a meret attribútumot.";
		EXPECT_EQ("foltos", c.getMinta()[0]) << "A Cat konstruktor nem helyesen inicializálta a minta attribútumot.";	
	}END

	TEST(Bird, konstruktor){
		Bird b(String("Tweety"), 5, String("USA"), MADAR, true);
		EXPECT_EQ("Tweety", b.getNev()) << "A Bird konstruktor nem helyesen inicializálta a nev attribútumot.";
		EXPECT_EQ(5, b.getElettartam()) << "A Bird konstruktor nem helyesen inicializálta az elettartam attribútumot.";
		EXPECT_EQ("USA", b.getSzarmazas()) << "A Bird konstruktor nem helyesen inicializálta a szarmazas attribútumot.";
		EXPECT_EQ(MADAR, b.getTipus()) << "A Bird konstruktor nem helyesen inicializálta a tipus attribútumot.";
		EXPECT_TRUE(b.isTudRepulni()) << "A Bird konstruktor nem helyesen inicializálta a tudRepulni attribútumot.";
	}END

	TEST(Rept, konstruktor){
		Rept r(String("Kígyó"), 20, String("Afrika"), HULLO, false);
		EXPECT_EQ("Kígyó", r.getNev()) << "A Rept konstruktor nem helyesen inicializálta a nev attribútumot.";
		EXPECT_EQ(20, r.getElettartam()) << "A Rept konstruktor nem helyesen inicializálta az elettartam attribútumot.";
		EXPECT_EQ("Afrika", r.getSzarmazas()) << "A Rept konstruktor nem helyesen inicializálta a szarmazas attribútumot.";
		EXPECT_EQ(HULLO, r.getTipus()) << "A Rept konstruktor nem helyesen inicializálta a tipus attribútumot.";
		EXPECT_FALSE(r.isMerevTestu()) << "A Rept konstruktor nem helyesen inicializálta a merevTestu attribútumot.";
	}END

	TEST(Hetero, konstruktor) {
		Hetero<Pet> menagerie(2);
		EXPECT_EQ(0, menagerie.size()) << "A Hetero konstruktor nem helyesen inicializálta a méretet.";
	}END



	return 0;
}