#ifndef ITERATOR_H
#define ITERATOR_H

#include "TNaryTree.h"
#include <iostream>

template <class node, class T>
class Iterator{
    public:
        Iterator(std::shared_ptr<node> n){
            it = n;
            it_prev = nullptr;
        }
        Iterator& operator=(const Iterator& it_){
            it = it_.it;
            return *this;
        }
        bool operator==(const Iterator& it_){
            return it == it_.it;
        }
        bool operator!=(const Iterator& it_){
            return !(it == it_.it);
        }
        node operator*(){
            return it->Get_data();
        }
        Iterator& operator++ (){
            if(it->Get_son() != nullptr && it_prev != it->Get_bro()){
                it_prev = it;
                it = it->Get_son();
            } else if (it->Get_bro() != nullptr && it_prev != it->Get_bro()){
                it_prev = it;
                it = it->Get_bro();
            } else {
                while(it->Get_bro() == nullptr || (it->Get_bro() == it_prev)){
                    it_prev = it;
                    if(it->Get_older() == nullptr){
                        return *this;
                    }
                    it = it->Get_older();
                }
                if(it->Get_bro() == nullptr && it->Get_son() == it_prev){
                    it_prev = it;
                    it = it->Get_older();
                    if(it->Get_older() == nullptr){
                        return *this;
                    }
                    if(it->Get_bro() == nullptr){
                        while(it->Get_bro() == nullptr){
                            it_prev = it;
                            it = it->Get_older();
                        }
                        it_prev = it;
                        it = it->Get_bro();
                    } else {
                    it = it->Get_bro();
                    }  
                } else {
                    it = it->Get_bro();
                }
            }
            return *this;
        }
        Iterator& operator++ (int){
            Iterator tmp(*it);
            ++(*this);
            return it;
        }
        Iterator& operator-- (){
            it = it.Get_older();
            return *this;
        }
        Iterator& operator-- (int){
            Iterator tmp(*it);
            --(*this);
            return it;
        }
    public:
        std::shared_ptr<node> it_prev;
        std::shared_ptr<node> it;
};

#endif