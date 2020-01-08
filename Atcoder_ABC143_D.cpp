#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool triangle(int a,int b,int c){
    bool ch = true;
    if(a + b <= c)
        ch = false;
    if(a + c <= b)
        ch = false;
    if(b + c <= a)
        ch = false;
    return ch;
}

int main(){
    int N;
    cin >> N;
    vector<int> L(N);
    for (int i = 0; i < N;i++)
        cin >> L[i];
    sort(L.begin(), L.end());
    int ans = 0;
    for (int i = 0; i < N-1;i++)
        for (int j = i + 1; j < N;j++){
            int l = j + 1;
            int r = N - 1;
            while(r - l > -1){
                int mid = (l + r) / 2;
                if(triangle(L[i],L[j],L[mid])){
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }
            if (triangle(L[i], L[j], L[r])){
                ans += r - j;
            } 
        }
    cout << ans << endl;
    return 0;
}
