#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll mod = 1000000007;

int main(){
    vector<ll> conv(100001, 1);
    conv[2]++;

    for (int i = 3; i < 100001;i++)
        conv[i] = (conv[i - 1] + conv[i - 2]) %mod;

    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    for (int i = 0; i < M;i++)
        cin >> A[i];

    ll ans = 1;
    ll t = 0;
    for (int i = 0; i < M;i++){
        if(t != 1 && A[i] == t)
        {
            cout << 0 << endl;
            return 0;
        }else{
            if(A[i] - t - 1 >= 0)
                ans = (ans * conv[(A[i] - t - 1)]) % mod;
            t = A[i] + 1;
        }
    }
    ans = (ans * conv[N - t]) % mod;
    cout << ans  << endl;
    return 0;
}
