/** 
* Basamak.cpp
* Basamak işlemlerini yapar.
* 2. Öğretim C grubu
* 1. ödev
* 07.11.2023
* Elif Yerlikaya elif.yerlikaya1@ogr.sakarya.edu.tr
*/




#include <iostream>
#include "Basamak.h"

Basamak::Basamak(int deger) : deger(deger), sonraki(NULL) {}

Basamak* Basamak::sonrakiBasamagiAl() const {
    return this->sonraki;
}

int Basamak::basamakDegeriAl() const {
    return this->deger;
}

void Basamak::sonrakiBasamagiDegistir(Basamak* bsmk) {
    this->sonraki = bsmk;
}
