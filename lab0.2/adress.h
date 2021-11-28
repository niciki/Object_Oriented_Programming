#ifndef ADRESS_H
#define ADRESS_H

#include <iostream>
using namespace std;

class Adress {
    public:
        Adress() = default;
        Adress(string c, string r, int h, int a): city(c), route(r), house_number(h), apartaments_number(a){}
        friend ostream& operator<<(ostream& s, const Adress& l);
        friend Adress operator+(const Adress& l, const Adress& r);
        bool operator==(const Adress& l) const;
        bool is_near(const Adress& l) const;
        bool adress_to_route(string route_) const;
        bool adress_to_city(string city_) const;
        string Get_city() const;
        string Get_route() const;
        int Get_house_number() const;
        int Get_apartaments_number() const;
    private:
        string city;
        string route;
        int house_number;
        int apartaments_number;
};

/*Создать класс Address для работы с адресами домов. Адрес должен состоять из строк с названием города
 и улицы и чисел с номером дома и квартиры. Реализовать операции сравнения адресов, а также операции 
 проверки принадлежности адреса к улице и городу. В операциях не должен учитываться регистр строки. 
 Так же необходимо сделать операцию, которая возвращает истину если два адреса находятся по соседству
  (на одной улице в одном городе и дома стоят подряд).*/

#endif