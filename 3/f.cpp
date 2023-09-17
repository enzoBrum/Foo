
#include<bitset>
#include<stack>
#include<stack>
#include<functional>
#include<numeric>
#include<queue>
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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
  
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

using namespace __gnu_pbds;
typedef tree<int, null_type, std::less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
  

using namespace std;


int main() {
  fast_io();

  while (1) {
    int n, m;
    cin >> n >> m;
    if (n+m == 0) break;


    bitset<1000001> minutes;

    bool sucess = true;
    while (n--) {
      int s, e;
      cin >> s >> e;

      for (int i = s; i < e; ++i) {
        if (minutes.test(i)) {
          sucess = false;
          break;
        }

        minutes.set(i);
      }
    }

    while (m--) {
      int s, e, r;
      cin >> s >> e >> r;

      while ( e <= (int) 1e6 && sucess) {
        for (int i = s; i < e; ++i) {
          if (minutes.test(i)) {
            sucess = false;
            break;
          }

          minutes.set(i);
        }

        s += r;
        e += r;
      }
    }

    if (sucess) cout << "NO CONFLICT\n";
    else cout << "CONFLICT\n";  
  }

  return 0;
}
