//
// Created by Antonia on 12/4/2023.
//

#include "Huda.h"
#include <iostream>
#include <stdexcept>

Huda::Huda(const std::wstring& produs_, const std::wstring& culoare_) : produs(produs_), culoare(culoare_) {}

std::wstring Huda::afisare() const {
    return produs + L" " + culoare + L" ";
}

void Huda::promotii(std::wstring tip_produs) {
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

std::shared_ptr<Magazin> Huda::clone() const {
    return std::make_shared<Huda>(*this);
}

