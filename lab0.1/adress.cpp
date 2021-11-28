#include "adress.h"

string Adress::Get_city() const {
    return city;
}

string Adress::Get_route() const {
    return route;
}

int Adress::Get_house_number() const {
    return house_number;
}

int Adress::Get_apartaments_number() const {
    return apartaments_number;
}

ostream& operator<<(ostream& s, const Adress& l){
    s << "(" << l.Get_city() << ", " << l.Get_route() << ", " << l.Get_house_number() << ", " << l.Get_apartaments_number() << ")";
    return s;   
}
bool Adress::operator==(const Adress& l){
    return l.city == city && l.route == route && l.house_number == house_number && l.apartaments_number == apartaments_number;
}

bool Adress::is_near(const Adress& l){
    if(l.Get_city() == city && l.Get_route() == route){
        return (abs(l.Get_apartaments_number() - apartaments_number) <= 1) || (abs(l.Get_house_number() - house_number) <= 1);
    } else {
        return false;
    }
}

bool Adress::adress_to_route(string route_){
    return route == route_;
}

bool Adress::adress_to_city(const string city_){
    return city == city_;
}