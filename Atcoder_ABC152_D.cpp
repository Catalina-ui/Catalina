#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

int main()
{
    int N ;
    cin >> N;
    int ans = 0;
    map<pair<int,int>,int> mp;
    for(int i = 1;i <= N;i++){
        int a,b;
        int tmp = i;
        if(tmp % 10 == 0)continue;
        a = tmp % 10;
        while(tmp >= 10){
            tmp /= 10;
        }
        b = tmp % 10;
        if(a == b){
            ans += 2 * mp[make_pair(a,b)] + 1;
            mp[make_pair(a,b)]++;
        }else{
            ans += 2*mp[make_pair(a,b)];
            mp[make_pair(b,a)]++;
        }
    }
    cout << ans << endl;
    return 0;
    
}
