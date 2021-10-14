#ifndef TNARYTREE_ITEM_H
#define TNARYTREE_ITEM_H

#include "rectangle.h"
#include <memory>

class Item{
    public:
       std::shared_ptr<Item> bro = nullptr;
       std::shared_ptr<Item> son = nullptr;    
       Item(Point a_, Point b_, Point c_, Point d_);
       Item(Rectangle a);
       Item(std::shared_ptr<Item> a);
       Item();
       void Print(std::ostream &os);
       double Area();
       ~Item();
    private:
        Rectangle data;     
};

#endif