#include<iostream>

using namespace std;

/*
 * Задана матрица размером N*M.
 * Определить количество «особых» элементов матрицы,
 * считая элемент «особым»,
 * если он больше суммы остальных элементов своего столбца.
 * */
int main() {
    double **matrix, maxValue, sum, **map;
    int row, col, size, cols, rows;

    cout << "Введите размер масива: \n";
    cin >> size;
    cols = rows = size;
    matrix = new double *[rows];
    map = new double *[rows];
    for (row = 0; row < size; row++) {
        matrix[row] = new double[cols];
        map[row] = new double[4];
    }

    cout << "Ввести эелементы масива: \n";
    for (row = 0; row < rows; row++) {
        for (col = 0; col < cols; col++) {
            cin >> matrix[row][col];
        }
    }

    for (row = 0; row < rows; row++) {
        sum = 0;
        maxValue = 0;
        for (col = 0; col < cols; col++) {
            sum += matrix[col][row];
            if (maxValue < matrix[col][row]) {
                maxValue = matrix[col][row];
                map[row][0] = maxValue; // максимальное число в колонке
                map[row][2] = row; // его позиция в ряду
                map[row][3] = col; // строка в которой находится элемент
            }
        }
        map[row][1] = sum - maxValue; // сумма чисесл ряда без максимального

    }

    for (row = 0; row < rows; row++) {
        for (col = 0; col < cols; col++) {
            cout << matrix[row][col] << " ";
        }
        cout << endl;
    }

    for (row = 0; row < rows; row++) {
        if (map[row][0] > map[row][1]) {
            cout << "особый элемент: " << map[row][0]
                 << " расположен на позици: " << map[row][2]
                 << " в " << map[row][3] << " ряду";
        } else {
            cout << "особый элемент отсуствует";
        }
        cout << endl;
    }
    return 0;
}