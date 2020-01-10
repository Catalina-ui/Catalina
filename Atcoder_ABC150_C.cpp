#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> P(N);
    vector<int> Q(N);
    vector<int> p(N-1,0);
    vector<int> k(N - 1,1);
    int ke = 2;
    for (int i = N - 3; i >= 0;i--){
        k[i] *= ke * k[i + 1];
        ke++;
    }
    for (int i = 0; i < N;i++)
        cin >> P[i];
    for (int i = 0; i < N;i++)
        cin >> Q[i];

    for (int i = 0;i < N-1;i++){
        int t = P[i];
        int e = Q[i];
        for (int j = i + 1; j < N;j++){
            if(t > P[j])
                p[i]++;
            if (e > Q[j])
                p[i]--;
        }
    }
    int ans = 0;
    for (int i = 0; i < N - 1;i++){
        ans += p[i] * k[i];
    }
    if(ans < 0)
        ans = -ans;
    cout << ans << endl;
    return 0;
}
