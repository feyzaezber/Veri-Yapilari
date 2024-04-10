#ifndef Basamak_hpp
#define Basamak_hpp


class Basamak {
public:
    int deger;
    Basamak* sonraki;

    Basamak(int deger);
	
	~Basamak() ;
	
    bool tekBasamakVarMi() const;
	
	
};


#endif