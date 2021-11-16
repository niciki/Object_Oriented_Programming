/*#include "Iterator.h"
#include "TNaryTree.h"
#include <memory>
#include <iostream>

template <class node, class T>
Iterator<node, T>::Iterator(std::shared_ptr<node> n){
    it = n;
}

template <class node, class T>
Iterator<node, T>& Iterator<node, T>::operator=(const Iterator<node, T>& it_){
    it = it_.it;
    return *this;
}

template <class node, class T>
bool Iterator<node,T>::operator==(const Iterator<node, T>& it_){
    return it == it_.it && tree = it_.tree;
}

template <class node, class T>
bool Iterator<node,T>::operator!=(const Iterator<node, T>& it_){
    return !(it == it_.it && tree = it_.tree);
}

template <class node, class T>
std::shared_ptr<T> Iterator<node, T>::operator*(){
    return it->data;
}

template <class node, class T>
Iterator<node, T>& Iterator<node, T>::operator++ (){
    it = it.Get_son();
    return *this;
}

template <class node, class T>
Iterator<node, T>& Iterator<node, T>::operator++ (int){
    Iterator tmp(*it);
    ++(*this);
    return it;
}

template <class node, class T>
Iterator<node, T>& Iterator<node, T>::operator-- (){
    it = it.Get_older();
    return *this;
}

template <class node, class T>
Iterator<node, T>& Iterator<node, T>::operator-- (int){
    Iterator tmp(*it);
    --(*this);
    return it;
}*/