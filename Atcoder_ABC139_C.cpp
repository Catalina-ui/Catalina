#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<long int> H(N);
    for (int i = 0; i < N;i++)
        cin >> H[i];
    int max = 0;
    bool check = true;
    int count = 0;
    for (int i = N - 1; i > 0;i--){
        if(H[i] <= H[i-1]){
            check = true;
            count++;
        }else{
            check = false;
        }
        if(check == false){
            count = 0;
            check = true;
        }
        if(count > max)
            max = count;
    }
    cout << max << endl;
    return 0;
}
