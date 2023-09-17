#include<algorithm>
#include<iostream>
#include<vector>
#include<sstream>
#include<unordered_map>
#include<array>

#define fast_io()            \
  {                          \
    ios::sync_with_stdio(0); \
    cin.tie(NULL);           \
  }

using namespace std;


struct Contestant {
    Contestant(int idd) {
        n_solved = 0;
        n_penalty = 0;
        id = idd;
        print = false;
        solved.fill(false);
        penalty.fill(0);
    }

    int n_solved;
    int n_penalty;
    int id;
    bool print;
    array<bool, 110> solved;
    array<int, 110> penalty;

    void add_problem(int p, int t, char L)  {
        print = true;
        if (solved[p]) return;
        if (L == 'C') {
            solved[p] = true;
            n_solved++;
            n_penalty += t + penalty[p];
        }
        else if (L == 'I') {
            penalty[p] += 20;
        }
    }
};

int main() {
   fast_io();

   int t;
   cin >> t;

   string throaway;
   getline(cin, throaway);
   getline(cin, throaway);
   for (int i = 0; i < t; ++i) {

    vector<Contestant> vec;
    for (int i = 0; i <= 100; ++i)
        vec.push_back(Contestant(i));
    while (true) {
            string line;
            getline(cin, line);
            if (line == "") break;

            stringstream buffer(line);

            int c, p, t;
            char L;
            buffer >> c >> p >> t >> L;
            vec[c].add_problem(p, t, L);

            if (cin.eof()) break;
        }
    
    sort(vec.begin(), vec.end(), [](const Contestant& a, const Contestant& b) {
        if (a.n_solved != b.n_solved) return a.n_solved > b.n_solved;

        if (a.n_penalty != b.n_penalty) return a.n_penalty  < b.n_penalty;

        return a.id < b.id;
    });

    for (auto& c : vec) {
        if (!c.print) continue;

        cout << c.id << ' ' << c.n_solved << ' ' << c.n_penalty << '\n';
    }
    if (i != t - 1)
    cout << '\n';
}

    
}
