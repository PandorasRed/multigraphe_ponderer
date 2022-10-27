#include <main.hpp>

int main(){
    Sommet* a=new Sommet("bloup");
    auto b=new Sommet("test");
    auto c=new Arete(a,b,20);
    auto d=new Arete(b,a,30);
    std::vector<Sommet*> tmp;
    std::vector<Arete*> tmp2;
    tmp.push_back(a);
    tmp.push_back(b);
    tmp2.push_back(c);
    tmp2.push_back(d);
    Graphe test=Graphe(tmp,tmp2);
    std::cout<<test<<std::endl;
    GC collector=GC();
    collector.add_sommet(a);
    collector.add_arete(c); 
}