#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> ans(N, 0);
    vector<bool> ans1(N, false);
    for (int i = 0; i < M; i++)
    {
        int s, c;
        cin >> s >> c;
        s--;
        if(ans1[s] == true && c != ans[s]){
            cout << -1 << endl;
            return 0;
        }
        ans1[s] = true;
        ans[s] = c;
    }
    if(N != 1 && ans[0] == 0 && ans1[0] == true){
        cout << -1 << endl;
        return 0;
    }
    if(ans1[0] == false && N!= 1)
        ans[0] = 1;

    for (int i = 0; i < N;i++){
        cout << ans[i];
    }
    
    cout << endl;
    return 0;
}
