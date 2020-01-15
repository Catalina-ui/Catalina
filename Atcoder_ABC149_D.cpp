#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int N, K, r, s, p;
    cin >> N >> K >> r >> s >> p;
    string T; cin >> T;
    int tsize = T.size();
    vector<char> ans(tsize,' ');
    long a = 0;
    for (int i = 0; i < tsize; i++){
        if(i > K-1){
            if(T[i] == 'r' && ans[i-K] != 'p')
                ans[i] = 'p';
            if (T[i] == 's' && ans[i - K] != 'r')
                ans[i] = 'r';
            if (T[i] == 'p' && ans[i - K] != 's')
                ans[i] = 's';
        }else{
            if(T[i] == 'r')
                ans[i] = 'p';
            if (T[i] == 's')
                ans[i] = 'r';
            if (T[i] == 'p')
                ans[i] = 's';
        }
    }
    for (int i = 0; i < tsize;i++){
        if(ans[i] == 'r')
            a += r;
        if(ans[i] == 's')
            a += s;
        if(ans[i] == 'p')
            a += p;
    }
    cout << a << endl;
    return 0;
}
