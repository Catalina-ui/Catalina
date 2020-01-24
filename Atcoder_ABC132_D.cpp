#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<vector<ll>> com(ll n, ll r)
{
    const long long _MOD = 1000000007;
    vector<vector<ll>> v(n + 1, vector<ll>(n + 1, 0));
    ll tmp = v.size();
    for (int i = 0; i < tmp;i++){
        v[i][0] = 1;
        v[i][i] = 1;
    }
    for (int j = 1; j < tmp;j++){
        for (int k = 1; k < j;k++){
            v[j][k] = v[j - 1][k - 1] + v[j - 1][k];
            if (v[j][k] > _MOD)
                v[j][k] %= _MOD;
        }
    }
    return v;
}

int main(){
    ll N, K;
    ll div_N = 1000000007;

    cin >> N >> K;
    vector<vector<ll>> v(2019, vector<ll>(2019, 0));
    ll tmp = K;
    if(N - K + 1 < K)
        tmp = N - K + 1;
    v = com(2019,2019);
    for (int i = 1; i <= K; i++)
    {
        ll ans = v[N - K + 1][i] * v[K - 1][i - 1];
        if(ans > div_N)
            ans %= div_N;
        cout << ans << endl;
    }
    return 0;
}
