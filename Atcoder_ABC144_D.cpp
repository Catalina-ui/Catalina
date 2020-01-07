#include <iomanip>
#include <iostream>
#include <math.h>
using namespace std;

int main(){
    long double a, b, x;
    cin >> a >> b >> x;
    long double ans = 0;
    long double PI = (acos(-1));
    if(a * a * b / 2 >= x){
        ans = atan((a * b * b) / (2 * x));
    }else{
        ans = atan(2 * (a * a * b - x) / (a * a * a));
    }
    cout << fixed << setprecision(15);
    cout << ans * 180.0 / PI << endl;
    return 0;
}
