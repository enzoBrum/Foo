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
    vector<vector<bool>> ships(10, vector<bool>(10));
    

    bool sucess = true;
    while (n-- && sucess) {
        int d, l, r, c;
        cin >> d >> l >> r >> c;

        int x1, x2, y1, y2;
        if (!d) {
            x1 = x2 = r;
            y1 = c;
            y2 = c + l - 1;
        }
        else {
            x1 = r;
            x2 = r + l - 1;
            y1 = y2 = c;
        }

        x1--;x2--;y1--;y2--;
        // cout << "FOO: " << x1 << ' ' << x2 << ' ' << y1 << ' ' << y2 << '\n';

        if (x1 < 0 || x1 > 9 || x2 < 0 || x2 > 9 || y1 < 0 || y1 > 9 || y2 < 0 || y2 > 9 ) {
            sucess = false;
            break;
        }

        for (int i = y1; i <= y2; ++i) {
            for (int j = x1; j <= x2; ++j) {
                // cout << "BAR: " << i << ' ' << j << " = " << ships[i][j] << '\n';
                if (ships[i][j]) sucess = false;
                else {
                    ships[i][j] = true;
                }
            }
        }
    }

    if (sucess) cout << 'Y';
    else cout << 'N';


    return 0;
}
