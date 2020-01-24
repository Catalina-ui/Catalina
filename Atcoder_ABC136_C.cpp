#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<long int> H(N);

    for (int i = 0; i < N;i++){
        cin >> H[i];
    }

    bool check = true;
    for (int i = 0; i < N-1;i++){
        if(H[i] < H[i+1]){
            check = true;
        }else if(H[i] == H[i+1]){
            check = check;
        }else if(H[i] - 1 == H[i+1] && check == true){
            check = false;
        }else{
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}
