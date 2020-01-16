#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;
    vector<unsigned long long> A(N);
    priority_queue<unsigned long long> B;
    for (int i = 0; i < N;i++){
    cin >> A[i];
    B.push(A[i]);
    }
    for (int i = 0; i < M;i++){
        unsigned long long tmp = B.top();
        B.pop();
        if(tmp != 0){
            B.push(tmp / 2);
        }else{
            B.push(0);
        }
    }

    unsigned long long ans = 0;
    for (int i = 0; i < N;i++){
        ans += B.top();
        B.pop();
    }
    cout << ans << endl;
    return 0;
}
        
