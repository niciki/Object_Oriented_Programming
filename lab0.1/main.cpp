#include <iostream>
#include "adress.h"

using namespace std;

int main(){
    Adress a("Moscow", "Tverskaya", 4, 5);
    Adress b("Moscow", "Tverskaya", 5, 100);
    Adress c("Moscow", "Petrovskaya", 13, 56);
    Adress d("Moscow", "Tverskaya", 4, 5);
    cout << a << "\n" << b.is_near(a) << "\n" << (a == b) << "\n" << (a == d) << "\n" << b.adress_to_route("Tverskaya") << "\n";
}
