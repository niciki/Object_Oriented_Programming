#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"

class Rectangle: Figure {
    public:
        size_t VertexesNumber();
        double Area();
        void Print(std::ostream& os);
        Rectangle();
        Rectangle(Point a_, Point b_, Point c_, Point d_);
        Rectangle(std::istream& is);

        friend std::istream &operator>>(std::istream &is, Rectangle &figure);
        friend std::ostream &operator<<(std::ostream &os, const Rectangle &figure);

        ~Rectangle();

    private:
        Point a;
        Point b;
        Point c;
        Point d;
};

#endif