#include "point.h"
#include "rhombus.h"
#include <iostream>

Rhombus::Rhombus() : a(Point()), b(Point()), c(Point()), d(Point()) {
}

Rhombus::Rhombus(Point a_, Point b_, Point c_, Point d_) : a(a_), b(b_), c(c_), d(d_) {
}

Rhombus::Rhombus(std::istream& is){
    is >> a >> b >> c >> d;
}

void Rhombus::Print(std::ostream& os){
    os << a << " " << b << " " << c << " " << d << "\n";
}

size_t Rhombus::VertexesNumber(){
    return (size_t)(4);
}

double Rhombus::Area(){
    return a.dist(c) * b.dist(d) * 0.5;
}