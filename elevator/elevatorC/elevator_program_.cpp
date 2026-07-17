#include <iostream>
#include <string>
//#include <windows.h>//->windows環境下のみでubuntuだともうちょっと設定しなきゃいけない(?)
#include <cmath>
#include <chrono>
#include <thread>
#include <typeinfo>
#include <ctime>
#include <vector>
using namespace std;

class Test{
public:
    char button;
};

class Elevator{
public:
    int entire_floor, current_floor, to_floor;//順にエレベーター移動が有効な階の階数, 現在の箱の階数, どこへ行くか
    Elevator();//ただのコンストラクタ

};

class UpButton:public Elevator{
public:
    int button;
    int decrease(int current_floor, int input);
};

class DownButton:public Elevator{
public:
    int button;
    int increase(int current_floor, int input);
};

class Button:public Elevator{
    
};

Elevator::Elevator():entire_floor(10), current_floor(1){
    //cout << "全体の変数初期化中..." << endl;
}

int UpButton::decrease(int current_floor, int input){
    int i;
    for (i = 0; i < (current_floor - input); i++){
        current_floor--;
        cout << "↓" << current_floor << "階" << endl;
    }

    cout << to_floor << "階です" << endl;
    cout << "ドアが開きます" << endl;
    return current_floor; //念のため
}

int DownButton::increase(int to_floor, int input){
    int i, is_same;
    for (i = 0; i < input; i++){
        current_floor++;
    }

    if (current_floor == input){
        cout << "到着" << endl;
        is_same = 1;
    }
    return is_same;
}
int main(){
    Elevator lift;
    UpButton up;
    DownButton down;

    Test outside_button;
    //外側のボタンの入力はmain関数で行うこととしたい
    cin >> outside_button.button;
    if (typeid(outside_button.button).name() != "char"){
        return 1;//char型でないと異常終了
    }
    if(outside_button.button == 'u'){
        up.button;
    }
    
    return 0;
}