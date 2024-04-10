#include "Basamak.hpp"

/** 
* @file : Odev6
* @description : Tek yönlü bağlı listeler kullanarak tam sayılar üzerinde çeşitli işlemler yaptırmak
* @course : 2.Öğretim A Grubu
* @assignment 1.Ödev
* @date : 19.11.2023
* @author : Feyza Ezber feyza.ezber@ogr.sakarya.edu.tr
*/

Basamak::Basamak(int deger) : deger(deger), sonraki(nullptr) {}

Basamak::~Basamak() {}

bool Basamak::tekBasamakVarMi() const {
    return (deger >= 0 && deger <= 9);
}

