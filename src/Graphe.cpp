#include <Graphe.hpp>

Graphe::Graphe(const Graphe &g){
    sommets=g.sommets;
    aretes=g.aretes;
    sym=g.sym;
}
Graphe::Graphe(std::vector<Sommet*> s, std::vector<Arete*> a){
    sommets=s;
    aretes=a;
    sym=false;
}
Sommet* Graphe::ajoute_sommet(std::string s){
    Sommet* ret=new Sommet(s);
    sommets.push_back(ret);
    return ret;

}
void Graphe::ajoute_sommet(Sommet* s){
    bool c=true;
    for(auto s2:sommets){
        if(s==s2){
            c=false;
        }
    }
    if(c){
        sommets.push_back(s);
    }
}
void Graphe::ajoute_arete(Arete* a){
    aretes.push_back(a);
    bool c=true,d=true;
    for(auto s:sommets){
        if(s==a->a){
            c=false;
        }
        if(s==a->b){
            d=false;
        }
    }
    if(c){
        sommets.push_back(a->a);
    }
    if(d){
        sommets.push_back(a->b);
    }
    sym=false;
}
Arete* Graphe::ajoute_arete(std::string a, std::string b, int poid){
    Arete* tmp=new Arete(a,b,poid);
    bool c=true,d=true;
    for(auto s:sommets){
        if(s==tmp->a){
            c=false;
        }
        if(s==tmp->b){
            d=false;
        }
    }
    if(c){
        sommets.push_back(tmp->a);
    }
    if(d){
        sommets.push_back(tmp->b);
    }
    sym=false;
    return tmp;
    
}
Arete* Graphe::ajoute_arete(Sommet* a,Sommet* b, int poids){
    Arete* tmp=new Arete(a,b,poids);
    aretes.push_back(tmp);
    bool c=true,d=true;
    for(auto s:sommets){
        if(s==tmp->a){
            c=false;
        }
        if(s==tmp->b){
            d=false;
        }
    }
    if(c){
        sommets.push_back(tmp->a);
    }
    if(d){
        sommets.push_back(tmp->b);
    }
    sym=false;
    return tmp;
}
int Graphe::poids(){
    int ret=0;
    for(auto a : aretes){
        ret+=a->getpoid();
    }
    if(sym){
        return ret/2;
    }
    return ret;
}
/**
 * @brief symetrise les arc, si jamais deux arc entre deux sommet n'ont pas le meme point en choisit un arbitrairement et applique sa valeur a l'autre arc
 * 
 */
std::vector<Arete*> Graphe::symetrise(){
    std::vector<Arete*> ret;
    std::cout<<std::endl;
    for(auto a : aretes){
        bool b=false;//pour savoir si un arc "inverse" existe 
        for(auto a2:aretes){
            b=(a2->a==a->b && a2->b==a->a);
            if(b){//arc inverse trouvé,normalisation de son poid;
                if(a2->poid!=a->poid){
                    a2->poid=a->poid;
                }
                break;
            }
        }
        if(!b){
            Arete* tmp=new Arete(a->b,a->a,a->poid);
        //     auto tmp=ajoute_arete(a->b,a->a,a->poid);//pas faire ca sinon il essaie d'iterer dessus derrière et ca fait des segfault
            ret.push_back(tmp);
        }
    }
    for(auto r: ret){
        ajoute_arete(r);
    }
    sym=true;
    return ret;
}
std::vector<Arete*> Graphe::kruskal(){
    std::vector<Arete*> ret;
    std::sort(aretes.begin(), aretes.end(), [](Arete* a, Arete* b) {
        return a->getpoid()< b->getpoid();
    });
    for (unsigned int i=0;i<sommets.size();i++){
        sommets[i]->marque=i;
    }
    for(auto a: aretes){
        if(a->a->marque!=a->b->marque){
            a->b->marque=a->a->marque;
            ret.push_back(a);
        }
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
    std::cout<<"poid total : "<<b.poids()<<std::endl;
    return out;
}

