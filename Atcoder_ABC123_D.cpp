#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
using namespace std;
typedef long long ll;

int main(){
    ll X, Y, Z, K;
    cin >> X >> Y >> Z >> K;
    vector<ll> x(X), y(Y), z(Z);
    for (int i = 0; i < X;i++)cin >> x[i];
    for (int i = 0; i < Y;i++)cin >> y[i];
    for (int i = 0; i < Z;i++)cin >> z[i];

    vector<unsigned long long> xy(X * Y);
    for (int i = 0; i < X;i++){
        for (int j = 0; j < Y;j++)
            xy[i * X + j] = x[i] + y[j];
    }
    sort(xy.begin(), xy.end());
    if(X * Y > K){
        vector<unsigned long long> xyz(0);
        for (int i = 0; i < K;i++){
            for (int j = 0; j < Z;j++)
                xyz.emplace_back(xy[X * Y - i - 1] + z[j]);
        }
        sort(xyz.begin(),xyz.end());
        for (int i = 0; i < K;i++)
            cout << xyz[xyz.size() - i - 1] << endl;
    }else
    {
        vector<unsigned long long> xyz(0);
        for (int i = 0; i < X*Y; i++)
        {
            for (int j = 0; j < Z; j++)
                xyz.emplace_back(xy[X * Y - i - 1] + z[j]);
        }
        sort(xyz.begin(), xyz.end());
        for (int i = 0; i < min(K,X*Y*Z); i++)
            cout << xyz[xyz.size() - i - 1] << endl;
    }
    
    return 0;
}
