#ifndef VECTOR_H
#define VECTOR_H

#include "TVector_item.h"
#include <memory>
#include <iostream>

template<typename T> 
class Vector{
    public:
        Vector(): length(0), head(nullptr) {};
        void push_back(T t){
            if(length == 0){
                head = std::make_shared<Vector_item<T>>(new(Vector_item<T>));
            } else {
                Vector_item<T> tmp;
                while(tmp.Get_next() != nullptr){
                    tmp = *tmp.Get_next();
                }
            }
            ++length;
        }
        int size() const {
            return length;
        }
        void erase(int ind){
            while(ind--){
                head = head->Get_next();
            }
            if(length > 0){
                --length;
            } else {
                std::cout << "Error in delete element from vector!\n";
            }
        }
        std::shared_ptr<Vector_item<T>> Get_first(){
            return head;
        }
    private:
        std::shared_ptr<Vector_item<T>> head;
        int length;
};

#endif