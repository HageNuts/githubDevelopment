#include <iostream>
#include <windows.h>
#include <chrono>
#include <thread>
using namespace std;

int main() {
    int now_floor = 1;
    int enter_floor = 6;
    int persons_floor = 6;
    int inthebox = 0;
    string enter_vector;
    system("cls");
    cin >> enter_vector;//エレベーターホールにおける行きたい方向の指定ボタン。上か下か。
    if(enter_vector == "w" || enter_vector == "s") {//wで上、sで下。
    system("cls");
    if(now_floor > enter_floor) {//もともと箱の方が上にいたとき。
        cout << now_floor << " down ";
        while((now_floor - enter_floor) != 0) {//箱と人の階数が一致するまで繰り返す。
            this_thread::sleep_for(std::chrono::milliseconds(2300));//階数が減ります。
            system("cls");
            now_floor--;
            cout << now_floor << " down ";
        }
            cout << endl;//ここの下にopeningと一文字ずつ表示させる。
            this_thread::sleep_for(std::chrono::milliseconds(500));//扉が開きます、

            cout << endl;
            this_thread::sleep_for(std::chrono::seconds(1));
            cout << "BUTTON:" << endl;
            cin >> enter_floor;//行きたい階数を入力。
            if(enter_floor > 0 && enter_floor < 11){//1から10階まで止まる。正常。
            this_thread::sleep_for(std::chrono::milliseconds(3500));//扉が閉まります。
            system("cls");
            if(enter_vector == "w") {//w...上行
                cout << now_floor << " up ";
                while((enter_floor - now_floor) != 0) {
                    this_thread::sleep_for(std::chrono::milliseconds(2300));//階数が増えます。
                    system("cls");
                    now_floor++;
                    persons_floor = now_floor;
                    cout << now_floor << " up ";
                }
                this_thread::sleep_for(std::chrono::seconds(15));//扉が開きます、閉まります。
        
            }else if(enter_vector == "s") {//s...下行
                cout << now_floor << " down ";
                while((enter_floor - now_floor) != 0) {
                    this_thread::sleep_for(std::chrono::milliseconds(2300));//階数が減ります。
                    system("cls");
                    now_floor--;
                    persons_floor = now_floor;
                    cout << now_floor << " down ";
                }
                this_thread::sleep_for(std::chrono::seconds(15));//扉が開きます、閉まります。
            }else{
               cout << "ERROR" << endl;//これは表示されない。
            }
        }else{
            cout << "FUKUCHI" << endl;
        }

        }else if(now_floor < enter_floor) {
        cout << now_floor << " up ";
        while((now_floor - enter_floor) != 0) {
            this_thread::sleep_for(std::chrono::milliseconds(2300));//階数が増えます。
            system("cls");
            now_floor++;
            cout << now_floor << " up ";
        }
            this_thread::sleep_for(std::chrono::milliseconds(3500));//扉が開きます、
            cout << endl;
            cout << "BUTTON:";
            cin >> enter_floor;//行きたい階数を入力。
            if(enter_floor > 0 && enter_floor < 11){//正常
            this_thread::sleep_for(std::chrono::milliseconds(3500));//扉が閉まります。
            system("cls");
            if(enter_vector == "w") {//ここに何か書き込むことで正常になる。
                cout << now_floor << " up ";
                while((enter_floor - now_floor) != 0) {
                    this_thread::sleep_for(std::chrono::milliseconds(2300));//階数が増えます。
                    system("cls");
                    now_floor++;
                    persons_floor = now_floor;
                    cout << now_floor << " up ";
                }
                this_thread::sleep_for(std::chrono::seconds(15));//扉が開きます、閉まります。
        
            }else if(enter_vector == "s") {//here too.
                cout << now_floor << " down ";
                while((enter_floor - now_floor) != 0) {
                    this_thread::sleep_for(std::chrono::milliseconds(2300));//階数が減ります。
                    system("cls");
                    now_floor--;
                    persons_floor = now_floor;
                    cout << now_floor << " down ";
                }
                this_thread::sleep_for(std::chrono::seconds(15));//扉が開きます、閉まります。
            }else{
                cout << "ERROR0" << endl;//これは表示されません。っ無駄ァ⤴！！！！！
            }
        }else{
            cout << "ERROR1" << endl;
        }
    }else if(now_floor == enter_floor) {//ここから下のコードを正常にする必要がある。関数moveってついてるけどそんなのとうの昔に消したわ
        Sleep(3500);//扉が開きます。
        cin >> enter_floor;//行きたい階数を入力。
        Sleep(3500);//扉が閉まります。
        int move(int enter_floor, int now_floor);//f(move)
    }else if (enter_floor < 0 || enter_floor < 11){
        cout << "FUKUCHI" << endl;//これが表示されることは無いでしょう。
    }}else{
        cout << "USE w key to go up or use s key to go down." << endl;
    }
}
//1.0.0 202505161515
//1.0.1 202505161539 開始時とボタンを押された後の余計な行消去
//1.0.2 202505172339 止まる範囲の指定
//1.0.3 202505180815 wsキーのみの入力を受け付ける。
//1.0.4 20250520 wキーで必ず上へ、sキーで必ず下へ。

//コード長すぎるから短縮しようと思ったけどあまりにも膨大で出来なさそう。
//かなりの根気がないと無理だ。これは。

