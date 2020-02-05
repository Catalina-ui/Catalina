#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<pair<int,int>> A;

int main(){
    int N, T;
    cin >> N >> T;
    A.resize(N);

    for (int i = 0; i < N;i++)
        cin >> A[i].first >> A[i].second;

    sort(A.begin(), A.end());

    vector<vector<int>> dp(3010,vector<int>(3010,0));
    int ans = 0;
    for (int i = 0; i < N;i++){
        for (int j = 0; j < T;j++){
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);

            int tj = j + A[i].first;
            if(tj < T)
                dp[i + 1][tj] = max(dp[i + 1][tj], dp[i][j] + A[i].second);
        }
        int tmp = dp[i][T - 1] + A[i].second;
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}
