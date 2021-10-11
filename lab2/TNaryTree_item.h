#ifndef TNARYTREE_ITEM_H
#define TNARYTREE_ITEM_H

#include "rectangle.h"

class Item{
    public:
       Item* bro = nullptr;
       Item* son = nullptr;    
       Item(Point a_, Point b_, Point c_, Point d_);
       Item(Rectangle a);
       Item(Item* a);
       Item();
       void Print(std::ostream &os);
       double Area();
       ~Item();
    private:
        Rectangle data;     
};

#endif