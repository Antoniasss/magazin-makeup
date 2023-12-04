//
// Created by Antonia on 12/4/2023.
//

#include "Dior.h"
#include <iostream>
#include <stdexcept>

Dior::Dior(const std::wstring& produs_, const std::wstring& culoare_) : produs(produs_), culoare(culoare_) {}

std::wstring Dior::afisare() const {
    return produs + L" " + culoare + L" ";
}

void Dior::promotii(std::wstring tip_produs) {
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

std::shared_ptr<Magazin> Dior::clone() const {
    return std::make_shared<Dior>(*this);
}

