//
// Created by Antonia on 12/4/2023.
//

#ifndef UNTITLED6_TIP_H
#define UNTITLED6_TIP_H


#include <memory>
#include "Magazin.h"

class Tip {
public:
    static void getProductType(const std::shared_ptr<Magazin> &product);
};


#endif //UNTITLED6_TIP_H
