#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


long long mod = 1000000007;
long long N;
int main()
{
    cin >> N;

    vector<long long> A(N);
    vector<long long> ones(60, 0);
    for (int i = 0; i < N;i++){
        cin >> A[i];
        for (int j = 0; j < 60; j++)
        {
            if (A[i] & (1ll << j))
                ones[j]++;
        }
    }
    long long ans = 0;

    for (int i = 0; i < 60;i++){
        ans += (((ones[i] % mod) * ((N - ones[i])%mod)%mod) * ((1ll << i)%mod)%mod);
    }
    ans = ans % mod;

    cout << ans << endl;
    return 0;
}