#ifndef ARETE_HPP
#define ARETE_HPP
#include <iostream>
#include <fstream>
#include <string>
#include <Sommet.hpp>
class Arete{
    private:
    Sommet* a;
    Sommet* b;
    int poid; 
    public:
    Arete(std::string a, std::string b,int p);
    Arete(Sommet* sa,Sommet* sb,int p);
    Arete(const Arete &ar);
    Sommet get1();
    Sommet get2();
    int getpoid();
    friend class GC;
    friend class Graphe;
};
std::ostream& operator<<(std::ostream& out, Arete &b);

#endif //ARETE_HPP
