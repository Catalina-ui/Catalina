#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<long long> A(N);
    long long sum = 0;
    long long S = 0;
    for(int i = 0;i <N; i++){
        cin >> A[i];
        S += A[i];
        if(i%2 == 1)
            sum += A[i];
    }
    vector<long long> ans(N);
    ans[0] = S - 2 * (sum);
    cout << ans[0] << " ";
    for (int i = 1; i < N;i++){
        ans[i] = 2*A[i - 1] - ans[i - 1];
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
