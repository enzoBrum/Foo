#include<utility>
#include<cmath>
#include<map>
#include<algorithm>
#include<iostream>
#include<vector>
#include<sstream>
#include<unordered_map>

#define fast_io()            \
  {                          \
    ios::sync_with_stdio(0); \
    cin.tie(NULL);           \
  }

using namespace std;

int main() {
    fast_io();

    int n;
    int t = 0;
    while (cin >> n) {
        if (!n) break;
        t++;
        vector<int> vec(n);
        for (auto& v : vec) cin >> v;

        sort(vec.begin(), vec.end());

        int m; cin >> m;

        cout << "Case " << t << ":\n";
        while (m--) {
            int query; cin >> query;

            auto end = vec.end() - 1;

            auto begin = vec.begin();

            int nearest = 1e9;
            while (begin < end) {
                int sum = *begin + *end;

                if (sum == query) {
                    nearest = query;
                    break;
                }

                if (abs(sum - query) < abs(nearest - query))
                    nearest = sum;

                if (sum < query)
                    begin++;
                else
                    end--;
            }

            cout << "Closest sum to " << query << " is " << nearest << ".\n";
        }
    }
    
    return 0;
}
