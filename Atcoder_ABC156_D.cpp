#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;
ll mod = 1e9 + 7;

ll pow(ll a,ll b){
    ll ret = 1;
    for (; b > 0;b >>= 1,a = a * a % mod){
        if(b % 2 == 1){
            ret = ret * a % mod;
        }
    }
    return ret;
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
    ans -= c * pow(d, mod - 2) % mod;
    c = 1, d = 1;
    for (int i = 0; i < b;i++){
        c = c * (N - i) % mod;
        d = d * (i + 1) % mod;
    }
    ans -= c * pow(d, mod - 2) % mod;
    if(ans < 0)
        ans += mod;
    cout << ans << endl;
    return 0;
}
