#include <iostream>
#include "adress.h"

using namespace std;

Adress operator""_city(const char* s, std::size_t n){
    string city = "";
    for(int i = 0; i < n; ++i){
        city += s[i];
    }
    return Adress(city, "", 0, 0);
}

Adress operator""_route(const char* r, std::size_t n){
    string route = "";
    for(int i = 0; i < n; ++i){
        route += r[i];
    }
    return Adress("", route, 0, 0);
}

Adress operator""_house_number(unsigned long long int house_number){
    return Adress("", "", house_number, 0);
}

Adress operator""_apartaments_number(unsigned long long int apartaments_number){
    return Adress("", "", 0, apartaments_number);
}

int main(){
    Adress a("Moscow", "Tverskaya", 4, 5);
    Adress b("Moscow", "Tverskaya", 5, 100);
    Adress c("Moscow", "Petrovskaya", 13, 56);
    Adress d("Moscow", "Tverskaya", 4, 5);
    cout << a << "\n" << b.is_near(a) << "\n" << (a == b) << "\n" << (a == d) << "\n" << b.adress_to_route("Tverskaya") << "\n";
    cout << "Mосква"_city + "проспект 60-летия Октября"_route + 9_house_number + 12_apartaments_number << "\n";
}
