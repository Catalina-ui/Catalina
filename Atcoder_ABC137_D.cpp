#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

typedef long long ll;
using namespace std;

int main(){
    ll N,M;
    cin >> N >> M;
    vector<pair<ll, ll>> ab(N);
    for (ll i = 0; i < N;i++){
        ll a, b;
        cin >> a >> b;
        ab[i] = make_pair(a, b);
    }
    sort(ab.begin(), ab.end());

    ll ans = 0, ext = 0;
    priority_queue<ll> tmp;

    for (ll j = 1; j <= M;j++){
        while(ab[ext].first <= j && ext < N){
            tmp.push(ab[ext].second);
            ext++;
        }
            if(tmp.empty())
                continue;

            ans += tmp.top();
            tmp.pop();
    }
    cout << ans << endl;
}
