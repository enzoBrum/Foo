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
typedef long long ll;

ll convert_to_bill(ll consumed) {
  ll ret = 0;

  if (consumed <= 100)
    return consumed*2;

  ret += 200;
  consumed -= 100;

  if (consumed <= 10000 - 100)
    return ret + consumed*3;

  ret += (10000-100)*3;
  consumed -= (10000-100);

  if (consumed <= 1000000 - 10000 - 100)
    return ret + consumed*5;

  consumed -= (1000000 - 10000 - 100);
  ret += (1000000 - 10000 - 100)*5;

  return ret + consumed*7;
}


ll convert_to_consumed(ll bill) {
  ll consumed = 0;

  if (bill <= 200)
    return bill/2;

  consumed = 100;
  bill -= 200;

  if (bill <= 3*9900)
    return consumed + bill/3;

  consumed += 9900;
  bill -= 9900*3;

  if (bill <= (1000000 - 10000 - 100)*5)
    return consumed + bill/5;

  consumed += (1000000 - 10000 - 100);
  return consumed + bill/7;
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // A = x + y
  // B = abs(x-y)
  
  ll a, b;
  while (cin >> a >> b && a && b) {
    // Estranhamente parecido com o método da bissecção
    // se considerar f(x,y) = abs(x-y) - B

    // a = convert_to_consumed(a);

    ll l = 0, r = a;
    ll ans = 0;
    while (l <= r) {
      ll mid = (l+r)/2;

      ll neigh_consumed = a - mid;
      if (neigh_consumed < 0) {
        r = mid - 1;
        continue;
      }

      ll my_bill = convert_to_bill(mid);
      ll neigh_bill = convert_to_bill(neigh_consumed);

      ll diff = abs(my_bill - neigh_bill);
      if (diff == b) {
        ans = mid;
        break;
      }
      
      if (diff < b)
        l = mid + 1;
      else
        r = mid - 1;
    }

    cout << convert_to_bill(ans) << '\n';
  }

}
