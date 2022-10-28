#include <main.hpp>

int main(){
    Sommet* a=new Sommet("bloup");
    auto b=new Sommet("test");
    auto f=new Sommet("test2");
    auto c=new Arete(a,b,20);
    auto d=new Arete(b,f,30);
    auto e=new Arete("A","B",100);
    auto g=new Arete(f,a,200);
    std::vector<Sommet*> tmp;
    std::vector<Arete*> tmp2;
    tmp.push_back(a);
    tmp2.push_back(c);
    tmp2.push_back(e);
    tmp2.push_back(g);
    Graphe test=Graphe(tmp,tmp2);
    test.ajoute_arete(d);
    auto ta=test.symetrise();
    auto p=test.kruskal();
    for(auto p2:p){
        std::cout<<*p2<<std::endl;
    }
    std::cout<<test<<std::endl;
    GC collector=GC();
    for(auto tmpa : ta){
        collector.add_arete(tmpa);
    }

    collector.add_sommet(a);
    collector.add_arete(c); 
    collector.add_arete(e);
    collector.add_arete(d);
}