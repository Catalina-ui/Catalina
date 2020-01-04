#include <iostream>
#include <utility>
#include <vector>
#include <math.h>
#include <iomanip>

using namespace std;

long double dist(long double a,long double b){
    return sqrt(a * a + b * b);
}

double N;
vector<pair<long double, long double>> pair_vec;
long double sum = 0;

int main(){
    cin >> N;
    pair_vec.resize(N);
    for (int i = 0; i < N;i++)
        cin >> pair_vec[i].first >> pair_vec[i].second;

    for (int i = 0; i < N - 1; i++)
        for (int j = i + 1; j < N; j++){
            long double dx = pair_vec[i].first  - pair_vec[j].first;
            long double dy = pair_vec[i].second - pair_vec[j].second;
            sum +=dist(dx,dy);
        }
    
    sum = (2.0 * sum) / N;
    cout << fixed << setprecision(15) << sum << endl;
    return 0;
}
