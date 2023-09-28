#include<numeric>
#include<algorithm>
#include<iostream>
#include<vector>
#include<sstream>
#include<unordered_map>
#include<array>
#include<tuple>
#define fast_io()            \
  {                          \
    ios::sync_with_stdio(0); \
    cin.tie(NULL);           \
  }

using namespace std;

bool verify(string& s, vector<array<int,3>>& constraints) {
    for (auto& arr : constraints) {
        int a = -1;

        int ca = arr[0];
        int cb = arr[1];
        int dist = arr[2];
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] - '0' == ca || s[i] - '0' == cb) {
                if (a == -1) {
                    a = i;
                    continue;
                }
                if (dist > 0) {
                    if (i - a > dist) return false;
                    break;
                }

                // :cout << s <<  ' ' << i - a << '-' << dist<< '\n';
                
                if (i - a  < abs(dist)) return false;
                break;
            }
        }
    }

    return true;
}


int main() {
    int n, m;

    while (cin >> n >> m && (n || m)) {
        string teens;
        for (int i = 0; i < n; ++i)
            teens.push_back('0' + i);

        vector<array<int,3>> constraints;

        for (int i = 0; i < m; ++i) {
            int a, b, c;
            cin >> a >> b >> c;

            array<int,3> tmp = {a, b, c};
            constraints.push_back(tmp);
        }

        int ans = 0;

        do {
            if (verify(teens, constraints))
                ans++;
        } while (next_permutation(teens.begin(), teens.end()));

        cout << ans << '\n';
    }
}
