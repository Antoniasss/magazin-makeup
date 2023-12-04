//
// Created by Antonia on 12/4/2023.
//

#ifndef UNTITLED6_PARFUM_INFO_H
#define UNTITLED6_PARFUM_INFO_H


#include <memory>

class Parfum; // Forward declaration to resolve circular dependency

class Parfum_info {
public:
    static bool haveSameScent(const std::shared_ptr<Parfum>& perfume1, const std::shared_ptr<Parfum>& perfume2);
};



#endif //UNTITLED6_PARFUM_INFO_H
