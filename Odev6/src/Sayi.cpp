#include "Sayi.hpp"
#include <iostream>


/** 
* @file : Odev6
* @description : Tek yönlü bağlı listeler kullanarak tam sayılar üzerinde çeşitli işlemler yaptırmak
* @course : 2.Öğretim A Grubu
* @assignment 1.Ödev
* @date : 19.11.2023
* @author : Feyza Ezber feyza.ezber@ogr.sakarya.edu.tr
*/


Sayi::Sayi() : basamakHead(nullptr), basamakTail(nullptr)  {}

Sayi::Sayi(int sayi) : basamakHead(nullptr), basamakTail(nullptr) {
    
    while (sayi != 0) {
        ekleBasamak(sayi % 10);
        sayi /= 10;
    }
}

void Sayi::ekleBasamak(int deger) {
    Basamak* yeniBasamak = new Basamak(deger);

    if (basamakHead == nullptr) {
        basamakHead = basamakTail = yeniBasamak;
    } else {
        basamakTail->sonraki = yeniBasamak;
        basamakTail = yeniBasamak;
    }
}

void Sayi::yazdir() const {
    Basamak* currentBasamak = basamakHead;
    while (currentBasamak != nullptr) {
        std::cout << currentBasamak->deger;
        currentBasamak = currentBasamak->sonraki;
    }
    std::cout << "\n " << "\n " << "\n ";
}


void Sayi::tekBasamaklariBasaAl() {
    Basamak* tekBasamaklar = nullptr;
    Basamak* current = basamakHead;
    Basamak* prev = nullptr;

    while (current != nullptr) {
        if (current->deger % 2 == 1) {
            if (prev == nullptr) {
                basamakHead = current->sonraki;
            } else {
                prev->sonraki = current->sonraki;
            }

            current->sonraki = tekBasamaklar;
            tekBasamaklar = current;

            current = (prev == nullptr) ? basamakHead : prev->sonraki;
        } else {
            prev = current;
            current = current->sonraki;
        }
    }

    current = tekBasamaklar;
    while (current != nullptr) {
        Basamak* temp = current->sonraki;
        current->sonraki = basamakHead;
        basamakHead = current;
        current = temp;
    }
}



void Sayi::basamaklariTersCevir() {
    Basamak* prev = nullptr;
    Basamak* current = basamakHead;
    Basamak* next = nullptr;

    while (current != nullptr) {
        next = current->sonraki;
        current->sonraki = prev;
        prev = current;
        current = next;
    }

    basamakHead = prev;
}

 int Sayi::enBuyukSayiyiBul() {
    if (basamakHead == nullptr) {
        throw std::runtime_error("Hata: Liste bos!");
    }

    int enBuyukSayi = 0;
    Basamak* current = basamakHead;

    while (current != nullptr) {
        enBuyukSayi = enBuyukSayi * 10 + current->deger;
        current = current->sonraki;
    }

    return enBuyukSayi;
} 

bool Sayi::tekBasamakVarMi() const {
    Basamak* currentBasamak = basamakHead;
    
    while (currentBasamak != nullptr) {
        if (currentBasamak->deger % 2 == 1) {
            return true;
        }
        currentBasamak = currentBasamak->sonraki;
    }

    return false;
}

Sayi::~Sayi() {}

