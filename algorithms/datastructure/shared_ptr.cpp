#include<iostream>
#include<string>
#include<memory>

using namespace std;

int main() {
    int * arr = new int[10];
    arr[7]=100;
    shared_ptr<int> p1(arr);
    cout << p1.use_count() << endl;
    shared_ptr<int> p2(p1);
    cout << p1.use_count() << endl;
    shared_ptr<int> p3(p2);//p3 = p2;
    cout << p1.use_count() << endl;
    p1.reset();
    p2.reset();
    cout << " arr[7]: " << arr[7] << endl;
    p3.reset();
    cout << p1.use_count() <<endl;
    cout <<"arr[7]: " << arr[7] << endl;
    return 0;
}