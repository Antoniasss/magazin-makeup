//
// Created by Antonia on 12/4/2023.
//

#ifndef UNTITLED6_PARFUM_H
#define UNTITLED6_PARFUM_H

#include "Magazin.h"

class Parfum : public Magazin {
public:
    std::wstring name;
    std::wstring sent;

    Parfum(const std::wstring& name_, const std::wstring& sent_, std::wstring _tip_produs = L"", double p = 0, int s = 0);

    std::wstring afisare() const override;
    void promotii(std::wstring tip_produs) override;
    std::shared_ptr<Magazin> clone() const override;
};







#endif //UNTITLED6_PARFUM_H
