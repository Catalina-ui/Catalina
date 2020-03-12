#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string S;
    cin >> S;
    int s = (int)S.size();

    int t = 0, ans = 0;
    for (int i = 0; i < s;i+= 2){
        if(S[i] != '1')
            t++;
        if(i + 1 < s && S[i+1] != '0')
            t++;
    }
    for (int i = 0; i < s; i += 2)
    {
        if (S[i] != '0')
            ans++;
        if (i + 1 < s && S[i + 1] != '1')
            ans++;
    }
    cout << min(ans, t) << endl;
    return 0;
}
