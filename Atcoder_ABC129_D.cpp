#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int H, W;
    cin >> H >> W;
    vector<string> maze(H);
    vector<vector<int>> h(H, vector<int>(W, 0));
    vector<vector<int>> w(H, vector<int>(W, 0));

    for (int i = 0; i < H;i++)
        cin >> maze[i];

    int ans = 0;
    for (int i = 0; i < H;i++){
        for (int j = 0; j < W;j++){
            if(maze[i][j] == '#'){
                h[i][j] = 0;
                w[i][j] = 0;
                continue;
            }else{
                if(i > 0 && maze[i][j] == '.' && h[i-1][j] > 0){
                    h[i][j] = h[i - 1][j];
                }else{
                    int t = i + 1;
                    while(t < H && maze[t][j] == '.')
                        t++;
                    h[i][j] = t - i;
                }

                if(j > 0 && maze[i][j] == '.' && w[i][j-1] > 0){
                    w[i][j] = w[i][j - 1];
                }else{
                    int t = j + 1;
                    while(t < W && maze[i][t] == '.')
                        t++;
                    w[i][j] = t - j;
                }
                ans = max(ans, h[i][j] + w[i][j] - 1);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
