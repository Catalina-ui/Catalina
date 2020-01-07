#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    vector<pair<int, int>> vp;

    for (int i = 1; i < N;i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
        vp.push_back(make_pair(a, b));
    }

    int K = 0;
    map<pair<int, int>, int> I;
    vector<int> cs(N, 0);

    vector<int> used(N, 0);
    queue<int> q;
    used[0] = 1;
    q.push(0);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        if((int)G[v].size() > K)
            K = G[v].size();
        int cur = 1;
        for(int u:G[v]){
            if(used[u])
                continue;
            if(cur == cs[v])
                cur++;
            cs[u] = I[make_pair(u, v)] = I[make_pair(v, u)] = cur++;
            used[u] = 1;
            q.push(u);
        }
    }
    cout << K << endl;
    for (auto p:vp)
        cout << I[p] << endl;
    return 0;
}
