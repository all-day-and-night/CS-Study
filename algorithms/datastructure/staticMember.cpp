#include<iostream>
#include<string>

using namespace std;

class Person{
    private:
        //const int id; // 수정불가능
        string name;
    public:
        static int count;//모든 멤버가 동시에 가지고 있는 값
       
       Person(string name) : name(name){
            count++;
        }/*
        void setId(int id){
            this->id = id; 오류발생
        }*/
};
int Person::count = 0;

int main() {
    Person p1("ju");
    Person p2("won");
    Person p3("ung");
    cout << "number of people: " << Person::count << endl;
    return 0;
}