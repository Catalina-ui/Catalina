#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;

int main(){
    int N;
    cin >> N;
    map<string, int> mp;
    int max = 0;
    vector<string> S(N);
    for (int i = 0; i < N;i++){
        cin >> S[i];
        mp[S[i]]++;
        if(max < mp[S[i]])
            max = mp[S[i]];
    }

    vector<string> ans(0);
    for (int i = 0; i < N;i++){
        if(mp[S[i]] == max)
            ans.push_back(S[i]);
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    
    for (int i = 0;i < (int)ans.size();i++){
        cout << ans[i] << endl;
    }
    return 0;
}
