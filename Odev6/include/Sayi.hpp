

#ifndef SAYI_HPP
#define SAYI_HPP

#include "Basamak.hpp"

class Sayi {
public:

    Sayi();
    Sayi(int sayi);
	~Sayi();
    void ekleBasamak(int deger);
    void yazdir() const;
    void tekBasamaklariBasaAl();
    void basamaklariTersCevir();
    int enBuyukSayiyiBul();
    bool tekBasamakVarMi() const;
     Basamak* getBasamakHead() const {
        return basamakHead;
    }
	
	

private:
    Basamak* basamakHead;
    Basamak* basamakTail;
};

#endif
