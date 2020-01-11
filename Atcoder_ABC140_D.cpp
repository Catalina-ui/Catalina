#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N,K;
    cin >> N >> K;
    string S;
    cin >> S;
    int val = 0;

    for (int i = 0; i < N - 1;i++){
        if(S[i] == S[i+1])
            val++;
    }
    int tmp = N - val - 1;
    while(tmp > 1 && K > 0){
        val += 2;
        tmp -= 2;
        K--;
    }

    if(tmp == 1 && K != 0)
        val++;
    cout << val << endl;
    return 0;
}
