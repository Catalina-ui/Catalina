#include <iostream>
#include <vector>
#include <iomanip>
#include <math.h>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    vector<double> twolist(18, 2);
    for (int i = 2; i < 18;i++)
        twolist[i] = twolist[i - 1] * 2;
    twolist[0] = 1;
    double ans = 0;
    int ind = 0;
    for (int i = N; i >= 1;i--){
        double t = (double)K / i;
        while(twolist[ind] < t)
            ind++;
        ans += (double)1.0 / N * pow(0.5, ind);
    }
    cout << fixed << setprecision(15);
    cout << ans << endl;
    return 0;
}
