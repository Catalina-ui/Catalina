#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> P(N);
    for(int i = 0;i < N;i++)
        cin >> P[i];
    int ans = 0;
    int min = N+1;
    for(int i = 0;i < N;i++){
        if(P[i] > min)continue;
        else min = P[i];
        ans++;
        if(P[i] == 1)
            break;
    }
    cout << ans << endl;
    return 0;
}
