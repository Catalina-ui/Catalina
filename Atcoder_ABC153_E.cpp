#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <map>
#include <queue>
#include <math.h>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    ll H, N;
    cin >> H >> N;
    //vector<pair<double, double>> vec(N);
    vector<ll> dp(20001,1e9);
    dp[0] = 0;
    for (int i = 0; i < N;i++){
        ll a, b;
        cin >> a >> b;
        ll t = 0;
        while(t + a < 20001){
            dp[t + a] = min(dp[t + a], dp[t] + b);
            t++;
        }
    }
    ll ans = 1e9;
    for (int i = 20000;i >= H;i--){
        ans = min(dp[i], ans);
    }

    cout << ans << endl;
    return 0;
}
