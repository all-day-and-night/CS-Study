#include<iostream>
#include<string>
#define SIZE 100

using namespace std;

class Character{
    private:
        string name;
        int ragePoint;
        int hp;
        int damage;
    public:
    /*
        Character(string name, int hp, int damage){
            this->name = name;
            this->hp = hp;
            this->damage = damage;
            this->ragePoint = 0;
        }
    */  
        Character(String name, int hp, int damage) : name(name) , ragePoint(0), hp(hp), damage(damage){}
        //deep copy
        Character(const Character& other){// 복사 생성자
            name = other.name;
            ragePoint = other.ragePoint;
            hp = other.hp;
            damage = other.damage;
        }
        void show(){
            cout << name << "[" << ragePoint << "]" << hp << " " << damage << endl;
        }
        void pointUp() { ragePoint++;}
        ~Character(){
            cout << "instance none\n";
        }
};

//int * arr;
int main() {
    /*arr = new int[SIZE];//동적할당
    for(int i=0; i< SIZE; i++){
        arr[i] = i;
    }
    for(int i=0; i<SIZE ; i++){
        cout << arr[i] << " ";
    }
    delete arr;//해제
    */
    Character * character1 = new Character("slime", 50, 10);
    character1->pointUp();
    Character character2(*character1);
    character2.pointUp();
    character1->show();
    character2.show();
    delete character1;
    //delete character2; 동적할당을 사용하지 않았기 때문에 오류 발생

    return 0;
}