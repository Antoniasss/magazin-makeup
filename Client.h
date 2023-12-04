//
// Created by Antonia on 12/4/2023.
//

#ifndef UNTITLED6_CLIENT_H
#define UNTITLED6_CLIENT_H


#include <string>

class Client {
protected:
    std::string name;
    int age;

public:
    Client(std::string _name = "", double a = 0);

    virtual ~Client() {}

    virtual void citire();
    virtual std::wstring afisare() const;
};



#endif //UNTITLED6_CLIENT_H
