#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> k(M);
    for (int i = 0; i < M;i++){
        int size;
        cin >> size;
        k[i].resize(size);
        for (int j = 0; j < size;j++){
            int a;
            cin >> a;
            a--;
            k[i][j] = a;
        }
    }

    vector<int> p(M);
    for (int i = 0; i < M;i++)
        cin >> p[i];

    int ans = 0;
    for (int bit = 0; bit < (1 << N);bit++){
        bool ok = true;
        for (int m = 0;m < M;m++){
            int c = 0;
            for(auto v: k[m]){
                if(bit & (1 << v))
                    c++;
            }
            if(c % 2 != p[m])
                ok = false;
        }
        if(ok)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
