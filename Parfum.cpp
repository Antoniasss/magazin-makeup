//
// Created by Antonia on 12/4/2023.
//

#include "Parfum.h"
#include <iostream>

Parfum::Parfum(const std::wstring& name_, const std::wstring& sent_, std::wstring _tip_produs, double p, int s)
        : Magazin(_tip_produs, p, s), name{name_}, sent{sent_} {}

std::wstring Parfum::afisare() const {
    return name + L" " + sent + L" ";
}

void Parfum::promotii(std::wstring tip_produs) {
    std::cout << " Nu exista Promotii pentru parfumuri." << std::endl;
}

std::shared_ptr<Magazin> Parfum::clone() const {
    return std::make_shared<Parfum>(*this);
}

