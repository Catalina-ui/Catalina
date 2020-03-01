#include <iostream>
#include <vector>
using namespace std;

int N, M, K;
vector<int> par, sz, fr;

int root(int x){
    return par[x] == x ? x : root(par[x]);
}

void unit(int x,int y){
    x = root(x), y = root(y);
    if(x == y)
        return;
    else
        if(x < y)
            par[y] = x, sz[x] += sz[y];
        else
            par[x] = y, sz[y] += sz[x];
}

int main(){
    cin >> N >> M >> K;
    par.resize(N);
    sz.resize(N,1);
    fr.resize(N,0);
    for (int i = 0; i < N;i++)
        par[i] = i;

    for (int i = 0; i < M;i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        fr[a]++, fr[b]++;
        unit(a, b);
    }
    vector<vector<int>> block(N, vector<int>(0));
    for (int i = 0; i < K;i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        block[a].emplace_back(b);
        block[b].emplace_back(a);
    }
    vector<int> ans(N, 0);
    for (int i = 0; i < N;i++){
        int x = root(i);
        ans[i] = sz[x] - 1 - fr[i];
        for (int y : block[i])
            if(root(y) == x)
                ans[i]--;
    }
    for (int i = 0; i < N; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}
