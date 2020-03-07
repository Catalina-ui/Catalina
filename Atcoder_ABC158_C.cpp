#include <iostream>
#include <vector>
using namespace std;

int main(){
    double a, b;
    cin >> a >> b;
    int ans = 10000;
    for (int i = 1; i < 10000;i++){
        if(int((double)i * 0.08) == a && int((double)i * 0.1) == b && ans > i)
            ans = i;
    }
    if(ans == 10000)
        ans = -1;
    cout << ans << endl;
    return 0;
}
