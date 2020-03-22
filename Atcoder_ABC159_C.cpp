#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int N;
    cin >> N;
    cout << fixed << setprecision(15);
    double a, b;
    a = N / 3;
    b = N % 3;
    double ans = 1;
    for (int i = 0; i < 3;i++){
        ans *= (a + b / 3);
    }
        cout << ans << endl;

    return 0;
}
