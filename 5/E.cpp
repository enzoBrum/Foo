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

bool solve(vector<int>& vec, int goal, int n, int m) {
  int total = 1, curr = 0;
  for (int i = 0; i < n; ++i) {
    if (curr + vec[i] <= goal) {
      curr += vec[i];
    } else if (vec[i] > goal) {
      return false;
    } else {
      curr = vec[i];
      total++;
    }
    
    if (total > m) return false; 
  }

  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  while (cin >> n >> m) {
    vector<int> vec(n);

    for (auto& v : vec)
      cin >> v;

    int ans;
    int l = 0, r = accumulate(vec.begin(), vec.end(), 0);

    while (l <= r) {
      int mid = l + (r-l)/2;

      if (solve(vec, mid, n, m))
        r = mid-1;
      else
        l = mid+1;

      ans = mid;
    }

    if (!solve(vec, ans, n, m))
      ans++;
    cout << ans << '\n';
      
  }
}
