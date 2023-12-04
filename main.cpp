#include <iostream>
#include<vector>
#include<memory>
#include<map>
#include "Client.h"
#include "Basket.h"
#include "Dior.h"
#include "Fenty.h"
#include "Huda.h"
#include "Parfum.h"
#include "Parfum_info.h"
#include "Tip.h"

using namespace std;

/*
class Basket;

class Parfum_info;

class Client {
protected :
    std:: string name;
    int age;
public :
    //default constructor
    Client (std::string _name = "", double a = 0) : name(_name), age(a) {};
    virtual ~Client() {}
    virtual void citire(){ std::cin>>name>>age;}
    virtual std::wstring afisare () const {return L" ";}
};
// Clasa abstracta de baza pentru produsele din magazin
class Magazin {
public :
    std::wstring tip_produs;
    double pret;
    int stoc;

    //constructor
    Magazin(std::wstring _tip_produs = L"", double p = 0, int s = 0) : tip_produs(_tip_produs), pret(p), stoc(s) {}

    //destructor virtual pt polimorfism
    virtual ~Magazin() {}

//funtie virtuala pura pentru a aplica promotii
    virtual void promotii(std::wstring tip_produs)=0;

    virtual std::wstring afisare() const = 0;

//fct virtuala pt clonare
    virtual std::shared_ptr<Magazin> clone() const = 0;
};
class Dior : public Magazin
{
public :
    std::wstring produs;
    std::wstring culoare;

    Dior( const std::wstring& produs_, const std::wstring& culoare_ ) : produs(produs_),culoare(culoare_){}

    //funtie de suprascriere pt a afisa informatiile din produsele dior
    std::wstring  afisare() const override {return produs + L" " + culoare + L" " ; }

    void promotii(std::wstring tip_produs) override {
        std::cout << "Promotii pentru produsele Dior." << std::endl;
        if (tip_produs == L"lips") {
            try {
                if (pret / 2 < 0) {
                    throw std::runtime_error("Negative price after promotion");
                }
                pret /= 2;
                std::wcout << L"Reducere la jumatate pentru produsul Dior: " << produs << std::endl;
            } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
    }
    //fct de suprascriere pt clonarea obiectelor dior
    std::shared_ptr<Magazin> clone() const override {
        return std::make_shared<Dior>(*this);
    }
};
class Fenty: public Magazin
{
public :
    std::wstring produs;
    std::wstring culoare;
    Fenty( const std::wstring& produs_, const std::wstring& culoare_ ) : produs(produs_),culoare(culoare_){}
    std::wstring  afisare() const override {return produs + L" " + culoare + L" " ; }
    void promotii(std::wstring tip_produs) override {
        std::cout << "Promotii pentru produsele Fenty." << std::endl;
        if (tip_produs == L"eyes") {
            try {
                if (pret / 2 < 0) {
                    throw std::runtime_error("Negative price after promotion");
                }
                pret /= 2;
                std::wcout << L"Reducere la jumatate pentru produsul Fenty: " << produs << std::endl;
            } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
    }
    std::shared_ptr<Magazin> clone() const override {
        return std::make_shared<Fenty>(*this);
    }

};
class Huda : public Magazin
{ public:
    std::wstring produs;
    std::wstring culoare;
    Huda( const std::wstring& produs_, const std::wstring& culoare_ ) : produs(produs_),culoare(culoare_){}
    std::wstring  afisare() const override {return produs + L" " + culoare + L" " ; }
    void promotii(std::wstring tip_produs) override {
        std::cout << "Promotii pentru produsele Huda." << std::endl;
        if (tip_produs == L"lips") {
            try {
                if (pret / 2 < 0) {
                    throw std::runtime_error("Negative price after promotion");
                }
                pret /= 2;
                std::wcout << L"Reducere la jumatate pentru produsul Huda: " << produs << std::endl;
            } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
    }

    std::shared_ptr<Magazin> clone() const override {
        return std::make_shared<Huda>(*this);
    }

};
class Parfum : public Magazin{
public:
    std::wstring name;
    std::wstring scent;
    Parfum(const std::wstring& name_, const std::wstring& scent_, std::wstring _tip_produs =L"", double p = 0, int s = 0) : Magazin(_tip_produs, p, s), name{name_}, scent{scent_}{}
    friend class Parfum_info;
    std::wstring afisare() const override { return name + L" " + scent + L" "; }
    void promotii(std::wstring tip_produs) override {
        std::cout << " Nu estista Promotii pentru parfumuri." << std::endl;
    }

    std::shared_ptr<Magazin> clone() const override {
        return std::make_shared<Parfum>(*this);
    }
};
//clasa statica pt informatiile despre parfumuri
class Parfum_info {
public:
    // Functie pt a verifica daca 2 parfumuri au acelasi miros
    static bool haveSameScent(const std::shared_ptr<Parfum>& perfume1, const std::shared_ptr<Parfum>& perfume2) {
        return perfume1->scent == perfume2->scent;
    }
};
//clasa statica pentru a determina tipul produselor(fata,ochi,buze)
class Tip {
public:
    //functie pentru a det tipul folosind dynamic_pointer_cast
    static void getProductType(const shared_ptr<Magazin>& product)
    {
        if (auto diorProduct = dynamic_pointer_cast<Dior>(product)) {
            wcout << L"Dior Product: " << diorProduct->tip_produs << std::endl;

        } else if (auto fentyProduct = dynamic_pointer_cast<Fenty>(product)) {
            wcout << L"Fenty Product: " << fentyProduct->tip_produs << std::endl;

        } else if (auto hudaProduct = dynamic_pointer_cast<Huda>(product)) {
            wcout << L"Huda Product: " << hudaProduct->tip_produs << std::endl;

        } else {
            wcerr << L"Unknown Product Type" << std::endl;
        }
    }
};
//cos de cumparaturi
class Basket {
public:
    vector<shared_ptr<Magazin>> cumparaturi;
//functie pentru a adauga produse in cos
    void adaugaProdus(shared_ptr<Magazin>produs)
    {
        cumparaturi.push_back(produs);
    }

    void afisareCos() const {
        for (const auto& cumparat : cumparaturi) {
            std::wcout << cumparat->afisare() << L" - Pret: " << cumparat->pret << std::endl;
        }
    }

    void aplicarePromotii() {
        for (const auto& cumparat : cumparaturi) {
            cumparat->promotii(cumparat->tip_produs);
        }
    }
};*/

int main()
//vector de clienti
{
    vector<Client *> c;
    //map pt a asocia clientii cu cosurile lor de cumparaturi
    map<Client *, Basket> cosuri;
    int nr;
    cout << "dati un nr de clienti: ";
    cin >> nr;
    for (int i = 0; i < nr; i++) {
        double a;
        string n;
        cout << "Nume: ";
        cin >> n;
        cout << "Varsta: ";
        cin >> a;
        c.push_back(new Client(n, a));
        cosuri[c.back()] = Basket();
    }
    auto sp1 = make_shared<Dior>(L" ruj", L"roz");
    auto sp2 = make_shared<Dior>(L" ruj", L"mov");
    auto sp3 = make_shared<Fenty>(L" mascara", L"roz");
    auto sp4 = make_shared<Huda>(L" ruj", L"roz");
    auto sp5 = std::make_shared<Parfum>(L"Parfum1", L"Scent1");
    auto sp6 = std::make_shared<Parfum>(L"Parfum2", L"Scent2");

    sp1->tip_produs = L"lips";
    sp2->tip_produs = L"eyes";
    sp3->tip_produs = L"eyes";
    sp4->tip_produs = L"lips";
    sp5->tip_produs = L"scent";
    sp6->tip_produs = L"scent";

    sp1->pret = 50.0;
    sp2->pret = 30.0;
    sp3->pret = 40.0;
    sp4->pret = 55.0;
    sp5->pret = 75.0;
    sp6->pret = 80.0;

    //adauga produsele in cosul unui client

    cosuri[c[0]].adaugaProdus(sp1);
    cosuri[c[0]].adaugaProdus(sp2);
    cosuri[c[0]].adaugaProdus(sp3);
    cosuri[c[0]].adaugaProdus(sp5);
    cosuri[c[0]].adaugaProdus(sp6);

    wcout << L"Cosul pentru " << c[0]->afisare() << L"contine:" << endl;
    cosuri[c[0]].afisareCos();

    cosuri[c[0]].aplicarePromotii();

    wcout << L"Cosul dupa aplicarea promotiilor:" << endl;
    cosuri[c[0]].afisareCos();

    for (auto client: c) {
        delete client;
    }
    if (Parfum_info::haveSameScent(std::dynamic_pointer_cast<Parfum>(sp5), std::dynamic_pointer_cast<Parfum>(sp6))) {
        std::cout << "The two perfumes have the same scent." << std::endl;
    } else {
        std::cout << "The two perfumes have different scents." << std::endl;
    }
    auto clonedDior = sp1->clone();
    std::wcout << L"Cloned Dior: " << clonedDior->afisare() << std::endl;

    auto clonedFenty = sp3->clone();
    std::wcout << L"Cloned Fenty: " << clonedFenty->afisare() << std::endl;

    auto clonedHuda = sp4->clone();
    std::wcout << L"Cloned Huda: " << clonedHuda->afisare() << std::endl;

    auto clonedParfum = sp5->clone();
    std::wcout << L"Cloned Parfum: " << clonedParfum->afisare() << std::endl;


    return 0;
}