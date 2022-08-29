#include<iostream>
#include<string>

using namespace std;

class Temp{
    public : void showTemp(){
        cout << "temporary parent class" << endl;
    }
};

class Person{
    private:
        string name;
    public:
        Person(string name) : name(name){}

        string getName(){
            return name;
        }
        void showName() {
            cout << "name: " << name << endl;
        }
};

class Student:Person, public Temp{
    private:
        int studentID;
    public:
        Student(int studentID, string name): Person(name) {
            this->studentID = studentID;
        }
        void show(){
            cout << "name: " << getName() << endl;
            cout << "ID: " << studentID << endl;
        }
        void showName() {
            cout << "name: " << getName() <<endl; 
        }
};

int main() {
    Student student1(1, "na dong bin");
    student1.showName();
    student1.showTemp();
    return 0;
}
