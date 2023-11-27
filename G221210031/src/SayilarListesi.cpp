/** 
* SayilarListesi.cpp
* Sayılardan oluşan listenin işlemlerini gerçekleştirir.
* 2. Öğretim C grubu
* 1. ödev
* 20.11.2023
* Elif Yerlikaya elif.yerlikaya1@ogr.sakarya.edu.tr
*/

#include "SayilarListesi.h"
#include <iostream>

SayilarListesi::SayilarListesi() : bas(NULL) {}

SayilarListesi::~SayilarListesi() {
    Sayi* guncelSayi = bas;
    while (guncelSayi != NULL) {
        Sayi* silinecekSayi = guncelSayi;
        guncelSayi = guncelSayi->sonrakiBasamagiAl();
        delete silinecekSayi;
    }
}
void SayilarListesi::tekBasamaklariBasaGonder() {
    Sayi* guncelSayi = this->bas;
    while (guncelSayi != NULL) {
        guncelSayi->tekBasamaklariBasaGonder();
        guncelSayi = guncelSayi->sonrakiBasamagiAl();
    }
}
void SayilarListesi::tersCevir() {
    Sayi* guncelSayi = this->bas;
    while (guncelSayi != NULL) {
        Basamak* oncekiBasamak = NULL;
        Basamak* guncelBasamak = guncelSayi->basamakBasi();
        Basamak* sonrakiBasamak = NULL;

        while (guncelBasamak != NULL) {
            sonrakiBasamak = guncelBasamak->sonrakiBasamagiAl();
            guncelBasamak->sonrakiBasamagiDegistir(oncekiBasamak);
            oncekiBasamak = guncelBasamak;
            guncelBasamak = sonrakiBasamak;
        }

        guncelSayi->setBas(oncekiBasamak);
        guncelSayi = guncelSayi->sonrakiBasamagiAl();
    }
}

Sayi* SayilarListesi::enBuyukSayiyiCikar() {
    if (bas == NULL) return NULL;

    Sayi* oncekiSayi = NULL;
    Sayi* guncelSayi = bas;
    Sayi* enBuyukSayiOnceki = NULL;
    Sayi* enBuyukSayi = bas;

    while (guncelSayi->sonrakiBasamagiAl() != NULL) {
        oncekiSayi = guncelSayi;
        guncelSayi = guncelSayi->sonrakiBasamagiAl();
        if (guncelSayi->basamakDegeriAl() > enBuyukSayi->basamakDegeriAl()) {
            enBuyukSayi = guncelSayi;
            enBuyukSayiOnceki = oncekiSayi;
        }
    }

    if (enBuyukSayiOnceki != NULL) {
        enBuyukSayiOnceki->sonrakiBasamagiDegistir(enBuyukSayi->sonrakiBasamagiAl());
    } else {
        bas = enBuyukSayi->sonrakiBasamagiAl();
    }

    enBuyukSayi->sonrakiBasamagiDegistir(NULL);
    return enBuyukSayi;
}

void SayilarListesi::tumunuYazdir() {
    Sayi* guncelSayi = bas;
    while (guncelSayi != NULL) {
        guncelSayi->tumunuYazdir();
        std::cout << std::endl << std::endl;
        guncelSayi = guncelSayi->sonrakiBasamagiAl();
    }
}

void SayilarListesi::sayiEkle(Sayi* yeniSayi) {
    if (bas == NULL) {
        bas = yeniSayi;
        yeniSayi->sonrakiBasamagiDegistir(NULL);
    } else {
        Sayi* guncelSayi = bas;
        while (guncelSayi->sonrakiBasamagiAl() != NULL) {
            guncelSayi = guncelSayi->sonrakiBasamagiAl();
        }
        guncelSayi->sonrakiBasamagiDegistir(yeniSayi);
        yeniSayi->sonrakiBasamagiDegistir(NULL);
    }
}
