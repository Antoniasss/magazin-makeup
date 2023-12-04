//
// Created by Antonia on 12/4/2023.
//

#include "Parfum.h"
#include "Parfum_info.h"
#include <memory>

bool Parfum_info::haveSameScent(const std::shared_ptr<Parfum>& perfume1, const std::shared_ptr<Parfum>& perfume2) {
    return perfume1->sent == perfume2->sent;
}

