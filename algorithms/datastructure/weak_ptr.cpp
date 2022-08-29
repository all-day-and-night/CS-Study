#include<iostream>
#include<memory>

using namespace std;

int main() {
    int * arr = new int(1);
    shared_ptr<int> sp1(arr);
    weak_ptr<int> wp = sp1;
    cout << sp1.use_count() <<endl;
    cout << wp.use_count() << endl;
    if(true) {
        shared_ptr<int> sp2 = wp.lock();//shared_ptr포인터 반환
        cout << sp1.use_count() << endl;
        cout << wp.use_count() << endl;
    } 
    cout << sp1.use_count() << endl;
    cout << wp.use_count() << endl;
    return 0;
}