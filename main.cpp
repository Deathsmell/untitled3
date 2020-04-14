#include<iostream>
#include<cctype>
#include<cstdio>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    char str[99];
    bool flag;
    int i, len;
    char ch;
    len = 99; // вот тут узкий момент. Конструкция очень неустойчивая.
    cout << "Введите строку, состоящую из букв, цифр, запятых, точек, знаков «+» и «–»\n";
    for (i = 1; i <= len; i++) {
        ch = getchar();
        if (ch == ' ') break;
        if (isdigit(ch)) {
            flag = true;
            cout << ch;
        } else {
            if (flag) {
                cout << endl;
                flag = false;
            }
        }
    }
    return 0;
}