#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <iomanip>

#define sz(x) (int(x.size()))
#define fast_io()            \
  {                          \
    ios::sync_with_stdio(0); \
    cin.tie(NULL);           \
  }
#define mult_vec(name, T, n, m) \
  std::vector<std::vector<T>> name(n, std::vector<T>(m))
// #define DB

#ifdef DB
#define DEBUG(s) std::cout << s << '\n';
#else
#define DEBUG(s) ;
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
typedef std::vector<std::vector<std::string>> vvs;
typedef std::vector<char> vc;
typedef std::vector<std::vector<char>> vvc;
typedef std::vector<std::vector<std::string>> vvs;
typedef std::vector<bool> vb;
typedef std::vector<std::vector<bool>> vvb;
typedef std::vector<ll> vll;
typedef std::vector<ull> vull;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;
typedef std::pair<ull, ull> pull;
typedef std::vector<pii> vpii;
typedef std::vector<pll> vpll;
typedef std::vector<pull> vpull;
typedef std::vector<std::vector<int>> vvii;
typedef std::vector<std::vector<ll>> vvll;
typedef std::vector<std::vector<ull>> vvull;
typedef std::vector<std::vector<pii>> vvpii;
typedef std::vector<std::vector<pll>> vvpll;
typedef std::vector<std::vector<pull>> vvpull;

using namespace std;

int main() {
    fast_io();

    int n;
    bool first = true;
    while (cin >> n) {
        if (!n) break;

        if (first) first = false;
        else cout << '\n';

        int k;
        cin >> k;

        vpii players(n, {0,0});

        for (int i = 0; i < k*n*(n-1)/2; ++i) {
            int p1, p2;
            string c1, c2;
            cin >> p1 >> c1 >> p2 >> c2;

            int winner = 0;
            if (c1 == c2) continue;

            if ((c1 == "rock" && c2 == "scissors") || (c1 == "paper" && c2 == "rock") || (c1 == "scissors" && c2 == "paper"))
                winner = 1;
            else
                winner = 2;

            if (winner == 1) {
                players[p1-1].first++;
                players[p2-1].second++;
            } else {
                players[p1-1].second++;
                players[p2-1].first++;
            }
        }

        for (auto&[w, l] : players) {
            if (w + l == 0) cout << "-\n";
            else cout << fixed << setprecision(3) << ((double)w/(w+l)) << '\n';
        }
        
    }

    return 0;
}
