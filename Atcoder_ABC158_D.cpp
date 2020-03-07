#include <iostream>
#include <vector>
#include <string>
#include <deque>
using namespace std;

int main(){
    deque<char> dq;
    string S;
    bool x = true;
    int Q;
    cin >> S >> Q;
    for (int i = 0; i < (int)S.size();i++)
        dq.emplace_back((char)S[i]);
    
    for (int i = 0; i < Q; i++)
    {
        int q;
        cin >> q;
        if (q - 1)
        {
            int f;
            char s;
            cin >> f >> s;
            if (f - 1)
            {
                if (x)
                    dq.emplace_back(s);
                else
                    dq.emplace_front(s);
            }
            else
            {
                if (x)
                    dq.emplace_front(s);
                else
                    dq.emplace_back(s);
            }
        }
        else
        {
            if (x)
                x = false;
            else
                x = true;
        }
    }

    if (x)
    {
        while (!dq.empty())
        {
            cout << dq.front();
            dq.pop_front();
        }
    }else{
        while (!dq.empty())
        {
            cout << dq.back();
            dq.pop_back();
        }
    }
    cout << endl;
    return 0;
}
