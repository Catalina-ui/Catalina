#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    string S, T;
    cin >> S >> T;

    map<char, vector<long long>> mp;
    for (long long i = 0; i < (long long)S.size();i++)
        mp[S[i]].push_back(i);
    
    for(auto t:T){
        if(mp[t].size() == 0){
            cout << -1 << endl;
            return 0;
        }
    }
    long long sum = 0, pre = -1;
    for(auto t:T){
        auto&& vec = mp[t];
        auto&& now = upper_bound(vec.begin(), vec.end(), pre);
        if(now == vec.end() || *now <= pre){
            sum++;
            pre = vec.front();
        }else{
            pre = *now;
        }
    }
    cout << sum * (long long)S.size() + pre + 1 << endl;
    return 0;
}
