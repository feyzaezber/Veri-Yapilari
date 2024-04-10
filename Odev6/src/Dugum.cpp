#include "Dugum.hpp"
#include "Sayi.hpp"

/** 
* @file : Odev6
* @description : Tek yönlü bağlı listeler kullanarak tam sayılar üzerinde çeşitli işlemler yaptırmak
* @course : 2.Öğretim A Grubu
* @assignment 1.Ödev
* @date : 19.11.2023
* @author : Feyza Ezber feyza.ezber@ogr.sakarya.edu.tr
*/


Dugum::~Dugum() {}

Dugum::Dugum(const Sayi& sayi) : sayi(sayi), sonraki(nullptr) {}

