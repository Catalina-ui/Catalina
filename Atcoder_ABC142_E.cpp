#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    int max = (1 << N);
    vector<int> dp(max, 10e8);

    vector<int> cost(M);
    vector<int> unlock(M, 0);
    for (int i = 0; i < M;i++){
        int b;
        cin >> cost[i] >> b;
        for (int j = 0; j < b;j++){
            int c;
            cin >> c;
            c--;
            unlock[i] |= 1<<c;
        }
    }

    dp[0] = 0;
    for (int i = 0; i < M;i++){
        for (int j = 0; j < max;j++){
            dp[j | unlock[i]] = min(dp[j | unlock[i]], dp[j] + cost[i]);
        }
    }

    if(dp[max-1] >= 10e8){
        cout << -1 << endl;
    }else{
        cout << dp[max - 1] << endl;
    }
    return 0;
}
