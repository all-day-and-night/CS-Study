#include<iostream>
#include<string>

using namespace std;

class A {
    public: 
        virtual void show()=0 {//순수 가상함수//=0 없어도 가능
            cout<< "A class \n" ;
        }
};
class B :public A{
    
    virtual void show() { cout << "B class \n";}
};

int main() {
    A * p;
    A a;
    B b;
    p = &a;
    p->show();
    p = &b;
    p->show();//여전히 A class 호출 정적 바인딩
    
    
    
    return 0;
}