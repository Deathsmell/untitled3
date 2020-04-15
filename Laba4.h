//
// Created by john on 15.04.2020.
//
#include <iostream>
#include <cmath>


#ifndef UNTITLED3_LABA4_H
#define UNTITLED3_LABA4_H
using namespace std;

class Laba4 {
public:
    static void run() {

        typedef double (*Tfun)(double);
        double a, b, x, h, r, s, Y, minY, maxY;
        int n;
        cout << "input a,b,h,n\n";
        cout << "a(starting position) = ";
        cin >> a;
        cout << "b(end position) = ";
        cin >> b;
        cout << "h(step) = ";
        cin >> h;
        cout << "n(tick count) = ";
        cin >> n;

        for (x = a; x <= b; x += h) {
            Y = cos(x);
            r = s = 1;
            for (int k = 1; k <= n; k++) {
                r *= (-(x * x) /
                      ((2 * k) * (2 * k - 1)));
                s += r;
            }

            Out_res(x, s, Y);

            if (maxY == 0 || maxY < Y) maxY = Y;
            if (minY == 0 || minY > Y) minY = Y;
        }
        cout << "\n\nMin Y(x) = " << minY << "\tMax Y(x) = " << maxY << endl;
    }

    static void Out_res(double x,double s, double Y){
        cout << "\nx= " << x
             << "\t;S(x)= " << s
             << "\t;Y(x)= " << Y
             << "\t;|Y(x) - S(x)|= " << abs(Y - s);
    }

};



#endif //UNTITLED3_LABA4_H
