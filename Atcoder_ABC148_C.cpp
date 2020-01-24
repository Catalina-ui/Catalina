#include <iostream>
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
    long long a, b;
    cin >> a >> b;
    long c = a * b;
    long d = euclidean_gcd(a, b);
    cout << c / d << endl;
    return 0;
}
