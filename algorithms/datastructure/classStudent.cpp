#include<iostream>
#include<string>
using namespace std;

class Student {
    private: 
        string name;
        int englishScore;
        int mathScore;
        int getSum() {return englishScore + mathScore;} // 정보은닉
    public:
        Student(string name, int englishScore, int mathScore){
            this->name = name;
            this->englishScore;
            this->mathScore;
        }
        void show() { cout << name << " sum: getSum()\n" ;}
}

int main() {
    Student a = Student("na dong bin", 100, 98);
    a.show();
    //cout << a.getSum();//error
    return 0;

}