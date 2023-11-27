/** 
* main.cpp
* Dosyadan okuma işlemlerini yapar. Menü seçim işlemleri de buradadır.
* 2. Öğretim C grubu
* 1. ödev
* 10.11.2023
* Elif Yerlikaya elif.yerlikaya1@ogr.sakarya.edu.tr
*/


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Sayi.h"
#include "Basamak.h"
#include "SayilarListesi.h"

int main() {
    std::ifstream dosya("Sayilar.txt");
    std::string line;
    SayilarListesi liste;
    Sayi* removedNum = NULL;

    if (!dosya.is_open()) {
        std::cerr << "Sayilar.txt dosyasi acilamadi!" << std::endl;
        return -1;
    }

   while (getline(dosya, line)) {
    std::istringstream lineStream(line);
    int number;
    while (lineStream >> number) {
        Sayi* num = new Sayi();
        while (number > 0) {
            int basamak = number % 10;
            num->basamakEkle(basamak);
            number /= 10;
        }
        liste.sayiEkle(num);
    }
}

    dosya.close();

    int choice;
    do {
        liste.tumunuYazdir();
        std::cout << "1. Tek Basamaklari Basa Al\n2. Basamaklari Ters Cevir\n3. En Buyuk Sayiyi Cikar\n4. Cikis\nSeciminizi yapiniz: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                liste.tekBasamaklariBasaGonder();
                break;
            case 2:
                liste.tersCevir();
                break;
            case 3:
                removedNum = liste.enBuyukSayiyiCikar();
                if (removedNum) {
                    std::cout << "En buyuk sayi cikarildi: \n";
                    removedNum->tumunuYazdir();
                    std::cout << '\n';
                    delete removedNum;
                } else {
                    std::cout << "Listede sayi yok!" << std::endl;
                }
                break;
            case 4:
                std::cout << "Programdan cikiliyor..." << std::endl;
                break;
            default:
                std::cout << "Gecersiz secim. Lutfen tekrar deneyin." << std::endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
