#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N,M, ac = 0,pn= 0;

int main()
{
    cin >> N >> M;
    vector<int> p(M);
    vector<bool> s(M);
    for (int i = 0; i < M;i++){
        int A;
        string S;
        cin >> A >> S;
        A--;
        p[i] = A;
        if(S == "AC"){
            s[i] = true;
            
        }else{
            s[i] = false;
        }
    }
    vector<bool> t(N, false);
    vector<int> wa(N, 0);
    for (int i = 0; i < M; i++)
    {
        if(s[i] == true){
            if(t[p[i]] == false)
                ac++;
            t[p[i]] = s[i];
        }
        if(t[p[i]] == false){
            wa[p[i]]++;
        }
    }
    for (int i = 0; i < N;i++){
        if(t[i])
            pn += wa[i];
    }

        cout << ac << " " << pn << endl;
    return 0;
}
