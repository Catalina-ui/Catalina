#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> B(N-1);

    for (int i = 0; i < N - 1;i++)
        cin >> B[i];

    long int sum = 0;
    for (int i = 0; i < N - 2;i++){
        if(B[i] >= B[i+1]){
            sum += B[i + 1];
        }else{
            sum += B[i];
        }
    }
    sum += B[0];
    sum += B[N - 2];
    cout << sum << endl;
    return 0;
}
