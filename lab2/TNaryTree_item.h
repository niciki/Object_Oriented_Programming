#ifndef TNARYTREE_ITEM_H
#define TNARYTREE_ITEM_H

#include "rectangle.h"

class Item{
    public:  
       Item(Point a_, Point b_, Point c_, Point d_);
       Item(Rectangle a);
       Item(Item* a);
       Item();
       void Print(std::ostream &os);
       Item* Get_bro();
       Item* Get_son();
       void Set_bro(Item* a);
       void Set_son(Item* a);
       double Area();
       ~Item();
    private:
        Item* bro = nullptr;
        Item* son = nullptr;  
        Rectangle data;     
};

#endif