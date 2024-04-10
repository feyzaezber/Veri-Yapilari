#include <iostream>
#include <fstream> 
#include "SayilarListesi.hpp"

/** 
* @file : Odev6
* @description : Tek yönlü bağlı listeler kullanarak tam sayılar üzerinde çeşitli işlemler yaptırmak
* @course : 2.Öğretim A Grubu
* @assignment 1.Ödev
* @date : 19.11.2023
* @author : Feyza Ezber feyza.ezber@ogr.sakarya.edu.tr
*/



int main() {
    std::ifstream dosya("Sayilar.txt"); 

    if (!dosya.is_open()) {
        std::cerr << "Hata: Dosya acilamadi!" << std::endl;
        return 1; 
    }

    SayilarListesi sayilarListesi;

    int sayi;
    while (dosya >> sayi) {
        
        sayilarListesi.ekleSayi(Sayi(sayi));
         std::cout << sayi << "\n" << "\n " << "\n ";
    }
    

    int secim;
    do {
        
        std::cout << "\n--- MENU ---\n";
        std::cout << "1) Tek basamaklari basa al\n";
        std::cout << "2) Basamaklari ters cevir\n";
        std::cout << "3) En buyuk sayiyi yazdir\n";
        std::cout << "4) Cikis\n";
        std::cout << "Secim yapin: ";
        std::cin >> secim;

       
        switch (secim) {
            case 1:
                sayilarListesi.tekBasamaklariBasaAl();
                std::cout << "Tek basamaklar basa alindi.\n";
                sayilarListesi.ekranaYazdir();
                break;
            case 2:
                sayilarListesi.basamaklariTersCevir();
                std::cout << "Basamaklar ters cevrildi.\n";
                sayilarListesi.ekranaYazdir();
                break;
            case 3:
                std::cout << "En buyuk sayi: " << sayilarListesi.enBuyukSayiyiBul() << "\n";
                sayilarListesi.ekranaYazdir();
                break;
            case 4:
                std::cout << "Programdan cikiliyor.\n";
                break;
            default:
                std::cout << "Gecersiz secim! Tekrar deneyin.\n";
                break;
        }

    } while (secim != 4);

    return 0;
}