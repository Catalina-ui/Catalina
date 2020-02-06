#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    vector<ll> F(N);
    for (int i = 0; i < N;i++)
        cin >> A[i];
    for (int i = 0; i < N;i++)
        cin >> F[i];

    sort(A.begin(), A.end());
    sort(F.begin(), F.end());
    reverse(F.begin(), F.end());

    vector<ll> B(N);
    for (int i = 0; i < N;i++)
        B[i] = A[i] * F[i];

    ll l = -1, r = 1e12+1;
    while(r - l > 1){
        ll mid = (r + l) / 2;
        ll cnt = 0;
        for (int i = 0;i < N;i++)
            cnt += max(0ll, A[i] - mid / F[i]);
        if(cnt <= K)
            r = mid;
        else{
            l = mid;
        }
    }
    cout << r << endl;
    return 0;
}
