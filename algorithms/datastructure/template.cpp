#include<iostream>
#include<string>

using namespace std;

template<typename T>
void change(T& a, T& b){
    T temp;
    temp = a;
    a = b;
    b = temp;
}
template<>
void change<int> (int &a, int &b){//명시적 특수화

    cout << "change the data is type int"<< endl;
    int temp;
    temp = a;
    a = b;
    b = temp;
}

template<typename T = int>//default template function
class Data{
    private:
        T data;
    public:
        Data(T data) : data(data){}
        void setData(T data) {
            this->data = data;
        }
        T getData(){
            return data;
        }
};

int main() {
    string a= "ju";
    string b = "won";
    change(a, b);
    cout << a << " : " << b <<endl;
    //-----------------------
    Data<int> data1(1);
    Data<string> data2("juwonung");
    cout << data1.getData() << " : "  << data2.getData() << endl;
    Data<> data3(3);
    cout << data3.getData()<<endl;
    return 0;
}