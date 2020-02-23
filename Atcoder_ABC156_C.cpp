#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    ll Min = 10e9, Max = 0;
    for (int i = 0; i < N;i++){
        cin >> A[i];
        Min = min(Min, A[i]);
        Max = max(Max, A[i]);
    }

    ll ans = 10e9;
    for (int i = Min; i <= Max;i++){
        ll tmp = 0;
        for(auto u : A)
            tmp += (u - i) * (u - i);
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}
