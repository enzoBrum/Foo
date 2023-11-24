#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<unordered_map>
#include<utility>

using namespace std;

typedef unsigned long long ull;



int solve(vector<vector<int>>& matrix, int l, int u) {
  int ans = 0;
  for (int i = 0; i < matrix.size(); ++i) {
    auto it = lower_bound(matrix[i].begin(), matrix[i].end(), l);
    if (it == matrix[i].end() || *it > u ) continue;

    int j = it - matrix[i].begin();
    int curr_size = ans;

    int N = matrix.size();
    int M = matrix[i].size();
    while (i + curr_size < N && j + curr_size < M) {
      if (matrix[i + curr_size][j+curr_size] <= u) {
        curr_size++;
        continue;
      } 
      break;
    }

    ans = max(ans, curr_size);
  }

  return ans;
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
	int n, m;
	while (cin >> n >> m && n && m) {
    vector<vector<int>> matrix(n, vector<int>(m, 0));

    for (auto& row : matrix)
      for (auto& col : row)
        cin >> col;

		int q; cin >> q;
		while (q--) {
			int l, u;
			cin >> l >> u;

			int ans = solve(matrix, l, u);
			cout << ans << '\n';

		}
		cout << "-\n";
	}	
}
