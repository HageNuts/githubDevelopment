#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std;

class Sekaino{
public:
    int counter;
    void na(){
        counter++;
        this_thread::sleep_for(chrono::milliseconds(30));
        cout << counter;
        if(counter % 3 == 0 || to_string(counter).find("3") != string::npos){
            cout << "ﾊﾞｶ";
        }
    }
};


int main(){
    Sekaino Nabeatsu;
    Nabeatsu.counter = 0;
    while(true){
        cin.get();
        Nabeatsu;
        Nabeatsu.na();
    }

    return 0;
}