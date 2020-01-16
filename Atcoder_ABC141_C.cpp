#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    long long N,K,Q;
    cin >> N >> K >> Q;
    vector<long int> B(N, 0);
    for (int i = 0; i < Q;i++){
        int a;
        cin >> a;
        B[a-1]++;
    }
    for (int i = 0; i < N;i++){
        if(B[i] + K > Q){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
        return 0;
}
