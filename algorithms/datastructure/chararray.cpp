#include<iostream>
#include<string>

using namespace std;

int main() {
    string input;
    string input1; 
    cin >> input;
    getline(cin, input1);
    for(int i=0; i<input.size() ; i++){
        cout << input[i] << " ";
    }
    int k = 123;
    string s = to_string(k);
    cout << s << endl;
    int l = stoi(s);
    cout << l << endl;
    return 0;
}