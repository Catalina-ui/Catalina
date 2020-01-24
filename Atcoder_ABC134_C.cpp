#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N;i++)
        cin >> A[i];

    int maxvl, maxid,maxvls;
    maxvl = 0;
    maxvls = 0;
    for (int i = 0; i < N;i++){
        if(maxvl < A[i]){
            maxvl = A[i];
            maxid = i;
        }
        if(maxvls < A[i] && maxid != i && A[i] <= maxvl)
            maxvls = A[i];
    }
    for (int i = 0; i < N;i++){
        if(i != maxid){
            cout << maxvl << endl;
        }else{
            cout << maxvls << endl;
        }
    }
    return 0;
}
