#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

int main(){
    int N, Q;
    string S;
    cin >> N >> S;

    set<int> alpha[26];
    for (int i = 0; i < 26;i++)
        alpha[i].insert(N + 1);
    for (int i = 0; i < N;i++)
        alpha[S[i] - 'a'].insert(i);

    cin >> Q;
    while(Q > 0){
        Q--;
        int q;
        cin >> q;
        if(q-1){
            int l, r;
            cin >> l >> r;
            int ans = 0;
            l--, r--;
            for (int i = 0; i < 26;i++){
                if (*alpha[i].lower_bound(l) <= r)
                    ans++;
            }
            cout << ans << endl;
        }else{
            int t;
            char c;
            cin >> t >> c;
            t--;
            if(S[t] != c){
                alpha[S[t] - 'a'].erase(t);
                S[t] = c;
                alpha[c - 'a'].insert(t);
            }
            
        }
    }
    return 0;
}
