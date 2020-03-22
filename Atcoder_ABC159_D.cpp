#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<long long> con(N, 0);
    vector<long long> sam(N,0);
    vector<long long> ke(N+1,0);
    vector<bool> ch(N, false);
    for (long long i = 1; i <= N;i++){
        ke[i] = i * (i - 1) / 2;
    }
    for (int i = 0; i < N;i++){
        cin >> sam[i];
        con[sam[i]]++;
    }
    long long ans = 0;
    for (int i = 0; i < N;i++){
        if(ch[sam[i]] == false){
            ans += ke[con[sam[i]]];
            ch[sam[i]] = true;
        }
    }

    for (int i = 0; i < N; i++)
    {
        if(ke[con[sam[i]]] > 0)
            cout << ans - (ke[con[sam[i]]] - ke[con[sam[i]] - 1]) << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
