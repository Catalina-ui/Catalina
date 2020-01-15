#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<char> ans(0);
    int i = 0;
    while(i < N){
        char tmp = S[i];
        int t = 1;
        while (i + t < N && tmp == S[i + t])
            t++;
        ans.push_back(S[i]);
        i += t;
    }
    int A = ans.size();
    cout << A << endl;
    return 0;
}
