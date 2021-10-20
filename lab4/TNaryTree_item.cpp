#include "TNaryTree_item.h"
#include <iostream>

template <class T>
Item<T>::Item() {
    data = T();
}

template <class T>
Item<T>::Item(T a){
    data = a;
}

template <class T>
void Item<T>::Set(T a){
    data = a;
}

template <class T>
Item<T> Item<T>::Get_data(){
    return data;
}

template <class T>
std::shared_ptr<Item<T>> Item<T>::Get_bro(){
    return bro;
}

template <class T>
std::shared_ptr<Item<T>> Item<T>::Get_son(){
    return son;
}

template <class T>
Item<T>::Item(std::shared_ptr<Item<T>> a){
    bro = a->bro;
    son = a->son;
    data = a->data;
}

template <class T>
void Item<T>::Print(std::ostream &os){
    os << data.Area();
}

template <class T>
void Item<T>::Set_bro(std::shared_ptr<Item<T>> bro_){
    bro = bro_;
}

template <class T>
void Item<T>::Set_son(std::shared_ptr<Item<T>> son_){
    son = son_;
}

template <class T>
double Item<T>::Area(){
    return data.Area();
}

template <class T>
std::ostream &operator<<(std::ostream &os, const Item<T> &obj)
{
    os << "Item: " << obj.data << std::endl;
    return os;
}

template <class T>
Item<T>::~Item() {};

#include "rectangle.h"
template class Item<Rectangle>;
template std::ostream& operator<<(std::ostream& os, const Item<Rectangle> &obj);