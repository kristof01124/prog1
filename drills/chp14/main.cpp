#include <cstdio>
#include <iostream>

class B1 {
public:
    virtual void vf() {std::cout<<"B1::vf\n";}
    void f() {std::cout<<"B1::f\n";}
    //virtual void pvf()=0;
};

class D1: public B1 {
public:
    void vf() {std::cout<<"D1::vf\n";}
    void f() {std::cout<<"D1::f\n";}
}; 

class D2:public D1 {
public:
    void pvf() {std::cout<<"D2::pvf\n";}
};

class B2 {
public:
    virtual void pvf()=0;
};

class D21: public B2 {
public:
    std::string m_s = "string";
    void pvf() {std::cout<<m_s<<std::endl;}
};

class D22: public B2 {
public:
    int m_i = 10;
    void pvf() {std::cout<<m_i<<std::endl;}
};

void f(B2& b) {
    b.pvf();
}

int main() {
    std::cout<<"2."<<std::endl;
    D1 d1;
    d1.vf();
    d1.f();
    std::cout<<"3."<<std::endl;
    B1& b1(d1);
    b1.vf();
    b1.f();
   /*
    std::cout<<"6"<<std::endl;
    D2 d2;
    d2.pvf();
    d2.vf();
    d2.f();
    std::cout<<"7"<<std::endl;
    D21 d21;
    D22 d22;
    f(d21);
    f(d22);
    */
}
