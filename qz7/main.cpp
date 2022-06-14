#include <iostream>
#include <string>

using namespace std;
class myString {
    public:
        string str;
};
class ReadClass {
    public:
        string compare = "class";
        string Name;
        int num;
        ReadClass showClass() {
            num = 2;
            int cnt = num;
            cout << num << " class in main.cpp" << endl;
            while(--num) {
                if (cnt-num-1 == 0) Name = "myString";
                cout << "class " << Name << endl;
            }
            cout << "class ReadClass" << endl;
        }
};

int main() {
    ReadClass rfile;
    rfile.showClass();
    return 0;
}
