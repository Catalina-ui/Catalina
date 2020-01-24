#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long long N;
    cin >> N;
    unordered_map<string, long long > mp;
    long long cnt = 0;
    long long  ans = 0;
    long long  index = 0;
    vector<long long > vec(N, 0);
    while(cnt < N){
        string s;
        cin >> s;
        vector<char> ch(10);
        for (long long  i = 0; i < 10;i++)
            ch[i] = s[i];
        sort(ch.begin(), ch.end());
        for (long long  i = 0; i < 10;i++)
            s[i] = ch[i];
        auto itr = mp.find(s);
        if(itr != mp.end()){
            vec[mp.at(s)]++;
            ans += vec[mp.at(s)];
        }else{
            mp[s] = index;
            index++;
        }
        cnt++;
    }
    cout << ans << endl;
    return 0;
}

