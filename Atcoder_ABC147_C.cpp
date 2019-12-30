#include <iostream>
#include <vector>
#include <utility>
using namespace std;
using pint = pair<int, int>;

int max(int a,int b){
    if(a > b){
        return a;
    }else{
        return b;
    }
}

int N;
vector<vector<pint>> G;

bool judge(int bit){
    for (int i = 0; i < N;i++){
        if(!(bit & (1 << i)) )
            continue;

        for (pint xy : G[i]){
            int x = xy.first;
            int y = xy.second;

            if(y == 1 && !(bit & (1 << x)))
                return false;
            if(y == 0 && (bit & (1 << x)))
                return false;
        }
    }
    return true;
}

int main()
{
    cin >> N;
    G.resize(N);
    for (int i = 0; i < N;i++){
        int A;
        cin >> A;
        G[i].resize(A);
        for (int j = 0; j < A;j++){
            cin >> G[i][j].first >> G[i][j].second;
            G[i][j].first--;
        }
    }
    int res = 0;
    for (int bit = 0; bit < (1 << N);bit++){
        if(judge(bit)){
            int count = 0;
            for (int i = 0; i < N;i++){
                if(bit & (1 << i))
                    count++;
            }
            res = max(res, count);
        }
    }

    cout << res << endl;
}