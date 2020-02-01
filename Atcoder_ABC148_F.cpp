#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

vector<vector<ll>> graph;
vector<ll> U;
vector<ll> V;

void dfsU(ll v,ll t){
    U[v] = t, t++;
    for(auto next : graph[v]){
        if(U[next] != -1)
            continue;
        dfsU(next, t);
    }
}

void dfsV(ll v, ll t)
{
    V[v] = t, t++;
    for (auto next : graph[v])
    {
        if (V[next] != -1)
            continue;
        dfsV(next, t);
    }
}

int main(){
    ll N, u, v;
    cin >> N >> u >> v;
    u--, v--;
    graph.resize(N);
    U.resize(N,-1);
    V.resize(N,-1);

    if(N < 2){
        cout << 0 << endl;
        return 0;
    }

    for (int i = 1; i < N;i++){
        ll a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }

    dfsU(u, 0);
    dfsV(v, 0);

    ll ans = 0;
    for (int i = 0; i < N;i++){
        if(ans < V[i] && U[i] < V[i]){
            ans = V[i];
        }
    }

    cout << ans - 1 << endl;
    return 0;
}
