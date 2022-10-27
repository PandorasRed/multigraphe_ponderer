#ifndef GC_HPP
#define GC_HPP
#include <iostream>
#include <fstream>
#include <string>
#include <Sommet.hpp>
#include <Arete.hpp>
#include <unordered_set>
#include <vector>
class GC{
    private:
    std::vector<Sommet*> sommets;
    std::vector<Arete*> aretes;
    public:
    GC();
    ~GC();
    void add_arete(Arete* a);
    void add_sommet(Sommet* a);
};

#endif //GC_HPP
