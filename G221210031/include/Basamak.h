#ifndef BASAMAK_H
#define BASAMAK_H

class Basamak {
private:
    int deger;
    Basamak* sonraki;
public:
    Basamak(int deger);
    void sonrakiBasamagiDegistir(Basamak* sonraki);
    Basamak* sonrakiBasamagiAl() const;
    int basamakDegeriAl() const;
};

#endif 