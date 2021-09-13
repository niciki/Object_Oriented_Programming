#include "point.h"
#include "rectangle.h"
#include "rhombus.h"
#include "trapezoid.h"
#include "figure.h"

int main(){
    std::cout << "Please, enter coordinates of Rectangle\n";
    Rectangle a(std::cin);
    a.Print(std::cout);
    std::cout << a.Area() << "\n";
    std::cout << "Please, enter coordinates of Trapezoid\n"; 
    Trapezoid b(std::cin);
    b.Print(std::cout);
    std::cout << b.Area() << "\n";
    std::cout << "Please, enter coordinates of Rhombus\n";
    Rhombus c(std::cin);
    c.Print(std::cout);
    std::cout << c.Area() << "\n";
}