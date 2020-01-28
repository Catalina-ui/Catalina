#include <iostream>
#include <vector>
#include <map>
typedef long long ll;
using namespace std;
ll mod = 1000000007;

ll inverse(ll a,ll m){
    ll b = m,u = 1,v = 0;
    while(b){
        ll t = a /b;
        swap(a -= t * b,b);
        swap(u -= t * v,v);
    }
    return (u % m + m) % m;
}

map<ll,ll> divisor(ll a){
    map<ll, ll> mp;
    for (ll i = 2; i * i <= a;i++){
        while(a % i == 0){
            mp[i]++;
            a /= i;
        }
    }
    if (a > 1)
        mp[a]++;
    return mp;
}

int main(){
    int N;
    ll ans = 0;
    cin >> N;
    vector<ll> A(N);
    map<ll, ll> mp;

    for(int i = 0;i < N;i++){
        cin >> A[i];
        map<ll,ll> p = divisor(A[i]);
        for(auto v :p){
            mp[v.first] = max(mp[v.first], v.second);
        }
    }
    ll L = 1;
    for(auto v: mp){
        while(v.second){
            L *= v.first % mod;
            L %= mod;
            v.second--;
        }
    }
    for(int i = 0;i < N;i++){
        ans += (L % mod *inverse(A[i],mod) % mod) % mod;
    }
    ans = ans % mod;
    cout << ans << endl;
    return 0;
}
