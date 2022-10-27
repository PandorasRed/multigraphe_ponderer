#include <Arete.hpp>

Arete::Arete(std::string sa, std::string sb,int poid){
    a=new Sommet(sa);
    b=new Sommet(sb);
    poid=poid;
}
Arete::Arete(Sommet* sa,Sommet *sb,int p){
    a=sa;
    b=sb;
    poid=p;
}
Arete::Arete(const Arete &ar){
    a=ar.a;
    b=ar.b;
    poid=ar.poid;
}
Sommet Arete::get1(){
    return *a;
}
Sommet Arete::get2(){
    return *b;
}
int Arete::getpoid(){
    return poid;
}
std::ostream& operator<<(std::ostream& out, Arete &b){
    out<<b.get1().get()<<" " <<b.get2().get()<<" "<<b.getpoid()<<std::endl;
    return out;
}

