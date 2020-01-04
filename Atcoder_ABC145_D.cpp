#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
ll X, Y;
vector<ll> fac(1000001);
vector<ll> ifac(1000001);
vector<ll> inv(1000001);

void cominit(){
    fac[0] = fac[1]  = 1;
    ifac[0] = ifac[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < 1000001;i++){
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = mod - inv[mod % i] * (mod / i) % mod;
        ifac[i] = ifac[i - 1] * inv[i] % mod;
    }
}
ll mpow(ll x,ll n){
    ll ans = 1;
    while(n != 0){
        if(n&1)
            ans = ans * x % mod;
        x = x * x % mod;
        n = n >> 1;
    }
    return ans;
}

ll comb(ll a,ll b){
    if(a == 0 && b == 0)
        return 1;
    if(a < b || a < 0)
        return 0;
    ll tmp = ifac[a - b] * ifac[b] % mod;
    return tmp * fac[a] % mod;
}

int main(){
    cin >> X >> Y;
    if((X + Y) % 3 != 0){
        cout << 0 << endl;
        return 0;
    }
    cominit();
    ll x = (2 * Y - X) / 3, y = (2 * X - Y) / 3;
    if(x < 0 || y < 0){
        cout << 0 << endl;
        return 0;
    }
    ll ans = comb(x+y,y);
    cout << ans << endl;
    return 0;
}
