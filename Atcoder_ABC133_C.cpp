#include <iostream>
using namespace std;
typedef unsigned long long ll;

int main(){
    ll L, R;
    cin >> L >> R;
    ll ans = 2000000001;
    if(R - L > 2019){
        ans = 0;
    }else{
        for (ll i = L; i < R;i++){
            ll Rmod = i % 2019;
            for (ll j = i + 1; j < R + 1;j++){
                ll Lmod = j % 2019;
                ll mod = (Rmod * Lmod) % 2019;
                if(mod < ans){
                    ans = mod;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
