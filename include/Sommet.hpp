#ifndef SOMMET_HPP
#define SOMMET_HPP
#include <iostream>
#include <fstream>
#include <string>
class Sommet{
    private:
    std::string id;
    int marque;
    public:
    Sommet(std::string st);
    Sommet(const Sommet &s);
    std::string get();
};
std::ostream& operator<<(std::ostream& out, Sommet &b);

#endif //SOMMET_HPP
