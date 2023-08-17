#include<cmath>
#include <sstream>
#include<cstdint>
#include<iterator>
#include<vector>
#include <cstdio>
#include<iostream>
#include<map>
#include<set>
#include<utility>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<functional>
 
#define sz(x) (int (x.size()))
#define fast_io() {ios::sync_with_stdio(0); cin.tie(NULL);}
#define mult_vec(name,T,n,m) std::vector<std::vector<T>>name(n, std::vector<T>(m))
// #define DB 

#ifdef DB
  #define DEBUG(s) std::cout << s << '\n';
#else
  #define DEBUG(s);
#endif
 
typedef long long ll;
typedef unsigned long long ull;
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
typedef std::vector<std::vector<std::string>> vvs;
typedef std::vector<char> vc;
typedef std::vector<std::vector<char>> vvc;
typedef std::vector<std::vector<std::string>> vvs;
typedef std::vector<ll> vll;
typedef std::vector<ull> vull;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::pair<ull, ull> pull;
typedef std::vector<pi> vpi;
typedef std::vector<pll> vpll;
typedef std::vector<pull> vpull;
typedef std::vector<std::vector<int>> vvi;
typedef std::vector<std::vector<ll>> vvll;
typedef std::vector<std::vector<ull>> vvull;
typedef std::vector<std::vector<pi>> vvpii;
typedef std::vector<std::vector<pll>> vvpll;
typedef std::vector<std::vector<pull>> vvpull;
 
using namespace std;

int main() {
    fast_io();

    int n; cin >> n;
    string line;
    cin >> line;

    if (line.size() == 1) {
        cout << 0;
        return 0;
    }

    int ans = 0;
    int curr = 0;
    char last = '\0';

    for (auto& c : line) {
        if (c == last && c == 'a') curr++;
        else {
            ans += curr;
            if (curr) ans++;
            curr = 0;
            last = c;
        }
    }

    ans += curr;

    if (line.back() == 'a' && line[line.size()-2] == 'a') ans++;


    cout << ans;
    

    return 0;
}
