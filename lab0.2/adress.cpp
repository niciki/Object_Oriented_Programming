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

Adress operator+(const Adress& l, const Adress& r){
    Adress q;
    string city = "";
    string route = "";
    int house_number = 0;
    int apartaments_number = 0;
    if(l.Get_city() != ""){
        city = l.Get_city();
    }
    if (l.Get_route() != ""){
        route = l.Get_route();
    }
    if (l.Get_house_number()){
        house_number = l.Get_house_number();
    }
    if (l.Get_apartaments_number()){
        apartaments_number = l.Get_apartaments_number();
    }
    if(r.Get_city() != ""){
        city = r.Get_city();
    } 
    if (r.Get_route() != ""){
        route = r.Get_route();
    } 
    if (r.Get_house_number()){
        house_number = r.Get_house_number();
    } 
    if (r.Get_apartaments_number()){
        apartaments_number = r.Get_apartaments_number();
    }
    return Adress(city, route, house_number, apartaments_number);
}

bool Adress::operator==(const Adress& l) const {
    return l.city == city && l.route == route && l.house_number == house_number && l.apartaments_number == apartaments_number;
}

bool Adress::is_near(const Adress& l) const {
    if(l.Get_city() == city && l.Get_route() == route){
        return (abs(l.Get_apartaments_number() - apartaments_number) <= 1) || (abs(l.Get_house_number() - house_number) <= 1);
    } else {
        return false;
    }
}

bool Adress::adress_to_route(string route_) const {
    return route == route_;
}

bool Adress::adress_to_city(const string city_) const {
    return city == city_;
}