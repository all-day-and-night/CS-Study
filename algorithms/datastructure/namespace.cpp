#include<iostream>

using namespace std;

namespace A {
    void function() {
        cout << "A Namespace" << endl;
    }
}
namespace B {
    void function() {
        cout << "B Namespace" << endl;
    }
}

int main() {
    A::function();
    B::function();
    return 0;
}