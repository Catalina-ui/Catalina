#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> zAlgorithm(string S){
    int size = S.size();
    vector<int> A(size,0);
    A[0] = S.size();
    int i = 1, j = 0;
    while(i < size){
        while(i + j < size && S[j] == S[i+j])
            j++;
        A[i] = j;
        if(j == 0){
            i++;
            continue;
        }
        int k = 1;
        while(i + k < size && k + A[k] < j)
            A[i + k] = A[k], k++;
        i += k, j -= k;
    }
    return A;
}

int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;

    int ans = 0;

    for (int i = 0; i < N;i++){
        auto str = zAlgorithm(S.substr(i));
        for (int j = 0; j < N - i;j++)
            ans = max(ans, min(str[j], j));
    }
    cout << ans << endl;
    return 0;
}
