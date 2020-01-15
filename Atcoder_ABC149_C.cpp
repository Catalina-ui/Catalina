#include <iostream>
#include <math.h>
using namespace std;

bool IsPrime(int num)
{
    if (num < 2)
        return false;
    else if (num == 2)
        return true;
    else if (num % 2 == 0)
        return false; 

    double sqrnum = sqrt(num);
    for (int i = 3; i <= sqnum; i += 2)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main(){
    int a;
    cin >> a;
    int ans = 0;
    bool c = true;
    while(a <= 100003 && c){
        if(IsPrime(a)){
            ans = a;
            c = false;
            }
        a++;
    }
    cout << ans << endl;
    return 0;
}
