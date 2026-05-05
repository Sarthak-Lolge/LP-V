#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter number of points: ";
    cin >> n;

    double x[n], y[n];

    cout << "Enter x and y:\n";
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }

    double sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0;
    #pragma omp parallel for reduction(+:sum_x, sum_y, sum_xy, sum_x2)
    for(int i = 0; i < n; i++){
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x2 += x[i] * x[i];
    }

    double m = (n*sum_xy - sum_x*sum_y) / (n*sum_x2 - sum_x*sum_x);
    double c = (sum_y - m*sum_x) / n;

    cout << "Equation: y = " << m << "x + " << c << endl;

    return 0;
}