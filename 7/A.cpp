#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<unordered_map>
#include<utility>

using namespace std;

typedef unsigned long long ull;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  while (cin >> n && n) {
    int curr = 0, ans = 0;

    while (n--) {
      int val; cin >> val;

      curr = (curr + val < val) ? val : curr + val;
      ans = max(ans, curr);
    }

    ans = max(ans, curr);
    ans = max(ans, 0);

    if (ans == 0)
      cout << "Losing streak.\n";
    else
      cout << "The maximum winning streak is " << ans << ".\n";
  }

}
