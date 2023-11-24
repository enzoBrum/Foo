#include<iostream>
#include <numeric>
#include<vector>
#include<algorithm>
#include<sstream>
#include<unordered_map>
#include<utility>
#include <functional>

using namespace std;

typedef unsigned long long ull;


ull longest_subsequence(vector<int>& widths, vector<int>& heights, function<bool (int, int)> cmp) {
  vector<pair<int, int>> dp(heights.size());

  dp[0] = {1, widths[0]};
  for (int i = 1; i < heights.size(); ++i) {
    int curr_h = heights[i];
    int best_idx = -1;
    int best_val = 1;
    for (int j = 0; j < i; ++j) {
      if (cmp(curr_h, heights[j]) &&  dp[j].first + 1 >= best_val) {
        best_val = dp[j].first + 1;
        best_idx = j;
      }
    }

    dp[i] = {best_val, dp[best_idx].second + widths[i]};
  }

  int largest = 0;
  for (int i = 0; i < dp.size(); ++i)
    if (dp[i].first > largest) {
      largest = dp[i].first;
    }

  ull ans = 0;
  for (int i = 0; i < dp.size(); ++i) {
    if (dp[i].first != largest)
      continue;

    ans = max(ans, total_width(widths, dp, i));
  }

  return ans;
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tt;
  cin >> tt;

  for (int t = 0; t < tt; ++t) {
    int n; cin >> n;
    vector<int> heights(n), widths(n);
    for (auto& h : heights)
      cin >> h;
    for (auto& w : widths)
      cin >> w;

    auto lds_w = longest_subsequence(widths, heights, less<int>());
    auto lis_w = longest_subsequence(widths, heights, greater<int>());

    //
    //
    // unsigned long long lis_w = accumulate(vec_lis.begin(), vec_lis.end(), 0, [&widths](const int& val1, const int& val2) {return val1 + widths[val2];});
    // unsigned long long lds_w = accumulate(vec_lds.begin(), vec_lds.end(), 0, [&widths](const int& val1, const int& val2) {return val1 + widths[val2];});

    if (lis_w >= lds_w) {
      cout << "Case " << t+1 << ". Increasing (" << lis_w << "). Decreasing (" << lds_w << ").\n"; 
    } else {
      cout << "Case " << t+1 << ". Decreasing (" << lds_w << "). Increasing (" << lis_w << ").\n"; 
    }

  }
}
