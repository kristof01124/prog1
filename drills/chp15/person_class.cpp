#include <iostream> 
#include "../../include/std_lib_facilities.h"

#define BAD_CHARACTERS ";:\"'[]*&^%$#@!."

/*
    g++ main.cpp ../../include/*.cpp -o main `fltk-config --ldflags --use-images` -std=c++11
*/



class Person {
public:
    std::string m_first_name, m_second_name;
    int m_age;
    Person() {};

    void check_bad_characters(const std::string& bc = BAD_CHARACTERS) {
        if (m_first_name.size() > 150)
            error("Too long!");
        for (int i = 0; i<bc.size(); ++i) {
            if (m_first_name.find(bc.substr(i,1)) != std::string::npos || 
            m_second_name.find(bc.substr(i,1)) != std::string::npos
            ) {
                error("Found bad character!");
            }
        }
    }

    Person(const std::string& f, const std::string& s, const int& a)
        :m_first_name(f), m_second_name(s), m_age(a) {
            check_bad_characters();
        }

    const string& first_name() const {
        return m_first_name;
    }
    
    const string& second_name() const {
        return m_second_name;
    }

    const int& age() const {
        return m_age;
    }
};

ostream& operator<<(ostream& os, const Person& p)
{
  return os << p.first_name() << " " << p.second_name() << "," << p.age() << '\n';
}

istream& operator>>(istream& os, Person& p)
{
  istream& out = os >> p.m_first_name >> p.m_second_name >> p.m_age;
  p.check_bad_characters();
  return out;
}

int main() {
    /*
    Person p("alma", 1), g{"Goofy", 63};
    std::cin>>p;
    std::cout<<p;
    Person t[3];
    std::cin>>t[0]>>t[1]>>t[2];
    std::cout<<t[1]<<t[1]<<t[2];
    */
   Person t("Tóth", "Kristóf", 18);
   std::cin>>t;
   std::cout<<t<<std::endl;
    /*

    */
}