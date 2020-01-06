#include <iostream>
#include <map>
#include <vector>
#include <utility>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    int min = 0, max = 100001;
    for (int i = 0; i < M;i++){
        int l, r;
        cin >> l >> r;
        if(min < l)
            min = l;
        if(r < max)
            max = r;
    }
    int ans = max - min + 1;
    if(ans < 0)
        ans = 0;
    cout << ans << endl;
    return 0;
}
