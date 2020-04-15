//
// Created by john on 15.04.2020.
//
#include<iostream>
#include <regex>

#ifndef UNTITLED3_LABA7_H
#define UNTITLED3_LABA7_H
using namespace std;

/*
 *  Задача:
 *  В строке, состоящей из групп нулей и единиц,
 *  найти и вывести на экран группы с четным количеством символов.
 */
class Laba7 {
public:
    static void run() {
        regex basicRegex("[0,1]*");
        string subject;
        int counter = 0;

        do {
            cout << "Введите последовательность чисел состоящий из нулей и единиц (0, 1):\n";
            cin >> subject;
        } while (!regex_match(subject, basicRegex));

        try {
            regex re("0+|1+");
            sregex_iterator next(subject.begin(), subject.end(), re);
            sregex_iterator end;
            while (next != end) {
                smatch match = *next;
                if (match.length() % 2 == 0) {
                    counter++;
                    cout << "Найдено совпадение: " << match.str() << " "
                         << " начало на позиции - " << match.position()
                         << " , конец - " << match.position() + match.length()
                         << endl;
                }
                next++;
            }
        } catch (regex_error &e) {
            cout << "Ошибка при обработке регулярного выражения!";
        }
    }
};


#endif //UNTITLED3_LABA7_H
