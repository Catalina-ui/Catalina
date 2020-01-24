#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> d(N,0);

    for (int i = 0; i < N;i++)
        cin >> d[i];

    sort(d.begin(), d.end());

    int ans = 0;
    int t = N / 2 - 1;
    if(d[t] == d[t+1]){
        ans = 0;
    }else{
        ans = d[t + 1] - d[t];
    }
    cout << ans << endl;
    return 0;
}
