#include "rectangle.h"

double Rectangle::Area(){
    return a.dist(b) * b.dist(c);
}

void Rectangle::Print(std::ostream& os){
    os << a << " " << b << " " << c << " " << d << "\n";
}

size_t Rectangle::VertexesNumber(){
    return (size_t)(4);
}

Rectangle::Rectangle() : a(Point()), b(Point()), c(Point()), d(Point()){
}

Rectangle::Rectangle(Point a_, Point b_, Point c_, Point d_):
                                 a(a_), b(b_), c(c_), d(d_){
}

Rectangle::Rectangle(std::istream& is){
    is >> a >> b >> c >> d; 
}

std::istream &operator>>(std::istream &is, Rectangle &figure)
{
    is >> figure.a >> figure.b >> figure.c >> figure.d;
    return is;
}

std::ostream &operator<<(std::ostream &os, const Rectangle &figure)
{
    os << "Rectangle: " << figure.a << " " << figure.b << " " << figure.c << " " << figure.d;
    return os;
}

Rectangle::~Rectangle() {}