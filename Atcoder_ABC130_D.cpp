#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll N, K;

int main(){
    cin >> N >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    ll ans = 0, sum = 0,r = 0;
    for (int i = 0; i < N;i++){
        while (sum < K)
        {
            if (r == N)
                break;
            else{
            sum += A[r];
            r++;
            }
        }
        if (sum < K)
            break;
        ans += N - r + 1;
        sum -= A[i];
    }
    cout << ans << endl;
    return 0;
}
