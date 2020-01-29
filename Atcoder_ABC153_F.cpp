#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

typedef long long ll;
using namespace std;

int main(){
    int N;
    ll D, A;
    cin >> N >> D >> A;
    vector<pair<ll, ll>> XHP(N);
    for (int i = 0; i < N;i++){
        cin >> XHP[i].first >> XHP[i].second;
        XHP[i].second = (XHP[i].second + A - 1) / A;
    }

    sort(XHP.begin(), XHP.end());

    ll num = 0, ans = 0;
    queue<pair<ll,ll>> que;
    for (int i = 0; i < N; i++)
    {
        while(!que.empty() && que.front().first < XHP[i].first){
            num -= que.front().second;
            que.pop();
        }

        XHP[i].second -= num;

        if(XHP[i].second <= 0)
            continue;

        ans += XHP[i].second;
        que.push(make_pair(XHP[i].first + 2*D, XHP[i].second));
        num += XHP[i].second;
    }
    cout << ans << endl;
}
