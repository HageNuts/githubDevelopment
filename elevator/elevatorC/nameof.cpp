#include <iostream>
#include <typeinfo>

int main()
{
    // 型を指定する場合
    std::cout << typeid(int).name() << std::endl;

    // 変数を指定する場合
    int i = 0;
    std::cout << typeid(i).name() << std::endl;

    // ポインタ変数を指定する場合
    int* pi = NULL;
    std::cout << typeid(pi).name() << std::endl;
}