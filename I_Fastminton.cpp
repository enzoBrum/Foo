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


void print_player(int g, int p, bool server) {
  cout << g << " (" << p;

  if (server) cout << "*";

  cout << ")";
}

char simulate_game(int& index, char server, char receiver, string& buffer, int& gl, int& gr) {
  int pl = 0, pr = 0;
  for (; index < buffer.size() && !((abs(pl-pr) > 1 && (pl > 4 || pr > 4)) || pl == 10 || pr == 10); index++) {
    char curr = buffer[index];      

    if (curr == 'Q') {
      print_player(gl, pl, server == 'l');
      cout << " - ";
      print_player(gr, pr, server == 'r');
      cout << '\n';
      continue;
    }
    else if (curr == 'S') {
      if (server == 'l') pl++;
      else pr++;
    }
    else if (curr == 'R') {
      if (receiver == 'l') pl++;
      else pr++;
      swap(server, receiver);
    }

    
  }

  if (pl > pr) gl++;
  else gr++;

  return (pl > pr) ? 'l' : 'r';
}

void simulate_match(string& buffer) {
  int gl = 0, gr = 0;
  char server = 'l', receiver = 'r';
  int index = 0;
  while (gl != 2 && gr != 2 && index < buffer.size()) {
    char winner = simulate_game(index, server, receiver, buffer, gl, gr);

    if (winner != server) swap(server, receiver);
  }

  for (; index < buffer.size(); ++index) {
    if (buffer[index] == 'Q') {
      cout << gl << ' ';
      if (gl > gr)
        cout << "(winner) ";
      cout << "- " << gr;
      if (gr > gl)
        cout << " (winner)";
    }
    
  }
}

int main() {
  fast_io();

  string buffer;
  getline(cin, buffer);
  simulate_match(buffer);


  return 0;
}
