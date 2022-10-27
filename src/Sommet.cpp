#include <Sommet.hpp>

Sommet::Sommet(std::string st){
    id=st;
    marque=0;
}

Sommet::Sommet(const Sommet &s){
    id=s.id;
    marque=s.marque;
}
std::string Sommet::get(){
    return id;
}
std::ostream& operator<<(std::ostream& out, Sommet &b){
    out<<""<<b.get()<<std::endl;
    return out;
}
