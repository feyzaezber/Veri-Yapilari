#ifndef SAYILARLISTESI_HPP
#define SAYILARLISTESI_HPP

#include "Dugum.hpp"

class SayilarListesi {
public:
    Dugum* dugumHead;

    SayilarListesi();

    void ekleSayi(const Sayi& sayi);
    void yazdir();
    void tekBasamaklariBasaAl();
    void basamaklariTersCevir();
    int enBuyukSayiyiBul();
    void ekranaYazdir() const;
};

#endif