#include <Graphe.hpp>

Graphe::Graphe(const Graphe &g){
    sommets=g.sommets;
    aretes=g.aretes;
}
Graphe::Graphe(std::vector<Sommet*> s, std::vector<Arete*> a){
    sommets=s;
    aretes=a;
}
Sommet* Graphe::ajoute_sommet(std::string s){
    Sommet* ret=new Sommet(s);
    sommets.push_back(ret);
    return ret;

}
void Graphe::ajoute_sommet(Sommet* s){
    sommets.push_back(s);
}
void Graphe::ajoute_arete(Arete* a){
    aretes.push_back(a);
    sommets.push_back(a->a);
    sommets.push_back(a->b);
}
Arete* Graphe::ajoute_arete(std::string a, std::string b, int poid){
    Arete* tmp=new Arete(a,b,poid);
    aretes.push_back(tmp);
    sommets.push_back(tmp->a);
    sommets.push_back(tmp->b);
    return tmp;
}
Arete* Graphe::ajoute_arete(Sommet* a,Sommet* b, int poids){
    Arete* tmp=new Arete(a,b,poids);
    aretes.push_back(tmp);
    sommets.push_back(tmp->a);
    sommets.push_back(tmp->b);
    return tmp;
}
int Graphe::poids(){
    int ret=0;
    for(auto a : aretes){
        ret+=a->getpoid();
    }
    return ret;
}
std::ostream& operator<<(std::ostream& out, Graphe &b){
    std::cout<<"Sommets:\n";
    for (auto s : b.sommets){
        std::cout<<*s;
    }
    std::cout<<"Aretes:\n";
    for (auto a: b.aretes){
        std::cout<<*a;
    }
    std::cout<<std::endl;
    return out;
}

