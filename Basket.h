//
// Created by Antonia on 12/4/2023.
//

#ifndef UNTITLED6_BASKET_H
#define UNTITLED6_BASKET_H

#ifndef BASKET_H
#define BASKET_H

#include <vector>
#include <memory>
#include <iostream>
#include "Magazin.h"

class Basket {
public:
    std::vector<std::shared_ptr<Magazin>> cumparaturi;

    void adaugaProdus(std::shared_ptr<Magazin> produs);

    void afisareCos() const;

    void aplicarePromotii();
};

#endif // BASKET_H


#endif //UNTITLED6_BASKET_H
