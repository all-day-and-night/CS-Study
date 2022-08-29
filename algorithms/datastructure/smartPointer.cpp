#include<iostream>
#include<string>
#include<memory>

using namespace std;

int main() {/*
    unique_ptr<int> p1(new int(10));
    unique_ptr<int> p2;
    cout << "smart pointer1: " << p1 <<endl;
    cout << "smart pointer2: " << p2 << endl;
    cout << "possesion move\n" <<endl;
    p2 = move(p1);//소유권 이전
    cout << "smart pointer1: " << p1 << endl;
    cout << "smart pointer2: " << p2 << endl;
    cout << "------delete------" << endl;
    p2.reset();//할당 해제
    cout << "smart pointer1: " << p1 << endl;
    cout << "smart pointer2: " << p2 << endl;
*/ /* 객체 접근
    unique_ptr<int> p1(new int (10));
    cout << *p1 << endl;
*/
    int * arr = new int [10];
    unique_ptr<int> p1(arr);
    for(int i=0; i<10 ; i++){
        arr[i] = i;
    }
    for(int i=0; i<10; i++){
        cout << arr[i] << " ";
    }
    p1.reset();
    cout << endl;
    for(int i=0 ; i<10; i++){
        cout << arr[i] << " ";
    }
    return 0;
} 