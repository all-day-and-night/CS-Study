#include<iostream>
#include<string>

using namespace std;
/*
typedef struct Student{
    string name;
    int score;
}Student;
*/
class Student {
    private:
    string name;
    int score;
    public:
    Student(string n, int s) { name = n; score = s;}
    void show() {
        cout << name << " : " << score << endl;
    }
};

int main() {
    Student a = Student("na dong bin", 100);
    a.show();
    //cout << a.name << " : " <<a.score <<endl;
    return 0;
}