#include<iostream>
#include<string>
using namespace std;

class Student {
private:
    int studentId;
    string name;
public:
    Student(int studentId, string name) : studentId(studentId), name(name) {}
    friend Student operator + (const Student &student, const Student & other){
        return Student(student.studentId, student.name + " & " + other.name);
    }
    void showName() {
        cout << "name: " << name << endl;
    }

};
 
int main() {
    Student student1(1, "juwon");
    Student result = student1 + student1;
    result.showName();
    return 0;
}