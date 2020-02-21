#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
ll mod = 10e9 + 7;
vector<vector<int>> graph;
ll N, K;
ll dfs(int pos,int parent){
    ll canUseColor = (parent == -1) ? K - 1 : K - 2;

    if((ll)graph[pos].size() > K){
        return 0;
    }else{
        ll res = 1;
        for(int u:graph[pos]){
            if(u == parent)
                continue;
            res *= canUseColor;
            res %= mod;
            canUseColor--;
        }

        for(int u:graph[pos]){
            if(u == parent)
                continue;
            res *= dfs(u, pos);
            res %= mod;
        }
        return res;
    }
}

int main(){

    cin >> N >> K;
    graph.resize(N);
    for (int i = 0; i < N - 1;i++){
        ll a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    ll ans = K * dfs(0, -1);
    ans %= mod;
    cout << ans << endl;
    return 0;
}
