#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N,M, ans;

int main()
{
    cin >> N >> M;
    vector<vector<int>> maze(N, vector<int>(M, 1));
    for (int i = 0; i < N;i++)
        for (int j = 0; j < M;j++){
            char a;
            cin >> a;
            if(a == '.')
                maze[i][j] = 0;
        }

    vector<vector<int>> G(N * M,vector<int>(0));
    for (int i = 0; i < N;i++)
        for (int j = 0; j < M;j++){
            if(i > 0 && maze[i][j] == 0 && maze[i-1][j] == 0){
                G[i * M + j].push_back((i - 1) * M + j);
                G[(i - 1) * M + j].push_back(i * M + j);
            }
            if (j > 0 && maze[i][j] == 0 && maze[i][j-1] == 0){
                G[i * M + j].push_back(i * M + j - 1);
                G[i * M + (j - 1)].push_back(i*M + j);
            }
        }

    ans = 0;
    for (int i = 0; i < N*M;i++){
        if(G[i].size() == 0)
            continue;
        vector<int> dist(N*M, -1);
        queue<int> que;
        dist[i] = 0;
        que.push(i);

        while(!que.empty()){
            int v = que.front();
            que.pop();

            for(int nv:G[v]){
                if(dist[nv] != -1)
                    continue;
                dist[nv] = dist[v] + 1;
                que.push(nv);
            }
        }
        sort(dist.begin(), dist.end());
        if(dist[N*M-1] > ans)
            ans = dist[N*M-1];
    }
        cout << ans << endl;
    return 0;
}
