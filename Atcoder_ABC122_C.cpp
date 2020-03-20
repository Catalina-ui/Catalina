#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int N, Q;
    string S;
    string ac = "AC";
    cin >> N >> Q >> S;
    vector<int> vp(N,0);
    for (int i = 1; i < N;i++){
        vp[i] = vp[i - 1];
        if(S[i-1] == 'A' && S[i] == 'C')
            vp[i]++;
    }

    vector<int> right(0);
    vector<int> left(0);
    for (int i = 0; i < Q;i++){
        int r,l;
        cin >> l >> r;
        l--, r--;
        left.emplace_back(l);
        right.emplace_back(r);
    }
    for (int i = 0; i < Q;i++){
        cout << vp[right[i]] - vp[left[i]] << endl;
    }
    return 0;
}
