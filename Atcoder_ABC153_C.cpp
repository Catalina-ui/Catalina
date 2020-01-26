#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <map>
#include <queue>
#include <math.h>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    ll N, K;
    cin >> N >> K;
    vector<ll> H(N);
    for (int i = 0; i < N;i++){
        cin >> H[i];
    }
    sort(H.begin(), H.end());
    ll size = H.size();
    ll ans = 0;
    for (int i = 0; i < size-K;i++){
        ans += H[i];
    }
    cout << ans << endl;
    return 0;
}
