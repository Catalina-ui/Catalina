#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;
ll mod = 1e9 + 7;

ll pow(ll a,ll b){
    if(b == 0)
        return 1;
    ll res = pow(a * a % mod, b / 2);
    if(b&1)
        res = res * a % mod;
    return res;
}

int main(){
    ll N,a,b;
    cin >> N >> a >> b;
    ll ans = pow(2, N) - 1;
    ll c = 1, d = 1;
    for (int i = 0; i < a;i++){
        c = c * (N - i) % mod;
        d = d * (i + 1) % mod;
    }
    ans -= c * pow(d, 1e9 + 5) % mod;
    c = 1, d = 1;
    for (int i = 0; i < b;i++){
        c = c * (N - i) % mod;
        d = d * (i + 1) % mod;
    }
    ans -= c * pow(d, 1e9 + 5) % mod;
    while(ans < 0)
        ans += mod;
    cout << ans << endl;
    return 0;
}
