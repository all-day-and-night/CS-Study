#include<iostream>
#include<string>

using namespace std;

class Person{
    private:
        string name;
    public:
        Person() {name="ju won ung";}
        Person(string name) : name(name) {}
        Person operator + (const Person& other) {return Person(name + " & " + other.name);}
        void showName() {
            cout << "name: " << name << endl;
        }
};
int main() {
    Person person1;
    person1.showName();
    Person person2("na dong bin");
    person2.showName();
    Person result = person1 + person2;
    result.showName();
    return 0;
}