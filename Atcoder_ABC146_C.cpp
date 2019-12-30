#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

ll A, B, X;

ll h(ll N){
    return A * N + B * to_string(N).length();
}

int main(){
    cin >> A >> B >> X;
    if(A*(ll)1e9 + B *10 <= X){
        cout << (ll)1e9 << endl;
        return 0;
    }

    ll lb, rb, mid;
    lb = 0;
    rb = (ll)1e9;

    while(rb - lb > 1){
        mid = (lb + rb) / 2;
        if(h(mid) <= X){
            lb = mid;
            }else{
            rb = mid;
            }
    }
    cout << lb << endl;
    return 0;
}
