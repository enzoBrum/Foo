#include <iomanip>
#include <numeric>
#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<unordered_map>
#include<utility>
#include <cmath>

using namespace std;

typedef unsigned long long ull;

const double error = 1e-6;


double func(double x, double p, double q, double r, double s, double t, double u) {
  return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int p, q, r, s, t, u;
  while (cin >> p >> q >> r >> s >> t >> u) {
    double lo = 0, hi = 1;
    double lo_ans = func(lo, p, q, r, s, t ,u), hi_ans = func(hi, p, q, r, s, t, u);
    double mid;

    if (fabs(lo_ans) <= error) {
      cout << fixed << setprecision(4) << lo << '\n';
      continue;
    }
    if (fabs(hi_ans) <= error) {
      cout << fixed << setprecision(4) << hi << '\n';
      continue;
    }

    bool success = false;
    while ( hi - lo > 1e-9 ) {
      mid = (lo+hi)/2;

      double ans = func(mid, p, q, r, s, t, u);

      if (fabs(ans) <= error) {
        success = true;
        break;
      }
      
      if (ans < 0)
        hi = mid;
      else
        lo = mid;
    } 
    
    if (success)
      cout << fixed << setprecision(4) <<  mid << '\n';
    else
      cout << "No solution\n";
  }

}