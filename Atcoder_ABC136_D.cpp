#include <vector>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;

    ll N = s.size();

    vector<ll> R(N, 0);
    vector<ll> L(N, 0);
    vector<ll> ans(N, 0);

    for (int i = 0; i < N;i++){
        if(s[i] == 'R' && (i==0 ||R[i-1] < 2)){
            int tmp = i+1;
            while(s[tmp] =='R'){
                tmp++;
            }
            R[i] = tmp - i;
        }else if(i != 0 && R[i-1] >= 2){
            R[i] = R[i - 1] - 1;
        }else{
            R[i] = 0;
        }
    }

    for (int i = N-1; i > 0; i--)
    {
        if (s[i] == 'L' && (i == N - 1 ||L[i + 1] < 2))
        {
            int tmp = i - 1;
            while (s[tmp] == 'L')
            {
                tmp--;
            }
            L[i] = i - tmp;
        }
        else if (L[i + 1] >= 2 && i != N - 1)
        {
            L[i] = L[i + 1] - 1;
        }
        else
        {
            L[i] = 0;
        }
    }

    for (int i = 0; i < N;i++){
        if(R[i] != 0){
            if(R[i] % 2 == 1){
                ans[R[i] + i - 1]++;
            }else{
                ans[R[i] + i]++;
            }
        }
    }
    for (int i = N - 1; i > 0;i--){
        if(L[i] != 0){
            if(L[i] % 2 == 1){
                ans[i - L[i]+1]++;
            }else{
                ans[i - L[i]]++;
            }
        }
    }

    for (int i = 0; i < N;i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
