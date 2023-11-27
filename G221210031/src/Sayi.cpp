/** 
* Sayi.cpp
* Sayı ile yapılan işlemler var. Menüdeki isterlerin fonksiyonları bulunuyor.
* 2. Öğretim C grubu
* 1. ödev
* 17.11.2023
* Elif Yerlikaya elif.yerlikaya1@ogr.sakarya.edu.tr
*/



#include "Sayi.h"
#include <iomanip>
#include <sstream>
#include <string>
#include <iostream>

using namespace::std;
Sayi::Sayi() : bas(NULL), sonraki(NULL) {}

Sayi::~Sayi() {
    Basamak* mevcutBasamak = bas;
    while (mevcutBasamak != NULL) {
        Basamak* silinecekBasamak = mevcutBasamak;
        mevcutBasamak = mevcutBasamak->sonrakiBasamagiAl();
        delete silinecekBasamak;
    }
}


void Sayi::tekBasamaklariBasaGonder() {
    Basamak* oncekiBasamak = NULL;
    Basamak* guncelBasamak = this->bas;     
    Basamak* baslangic = NULL;
    Basamak* yeniBaslangic = NULL;
    Basamak* birSonraki = NULL; 

    while (guncelBasamak != NULL) {
        birSonraki = guncelBasamak->sonrakiBasamagiAl();
        if (guncelBasamak->basamakDegeriAl() % 2 == 1) {  
            if (baslangic == NULL) {
                baslangic = guncelBasamak;
            } else {
                yeniBaslangic->sonrakiBasamagiDegistir(guncelBasamak);
            }

            yeniBaslangic = guncelBasamak;
            if (oncekiBasamak == NULL) {
                this->bas = birSonraki;
            } else {
                oncekiBasamak->sonrakiBasamagiDegistir(birSonraki);
            }

            guncelBasamak->sonrakiBasamagiDegistir(NULL);
        } else {
            oncekiBasamak = guncelBasamak;
        }

        guncelBasamak = birSonraki;
    }

    if (baslangic != NULL) {
        yeniBaslangic->sonrakiBasamagiDegistir(this->bas);
        this->bas = baslangic;
    }
}


void Sayi::basamakEkle(int deger) {
    Basamak* yeniBasamak = new Basamak(deger);
    if (bas == NULL) {
        bas = yeniBasamak;
    } else {
        yeniBasamak->sonrakiBasamagiDegistir(bas);
        bas = yeniBasamak;
    }
}

    void Sayi::tumunuYazdir() {
    Basamak* simdikiBasamak = bas;
    std::ostringstream satir1, satir2, satir3, satir4, satir5;

    satir1 << "##########   ";
    satir3 << "#--------#   ";
    satir5 << "##########   ";
    satir2 << "#" << std::hex << std::uppercase << std::setfill('0') << std::setw(8) << reinterpret_cast<uintptr_t>(this) << "#   ";
    satir4 << "#" << std::setw(8) << basamakDegeriAl() << "#   ";
    while (simdikiBasamak != NULL) {
        satir2 << "* " << std::setw(3) << (reinterpret_cast<uintptr_t>(simdikiBasamak) & 0xFFF) << " * ";
        satir4 << "*  " << std::to_string(simdikiBasamak->basamakDegeriAl()) << "  * ";
        satir1 << "******* ";
        satir3 << "******* ";
        satir5 << "******* ";
        simdikiBasamak = simdikiBasamak->sonrakiBasamagiAl();
    }
    if (bas == NULL) {
        satir1 << "         ";
        satir3 << "           ";
        satir5 << "         ";
        satir4 << "#" << std::setw(8) << " " << "#   ";
    }

    std::cout << satir1.str() << std::endl;
    std::cout << satir2.str() << std::endl;
    std::cout << satir3.str() << std::endl;
    std::cout << satir4.str() << std::endl;
    std::cout << satir5.str() << std::endl;
}

bool Sayi::isTekBasamakli() const {
    return bas != NULL && !bas->sonrakiBasamagiAl(); 
    }

int Sayi::basamakDegeriAl() const {
    int toplamDeger = 0;
    Basamak* guncelBasamak = bas;

    while (guncelBasamak != NULL) {
        toplamDeger = toplamDeger * 10 + guncelBasamak->basamakDegeriAl();
        guncelBasamak = guncelBasamak->sonrakiBasamagiAl();
    }

    return toplamDeger;
}


Basamak* Sayi::basamakBasi() const {
    return this->bas;
}

void Sayi::setBas(Basamak* listeBasi) {
    this->bas = listeBasi;
}

