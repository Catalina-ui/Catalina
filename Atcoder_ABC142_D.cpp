#include <iostream>
using namespace std;

unsigned long long gcd(unsigned long long a,unsigned long long b){
    if (a < b)
        return gcd(b, a);
    unsigned long long r;
    while ((r = a % b))
    {
        a = b;
        b = r;
    }
    return b;
}

int main(){
    unsigned long long a, b;
    cin >> a >> b;
    
    unsigned long long tmp = gcd(a,b);
    int cnt = 1;
    for (unsigned long long cut = 2; cut * cut < tmp ;++cut){
        if(tmp % cut == 0){
        while(tmp % cut == 0)tmp /= cut;
        cnt++;
        }
    }
    if(tmp != 1)
        cnt++;

    cout << cnt << endl;
}
