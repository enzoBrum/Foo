#include<list>
#include<numeric>
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


bool is_prime(int n) {
    if (n < 2) return false;
    
    int root = sqrt(n);
    bool prime = true;
    for (int i = 2; i <= root; ++i) {
        if (n % i == 0) {
            prime = false;
            break;
        }
    }
    
    return prime;
}

void sieve(list<int>& numbers) {
    auto mult = next(numbers.begin());

    while (mult != numbers.end()) {
        auto aux = next(mult);

        while (aux != numbers.end()){
            if (*aux % *mult == 0) aux = numbers.erase(aux);
            else aux++;
        }

        ++mult;
    }
}

int main() {
    fast_io();
    
    int t; cin >> t;

    while (t--) {
        int n, m;
        cin >> m >> n;

        for (; m <= n; ++m)
            if (is_prime(m))
                cout << m << '\n';
        cout << '\n';
    }

    return 0;
}
