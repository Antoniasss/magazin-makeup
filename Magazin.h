//
// Created by Antonia on 12/4/2023.
//

#ifndef UNTITLED6_MAGAZIN_H
#define UNTITLED6_MAGAZIN_H

#include <string>
#include <memory>

class Magazin {
public:
    std::wstring tip_produs;
    double pret;
    int stoc;

    Magazin(std::wstring _tip_produs = L"", double p = 0, int s = 0);
    virtual ~Magazin();  // Declare the destructor as virtual since you have virtual methods

    virtual void promotii(std::wstring tip_produs) = 0;
    virtual std::wstring afisare() const = 0;
    virtual std::shared_ptr<Magazin> clone() const = 0;
};



#endif //UNTITLED6_MAGAZIN_H
