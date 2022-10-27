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
    aretes.push_back(a);
    bool c=false,b=false;

    for(auto s:sommets){
        if(s==a->a){
            c=true;
        }
        if(s==a->b){
            b=true;
        }
    }
    if(!b){
        add_sommet(a->b);
        std::cout<<"dernier"<<std::endl;
    }if(!c){
        add_sommet(a->a);
                std::cout<<"premier"<<std::endl;

    }
}
void GC::add_sommet(Sommet* s){
    sommets.push_back(s);
}

