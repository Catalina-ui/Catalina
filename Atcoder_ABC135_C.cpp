#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    long A[n+1];
    long B[n];

    for (int i = 0; i < n + 1;i++){
        cin >> A[i];
    }
    for (int i = 0; i < n;i++){
        cin >> B[i];
    }
    long sum = 0;

    for (int i = 0; i < n;i++){
        for (int j = 0; j < 2;j++){
            if(B[i] >= A[j+i]){
                B[i] -= A[j+i];
                sum += A[j+i];
                A[j+i] = 0;
            }else{
                sum += B[i];
                A[j+i] -= B[i];
                B[i] = 0;
            }
        }
    }
    cout << sum << endl;
    return 0;
}
