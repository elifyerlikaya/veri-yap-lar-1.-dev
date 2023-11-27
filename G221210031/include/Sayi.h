#ifndef SAYI_H
#define SAYI_H

#include "Basamak.h"
class Sayi {
private:
    Basamak* bas;
    Sayi* sonraki;  
public:
    Sayi();
    ~Sayi();
    void tekBasamaklariBasaGonder();
    int basamakDegeriAl() const;      
    Sayi* sonrakiBasamagiAl() const { return sonraki; }
    void tumunuYazdir() ;
    void sonrakiBasamagiDegistir(Sayi* pntr) { sonraki = pntr; }
    Basamak* basamakBasi() const;     
    void basamakEkle(int deger);
    bool isTekBasamakli() const;
    void setBas(Basamak* listeBasi); };

#endif 