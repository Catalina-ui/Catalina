#include <iostream>
#include <math.h>
using namespace std;

long long N,ans;

int main(){
    cin >> N;
    long long a = 1, b = N,ab = b + a - 2;
    for (long long i = 1; i * i <= N;i++){
        if(N % i == 0){
            if(ab > i + N/i - 2){
                a = i;
                b = N / i;
                ab = a + b - 2;
            }
        }
    }
    cout << ab << endl;
    return 0;
}
