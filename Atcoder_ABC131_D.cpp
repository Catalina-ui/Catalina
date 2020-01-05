#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main(){
    int N, A, B,max = 0;
    long int t = 0;
    cin >> N;
    priority_queue<pair<int, int>> q;
    for (int i = 0; i < N;i++){
        cin >> A >> B;
        if(B > max)
            max = B;
        t += A;
        q.push(make_pair(B, A));
    }
    if(t > max){
        cout << "No" << endl;
        return 0;
    }
    while(!q.empty()){
        int b = q.top().first;
        int a = q.top().second;
        q.pop();
        if(max < a){
            cout << "No" << endl;
            return 0;
        }
        if(max > b)
            max = b;
        max = max - a;
    }
    cout << "Yes" << endl;
    return 0;
}
