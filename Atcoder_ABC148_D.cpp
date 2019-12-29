#include <iostream>
#include <vector>
using namespace std;

unsigned euclidean_gcd(unsigned a, unsigned b)
{
    if (a < b)
        return euclidean_gcd(b, a);
    unsigned r;
    while ((r = a % b))
    {
        a = b;
        b = r;
    }
    return b;
}

int main()
{
    long long N;
    cin >> N;
    vector<int> A(N, 0);

    for (int i = 0; i < N;i++)
        cin >> A[i];

    int num = 1;
    int ind = 0;
    while(ind < N){
        if(num == A[ind])
            num++;
        ind++;
    }
    int ans = -1;
    if(num != 1)
        ans = N - num + 1;
    cout << ans << endl;
    return 0;
}