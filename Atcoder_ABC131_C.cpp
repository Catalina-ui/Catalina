#include <iostream>
using namespace std;
typedef long long ll;

ll A, B, C, D;

ll u(ll x,ll y){
    if(x < y)
        swap(x, y);
    ll t = x * y;
    ll r = x % y;
    while(r != 0){
        x = y;
        y = r;
        r = x % y;
    }
    return t / y;
}

int main(){
    cin >> A >> B >> C >> D;
    ll s = u(C, D);
    A--;
    A = A - (A / C + A / D - A / s);
    B = B - (B / C + B / D - B / s);
    cout << B - A << endl;
    return 0;
}
