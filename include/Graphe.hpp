#ifndef GRAPHE_HPP
#define GRAPHE_HPP
#include <iostream>
#include <Arete.hpp>
#include <fstream>
#include <string>
#include <Sommet.hpp>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <functional>
class Graphe{
    private:
    std::vector<Sommet*> sommets;
    std::vector<Arete*> aretes;
    bool sym;
    public:
    Graphe(const Graphe &g);
    Graphe(std::vector<Sommet*> s, std::vector<Arete*> a);
    void ajoute_sommet(Sommet* s);
    Sommet* ajoute_sommet(std::string s);
    void ajoute_arete(Arete* a);
    Arete* ajoute_arete(std::string a,std::string b, int poids);
    Arete* ajoute_arete(Sommet* a, Sommet* b, int poid);
    int poids();
    std::vector<Arete*> symetrise();
    friend std::ostream& operator<<(std::ostream& out, Graphe &b);
    std::vector<Arete*> kruskal();

    
};
std::ostream& operator<<(std::ostream& out, Graphe &b);

#endif //GRAPHE_HPP
