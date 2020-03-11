#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

ll mod = 1000000007;
string S;
vector<vector<ll>> dp(100005,vector<ll>(13,0));

int main(){
    cin >> S;
    int N = (int)S.size();

    for (int i = 0; i < N;i++){
        char c = (char)S[i];
        int t = c - '0';
        if(c == '?')
            t = -1;
        dp[0][0] = 1;
        for (int j = 0; j < 10;j++){
            if(t != -1 && t != j)
                continue;
            for (int k = 0; k < 13;k++){
                dp[i + 1][(k * 10 + j) % 13] += dp[i][k];
            }
        }
        for (int j = 0; j < 13;j++){
            dp[i + 1][j] %= mod;
        }
    }
    cout << dp[N][5] << endl;
    return 0;
}
