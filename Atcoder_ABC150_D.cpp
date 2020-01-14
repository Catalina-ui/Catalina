#include <iostream>
#include <math.h>
#include <vector>
typedef long long ll;
using namespace std;

ll gcd(ll n1, ll n2){
    return n2 == 0 ? n1 : gcd(n2, n1 % n2);
}

ll lcm(ll n1,ll n2){
    return n1 / gcd(n1, n2) * n2;
}

int main(){
    ll N, M;
    cin >> N >> M;
    ll sum = 1;
    bool ch = false;
    vector<ll> A(N);
    for (int i = 0; i < N;i++)
        cin >> A[i];

    int cnt = 0;
    for (int i = 0; i < N; i++){
        int tmp = 0;
        int a = A[i];
        A[i] /= 2;
        while(a % 2 == 0){
            a /= 2;
            tmp++;
        }
        if(i != 0 && tmp != cnt){
            ch = true;
        }
        cnt = tmp;
    }
    if(ch){
        cout << 0 << endl;
        return 0;
    }

    for (int i = 0; i < N;i++)
        sum = lcm(sum,A[i]);

    ll ans = M / sum;
    ans = ans / 2 + ans % 2;
    cout << ans << endl;
    return 0;
}
