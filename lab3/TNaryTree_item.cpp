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

void Item::Set(Rectangle a){
    data = a;
}

Item Item::Get_data(){
    return data;
}

std::shared_ptr<Item> Item::Get_bro(){
    return bro;
}

std::shared_ptr<Item> Item::Get_son(){
    return son;
}

Item::Item(std::shared_ptr<Item> a){
    bro = a->bro;
    son = a->son;
    data = a->data;
}

void Item::Print(std::ostream &os){
    os << data.Area();
}

void Item::Set_bro(std::shared_ptr<Item> bro_){
    bro = bro_;
}

void Item::Set_son(std::shared_ptr<Item> son_){
    son = son_;
}

double Item::Area(){
    return data.Area();
}

Item::~Item(){};