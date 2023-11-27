#ifndef SAYILARLISTESI_H
#define SAYILARLISTESI_H

#include "Sayi.h"

class SayilarListesi {
private:
    Sayi* bas;

public:
    SayilarListesi();
    ~SayilarListesi();
    void tekBasamaklariBasaGonder();
    void tersCevir(); 
    void tumunuYazdir();
    Sayi* enBuyukSayiyiCikar();
    void sayiEkle(Sayi* yeniSayi);
    };

#endif 