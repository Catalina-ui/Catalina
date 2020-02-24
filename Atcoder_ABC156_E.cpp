#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

ll N = 2 * 1e5 + 5;
ll K;
ll mod = 1000000007;

vector<ll> fac(N), finv(N), inv(N);

void Cinit()
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < N; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = mod - inv[mod % i] * (mod / i) % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}

long long com(ll n, ll k)
{
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}

int main(){
    Cinit();
    cin >> N >> K;
    ll ans = 0;
    for (int i = 0; i < min(K + 1, N);i++){
        ll a = com(N, i);
        a = (a * com(N - 1, N - i - 1) % mod);
        ans = (a + ans) % mod;
    }
    cout << ans << endl;
    return 0;
}
