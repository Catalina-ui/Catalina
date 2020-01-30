#include <iostream>
typedef long long ll;
using namespace std;

int main(){
    ll N;
    cin >> N;

    ll ans = 0;

    if(N % 2){
        cout << 0 << endl;
        return 0;
    }else{
        ll t = 10;
        while((N / t)){
            ans += (N / t);
            t *= 5;
        }
    }
    cout << ans << endl;
    return 0;
}
