#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;


int main(){
    long long N;
    long long K;
    cin >> N >> K;
    vector<double> C;
    for (int i = 0; i < N;i++){
        long long a;
        cin >> a;
        C.emplace_back((a+1)/2.0);
    }
    double tmp = 0;
    for (int i = 0;i < K;i++)
        tmp += C[i];
    double ans = tmp;
    for (int i = K; i < N;i++){
        tmp -= C[i - K], tmp += C[i];
        ans = max(ans, tmp);
    }
    cout << std::fixed << std::setprecision(15);
    cout << ans << endl;
    return 0;
}
