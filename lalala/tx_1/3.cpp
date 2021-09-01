// https://www.nowcoder.com/test/question/11ee0516a988421abf40b315a2b28d08?pid=30545524&tid=47169735
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <cmath>
using namespace std;
#define dbg(x) cout << (#x) << " = " << (x) << endl;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        double A, B, C;
        cin >> A >> B >> C;
        double a = 0.5 / A;
        double b = -1 / B;
        double c = C / B;
        if (b * b - 4 * a * c < 0)
        {
            cout << 0 << endl;
        }
        else
        {
            double x1 = (-b + sqrt(b * b - 4 * a * c)) / 2 / a;
            double x2 = (-b - sqrt(b * b - 4 * a * c)) / 2 / a;

            double f1 = x1 * x1 / 2 / B - x1 * x1 * x1 / 6 / A - C / B * x1;
            double f2 = x2 * x2 / 2 / B - x2 * x2 * x2 / 6 / A - C / B * x2;
            printf("%.6f\n", abs(f1 - f2));
        }
    }
}