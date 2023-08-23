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
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

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

    int l, c;
    cin >> l >> c;

    vvc vec(l, vc(c));
    
    for (int i = 0; i < l; ++i) {
        string word;
        cin >> word;

        for (int j = 0; j < c; ++j)
            vec[i][j] = word[j];
    }


    int n;
    cin >> n;

    vi words(n);
    for (int i = 0; i < words.size(); ++i) {
        string word; cin >> word;
        sort(word.begin(), word.end());
        words[i] = hash<string>()(word);
    }


    


    return 0;
}
