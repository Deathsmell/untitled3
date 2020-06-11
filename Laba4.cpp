#include<iostream>
#include <cmath>

using namespace std;



void input_var(double &a, double &b, double &h, int &n);
void calculate(double &a,double &b,double &h, int &n);
void Out_res(double x,double s, double Y);

int main() {
    typedef double (*Tfun)(double);
    double a, b, x, h, r, s, Y, minY, maxY;
    int n;

    input_var(a,b,h,n);
    calculate(a,b,h,n);
    return 0;

}

void calculate(double &a,double &b,double &h, int &n){
    double x,r,s,Y,minY,maxY;
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

void input_var(double &a, double &b, double &h, int &n){

    cout << "input a,b,h,n\n";
    cout << "a(starting position) = ";
    cin >> a;
    cout << "b(end position) = ";
    cin >> b;
    cout << "h(step) = ";
    cin >> h;
    cout << "n(tick count) = ";
    cin >> n;

}
void Out_res(double x,double s, double Y){
    cout << "\nx= " << x
         << "\t;S(x)= " << s
         << "\t;Y(x)= " << Y
         << "\t;|Y(x) - S(x)|= " << abs(Y - s);
}