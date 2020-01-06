#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;
ll N,M,sum = 0;
vector<pair<ll ,ll>> vp;
vector<ll> v;

int main(){
    cin >> N >> M;
    v.resize(N);
    vp.resize(M);
    for (int i = 0;i < N;i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    for (int i = 0;i < M;i++){
        ll a,b;
        cin >> b >> a;
        vp[i].first = a;
        vp[i].second = b;
    }
    sort(vp.begin(), vp.end());
    int t = M-1;
    for (int i = 0; i < N;i++){
        if(vp[t].second < 1)
            t--;
        if(t >= 0 && v[i] < vp[t].first){
            sum += vp[t].first;
            vp[t].second--;
        }else{
            sum += v[i];
        }
    }
    cout << sum << endl;
    return 0;
}
