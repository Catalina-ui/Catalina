#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N+1);
    vector<int> ans(N+1, 0);
    for (int i = 1; i < N + 1;i++)
        cin >> A[i];
    int cnt = 0;
    for (int i = N; i > 0;i--){
        int tmp = 0;
        for (int k = 1; k * i < N+1;k++)
            tmp += ans[k * i];

        if(tmp % 2 != A[i]){
            ans[i] = 1;
            cnt++;
        }
    }
    cout << cnt << endl;
    vector<int> Ans(cnt);
    int x = 0;
    for (int i = 1; i < N + 1;i++){
        if(ans[i] == 1){
            Ans[x] = i;
            x++;
        }
    }
    for (int i = 0; i < cnt;i++)
        cout << Ans[i] << " ";
    cout << endl;
    return 0;
}
