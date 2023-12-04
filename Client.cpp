//
// Created by Antonia on 12/4/2023.
//

#include "Client.h"
#include <iostream>

Client::Client(std::string _name, double a) : name(_name), age(a) {}

void Client::citire() {
    std::cin >> name >> age;
}

std::wstring Client::afisare() const {
    return L" ";
}

