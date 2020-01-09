#include <iostream>
#include <vector>

using namespace std;

int N,Q;
vector<vector<int>> G;
vector<bool> C;
vector<long int> test;

void dfs(int c,int s){
    C[c] = true;
    test[c] += s;
    for(auto u :G[c]){
        if(C[u])
            continue;
        dfs(u, test[c]);
    }
}

int main(){
    cin >> N >> Q;
    G.resize(N);
    for (int i = 1; i < N;i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    C.resize(N,0);
    test.resize(N,0);
    for (int i = 0; i < Q;i++){
        int a, b;
        cin >> a >> b;
        a--;
        test[a] += b;
    }
    dfs(0, 0);
    for (int i = 0; i < N;i++)
        cout << test[i] << " ";
    cout << endl;
    return 0;
}
