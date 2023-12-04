//
// Created by Antonia on 12/4/2023.
//

#include "Basket.h"
#include <iostream>

void Basket::adaugaProdus(std::shared_ptr<Magazin> produs) {
    cumparaturi.push_back(produs);
}

void Basket::afisareCos() const {
    for (const auto& cumparat : cumparaturi) {
        std::wcout << cumparat->afisare() << L" - Pret: " << cumparat->pret << std::endl;
    }
}

void Basket::aplicarePromotii() {
    for (const auto& cumparat : cumparaturi) {
        cumparat->promotii(cumparat->tip_produs);
    }
}

