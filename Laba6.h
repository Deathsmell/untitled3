//
// Created by john on 15.04.2020.
//
#include "iostream"

#ifndef UNTITLED3_LABA6_H
#define UNTITLED3_LABA6_H
using namespace std;

/*
 * Задана матрица размером N*M.
 * Определить количество «особых» элементов матрицы,
 * считая элемент «особым»,
 * если он больше суммы остальных элементов своего столбца.
 * */
class Laba6 {
public:
    static void run() {
        double **matrix, maxValue, sum, **map;
        int i, j, size;

        cout << "Введите размер масива: \n";
        cin >> size;
        matrix = new double *[size];
        map = new double *[size];
        for (i = 0; i < size; i++) {
            matrix[i] = new double[size];
            map[i] = new double[size];
        }

        cout << "Ввести эелементы масива: \n";
        for (i = 0; i < size; i++) {
            sum = 0;
            for (j = 0; j < size; j++) {
                cin >> matrix[i][j];
                sum += matrix[i][j];
                if (maxValue < matrix[i][j]) {
                    maxValue = matrix[i][j];
                    map[i][0] = maxValue; // максимальное число в ряду
                    map[i][2] = j; // его позиция в ряду
                }
            }
            map[i][1] = sum - maxValue; // сумма чисесл ряда без максимального
        }

        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++) {
                cout << matrix[i][j] << " ";
            }
            if (map[i][0] > map[i][1]) {
                cout << "\tособый элемент: " << map[i][0]
                     << " расположен на позици: " << map[i][2];
            } else {
                cout << "\tособый элемент отсуствует";
            }
            cout << endl;
        }
    }
};


#endif //UNTITLED3_LABA6_H
