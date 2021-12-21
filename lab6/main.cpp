#include "TNaryTree.h"
#include "rectangle.h"
#include "Iterator.h"
#include <unistd.h>

int main(void){
    TNaryTree<Rectangle> t(9);
    t.Update(Rectangle(Point(0, 0), Point(1, 0),Point(1, 1), Point(0, 1)), "");
    t.Update(Rectangle(Point(0, 0), Point(6, 0),Point(6, 1), Point(0, 1)), "c");
    t.Update(Rectangle(Point(0, 0), Point(3, 0),Point(3, 1), Point(0, 1)), "cc");
    t.Update(Rectangle(Point(0, 0), Point(2, 0),Point(2, 1), Point(0, 1)), "cb");
    t.Update(Rectangle(Point(0, 0), Point(4, 0),Point(4, 1), Point(0, 1)), "cbc");
    t.Update(Rectangle(Point(0, 0), Point(9, 0),Point(9, 1), Point(0, 1)), "cbcc");
    t.Update(Rectangle(Point(0, 0), Point(5, 0),Point(5, 1), Point(0, 1)), "b");
    t.Update(Rectangle(Point(0, 0), Point(7, 0),Point(7, 1), Point(0, 1)), "cbcb");
    t.Update(Rectangle(Point(0, 0), Point(8, 0),Point(8, 1), Point(0, 1)), "cbcbb");
    std::cout << *(t.Tree_root()->Get_bro());
    std::cout << t.size() << "\n";
    std::cout << t.Area("") << "\n";
    std::cout << t.size() << "\n";
    std::cout << t;
    TNaryTree<Rectangle> q(t);
    t.Clear();
    std::cout << q.size() << " " << q.Area("") << "\n";
    std::cout << q;
    //std::cout << q.Tree_root()->Get_data() << "\n";
    for(auto i: q){
        std::cout << i.Area() << " ";
        //sleep(1); 
    }
    std::cout << "\n";
    //std::cout << (q.Tree_root()->Get_older()->Get_bro());
    return 0;
}
