#ifndef TNARYTREE_ITEM_H
#define TNARYTREE_ITEM_H

#include "rectangle.h"
#include <memory>

template <typename T>
class Item{
    public: 
       Item(T a);
       Item(std::shared_ptr<Item<T>> a);
       Item();
       void Set(T a);
       void Set_bro(std::shared_ptr<Item<T>> bro_);
       void Set_son(std::shared_ptr<Item<T>> son_);
       Item Get_data();
       std::shared_ptr<Item<T>> Get_bro();
       std::shared_ptr<Item<T>> Get_son();
       void Print(std::ostream &os);
       double Area();
       ~Item();
    private:
        std::shared_ptr<Item<T>> bro = nullptr;
        std::shared_ptr<Item<T>> son = nullptr; 
        T data;     
};

#endif