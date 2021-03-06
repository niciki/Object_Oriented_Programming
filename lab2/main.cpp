#include <iostream>
#include "TNaryTree_item.h"
#include "point.h"
#include "rectangle.h"
#include "figure.h"
#include "TNaryTree.h"

int main(){
    TNaryTree t(5);
    t.Update(Rectangle(Point(0, 0), Point(1, 0),Point(1, 1), Point(0, 1)), "");
    t.Update(Rectangle(Point(0, 0), Point(4, 0),Point(4, 1), Point(0, 1)), "b");
    t.Update(Rectangle(Point(0, 0), Point(4, 0),Point(4, 1), Point(0, 1)), "bb");
    t.Update(Rectangle(Point(0, 0), Point(4, 0),Point(4, 1), Point(0, 1)), "bbc");
    t.Update(Rectangle(Point(0, 0), Point(4, 0),Point(4, 1), Point(0, 1)), "c");
    std::cout << t.size() << "\n";
    std::cout << t.Area("") << "\n";
    std::cout << t.size() << "\n";
    TNaryTree q(t);
    std::cout << q.size() << " " << q.Area("") << "\n";
    std::cout << t << '\n' << q;
    // std::cout << q.root; //<< " " << q.root->bro << " " << q.root->bro->bro << " " << q.root->bro->son ;
    // std::cout << t.root << " " << t.root->bro << " " << t.root->bro->bro << " " << t.root->bro->son << "\n";
    // std::cout << t.root->bro->son << "\n";
    // delete (t.root);
    // t.root->bro->Print(std::cout);
    t.Clear("");
    std::cout << t.Area("") << "\n";
}