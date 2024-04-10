#include "SayilarListesi.hpp"
#include <iostream>
#include <limits>


/** 
* @file : Odev6
* @description : Tek yönlü bağlı listeler kullanarak tam sayılar üzerinde çeşitli işlemler yaptırmak
* @course : 2.Öğretim A Grubu
* @assignment 1.Ödev
* @date : 19.11.2023
* @author : Feyza Ezber feyza.ezber@ogr.sakarya.edu.tr
*/

SayilarListesi::SayilarListesi() : dugumHead(nullptr) {}

void SayilarListesi::ekleSayi(const Sayi& sayi) {
    Dugum* yeniDugum = new Dugum(sayi);
    yeniDugum->sonraki = dugumHead;
    dugumHead = yeniDugum;
}

void SayilarListesi::yazdir() {
    Dugum* currentDugum = dugumHead;
    while (currentDugum != nullptr) {
        currentDugum->sayi.yazdir();
        currentDugum = currentDugum->sonraki;
    }
}

void SayilarListesi::tekBasamaklariBasaAl() {
    Dugum* currentDugum = dugumHead;

    while (currentDugum != nullptr) {
 
        currentDugum->sayi.tekBasamaklariBasaAl();

        currentDugum = currentDugum->sonraki;
    }
}

void SayilarListesi::basamaklariTersCevir() {
    Dugum* prevDugum = nullptr;
    Dugum* currentDugum = dugumHead;
    Dugum* nextDugum = nullptr;

    while (currentDugum != nullptr) {
        nextDugum = currentDugum->sonraki;
        currentDugum->sonraki = prevDugum;
        prevDugum = currentDugum;
        currentDugum = nextDugum;
    }

    dugumHead = prevDugum;
}

 int SayilarListesi::enBuyukSayiyiBul() {
    if (dugumHead == nullptr) {
        throw std::runtime_error("Hata: Liste bos!");
    }

    int enBuyukSayi = dugumHead->sayi.enBuyukSayiyiBul();
    Dugum* currentDugum = dugumHead->sonraki;

    while (currentDugum != nullptr) {
        int currentSayi = currentDugum->sayi.enBuyukSayiyiBul();
        if (currentSayi > enBuyukSayi) {
            enBuyukSayi = currentSayi;
        }
        currentDugum = currentDugum->sonraki;
    }

    return enBuyukSayi;
} 



void SayilarListesi::ekranaYazdir() const {
	 Dugum* currentDugum = dugumHead;
    while (currentDugum != nullptr) {
        
        std::cout << this << " ";
		
		
		Basamak* currentBasamak = currentDugum->sayi.getBasamakHead();
        while (currentBasamak != nullptr) {
            
            // Basamağın adresinin son üç basamağını elde et
            std::string basamakAdres = std::to_string(reinterpret_cast<uintptr_t>(currentBasamak));
            if (basamakAdres.length() > 3) {
                basamakAdres = basamakAdres.substr(basamakAdres.length() - 3);
            }

            std::cout << "    *" << basamakAdres << "* ";
            currentBasamak = currentBasamak->sonraki;
        }
        std::cout << "\n";

       
        std::cout <<  currentDugum->sayi.enBuyukSayiyiBul() << "           ";
        currentBasamak = currentDugum->sayi.getBasamakHead();
        while (currentBasamak != nullptr) {
            
            std::cout << currentBasamak->deger << "         ";
            currentBasamak = currentBasamak->sonraki;
        }
        std::cout << "\n\n";

        currentDugum = currentDugum->sonraki;
    } 
	
	
	
	
	
}