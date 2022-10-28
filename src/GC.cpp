#include <GC.hpp>
GC::GC(){
    aretes=std::vector<Arete*>();
    sommets=std::vector<Sommet*>();
}
GC::~GC(){
    for(auto a: aretes){
        delete a;
    }
    for(auto b: sommets){
        delete b;
    }
}

void GC::add_arete(Arete* a){
    bool c=true;
    for(auto a2:aretes){
        if(a2==a){
            c=false;
            break;
        }
    }
    if(c){
        aretes.push_back(a);
        add_sommet(a->b);
        add_sommet(a->a);
    }
}
void GC::add_sommet(Sommet* s){
    bool c=true;
    for(auto s2:sommets){
        if(s==s2){
            c=false;
            break;
        }
    }
    if(c){
            sommets.push_back(s);
    }
}

