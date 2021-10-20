#include "TNaryTree_item.h"

template <typename T>
Item<T>::Item(){
    data = T();
}

template <typename T>
Item<T>::Item(T a){
    data = a;
}

template <typename T>
void Item<T>::Set(T a){
    data = a;
}

template <typename T>
Item<T> Item<T>::Get_data(){
    return data;
}

template <typename T>
std::shared_ptr<Item<T>> Item<T>::Get_bro(){
    return bro;
}

template <typename T>
std::shared_ptr<Item<T>> Item<T>::Get_son(){
    return son;
}

template <typename T>
Item<T>::Item(std::shared_ptr<Item<T>> a){
    bro = a->bro;
    son = a->son;
    data = a->data;
}

template <typename T>
void Item<T>::Print(std::ostream &os){
    os << data.Area();
}

template <typename T>
void Item<T>::Set_bro(std::shared_ptr<Item<T>> bro_){
    bro = bro_;
}

template <typename T>
void Item<T>::Set_son(std::shared_ptr<Item<T>> son_){
    son = son_;
}

template <typename T>
double Item<T>::Area(){
    return data.Area();
}

template <typename T>
Item<T>::~Item(){};