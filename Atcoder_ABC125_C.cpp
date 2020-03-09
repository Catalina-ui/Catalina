#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
typedef long long ll;
#define rep(a, n) for (int i = a; i < n;i++)

ll gcd(ll n1, ll n2)
{
    return n2 == 0 ? n1 : gcd(n2, n1 % n2);
}

int main(){
    ll N, ans = 0;
    cin >> N;
    vector<ll> A(N), R(N+1), L(N+1);
    rep(0, N) cin >> A[i];
    L[1] = A[0], R[N - 1] = A[N - 1];

    rep(0,N-1){
        L[i + 2] = gcd(A[i + 1], L[i + 1]);
        R[N - 2 - i] = gcd(R[N - i - 1], A[N - 2 - i]);
    }
    L[0] = R[N-1],R[N] = R[1];
    rep(0,N){
        ans = max(ans, gcd(L[i], R[i + 1]));
    }
    cout << ans << endl;
    return 0;
}
