#include <iostream>

struct A {
    int a;
};

int main() {
    std::move(A{2}) = A{8};
}