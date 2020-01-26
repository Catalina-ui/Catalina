#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <map>
#include <queue>
#include <math.h>

using namespace std;

typedef long long ll;

int main()
{
    ll H;
    cin >> H;
    ll ans = 0;
    ll t = 1;
    while(H > 1){
        ans += t;
        H /= 2;
        t *= 2;
    }
    ans += t;
    cout << ans << endl;
    return 0;
}
