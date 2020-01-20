#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int W, H, x, y;
    cin >> W >> H >> x >> y;
    cout << fixed << setprecision(15);
    cout << (double)W * H / 2.0 << " " << (W == x + x && H == y + y) << endl;
    return 0;
}
