#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
using namespace std;

vector<long long> s(5);
int main(){
    long long N;
    cin >> N >> s[0] >> s[1] >> s[2] >> s[3] >> s[4];
    sort(s.begin(), s.end());
    long long ans = ceil((double)N / s[0]) + 4;
    cout << ans << endl;
    return 0;
}
