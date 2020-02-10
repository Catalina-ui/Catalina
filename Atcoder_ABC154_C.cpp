#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    long long N;
    cin >> N;
    vector<long long> C;
    for (int i = 0; i < N;i++){
        long long a;
        cin >> a;
        C.emplace_back(a);
    }
    sort(C.begin(), C.end());
    for (int i = 0; i < N - 1;i++){
        if(C[i] == C[i+1]){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;

}
