#include <numeric>
#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<unordered_map>
#include<utility>
#include <cmath>

using namespace std;

typedef unsigned long long ull;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  while (cin >> n && n) {
    vector<int> vec;
    while (n--) {
      int aux; cin >> aux;
      if (aux)
        vec.push_back(aux);
    }

    if (!vec.size())
      vec.push_back(0);

    for (int i = 0; i < vec.size(); ++i) {
      cout << vec[i];
      if (i != vec.size()-1) cout << ' ';
      else cout << '\n';
    }

    
  }
}