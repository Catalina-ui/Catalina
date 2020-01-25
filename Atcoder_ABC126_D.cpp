#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
typedef long long ll;

vector<vector<pair<ll, ll>>> dp;
vector<ll> d;
ll N;

void bfs(ll pos){
    d[pos] = 0;
    queue<ll> q;
    q.push(pos);
    while(!q.empty()){
        ll t = q.front();
        q.pop();
        for(auto next : dp[t]){
            if(d[next.first] != -1)
                continue;
            d[next.first] = d[t] + next.second;
            q.push(next.first);
        }
    }
}

int main(){
    cin >> N;
    d.resize(N+1, -1);
    dp.resize(N);
    for (int i = 0; i < N-1;i++){
        ll a, b,d;
        cin >> a >> b >> d;
        a--;
        b--;
        dp[a].push_back(make_pair(b, d));
        dp[b].push_back(make_pair(a, d));
    }
    bfs(0);

    for (int i = 0; i < N;i++)
        if(d[i] % 2 == 0)
            cout << 0 << endl;
        else
            cout << 1 << endl;
    return 0;
}
