//
// Created by Antonia on 12/4/2023.
//

#include "Fenty.h"
#include <iostream>
#include <stdexcept>

Fenty::Fenty(const std::wstring& produs_, const std::wstring& culoare_) : produs(produs_), culoare(culoare_) {}

std::wstring Fenty::afisare() const {
    return produs + L" " + culoare + L" ";
}

void Fenty::promotii(std::wstring tip_produs) {
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

std::shared_ptr<Magazin> Fenty::clone() const {
    return std::make_shared<Fenty>(*this);
}

