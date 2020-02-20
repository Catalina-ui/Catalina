#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> vec;
vector<bool> vis;

void dfs(int ind){
    if(vis[ind])
        return;
    vis[ind] = true;
    for(auto d:vec[ind])
        dfs(d);
}

int main(){
    int N,M;
    cin >> N >> M;
    vec.resize(N);
    vis.resize(N, 0);
    for (int i = 0; i < M;i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        vec[a].emplace_back(b);
        vec[b].emplace_back(a);
    }
    int ans = 0;
    for (int i = 0; i < N;i++){
        if(!vis[i]){
            ans++;
            dfs(i);
        }
    }
    cout << ans << endl;
    return 0;
}
