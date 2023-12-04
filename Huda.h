//
// Created by Antonia on 12/4/2023.
//

#ifndef UNTITLED6_HUDA_H
#define UNTITLED6_HUDA_H


#include "Magazin.h"

class Huda : public Magazin {
public:
    std::wstring produs;
    std::wstring culoare;

    Huda(const std::wstring& produs_, const std::wstring& culoare_);

    std::wstring afisare() const override;
    void promotii(std::wstring tip_produs) override;
    std::shared_ptr<Magazin> clone() const override;
};




#endif //UNTITLED6_HUDA_H
