//
// Created by Antonia on 12/4/2023.
//

#include "Tip.h"
#include "Dior.h"
#include "Fenty.h"
#include "Huda.h"
#include <iostream>

void Tip::getProductType(const std::shared_ptr<Magazin> &product) {
    if (auto diorProduct = std::dynamic_pointer_cast<Dior>(product)) {
        std::wcout << "Dior Product: " << diorProduct->tip_produs << std::endl;
    } else if (auto fentyProduct = std::dynamic_pointer_cast<Fenty>(product)) {
        std::wcout << "Fenty Product: " << fentyProduct->tip_produs << std::endl;
    } else if (auto hudaProduct = std::dynamic_pointer_cast<Huda>(product)) {
        std::wcout << "Huda Product: " << hudaProduct->tip_produs << std::endl;

    } else {
        std::wcerr << "Unknown Product Type" << std::endl;
    }
}

