#include "TNaryTree_item.h"

Item::Item(Point a_, Point b_, Point c_, Point d_){
    data = Rectangle(a_, b_, c_, d_);
}

Item::Item(){
    data = Rectangle();
}

Item::Item(Rectangle a){
    data = a;
}

Item::Item(Item* a){
    bro = a->bro;
    son = a->son;
    data = a->data;
}

Item* Item::Get_bro(){
    return bro;
}

Item* Item::Get_son(){
    return son;
}

void Item::Set_bro(Item* a){
    bro = a;
}

void Item::Set_son(Item* a){
    son = a;
}

void Item::Print(std::ostream &os){
    os << data.Area();
}

double Item::Area(){
    return data.Area();
}

Item::~Item(){};