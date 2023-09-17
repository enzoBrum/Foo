#include<iomanip>
#include<iostream>
#include<vector>
#include<map>
#include<set>

using namespace std;

int main() {
    int k; cin >> k;
    int t = 0;
    while (k--) {
        t++;
        int n; cin >> n;

        vector<int> friends(n);
        map<int, set<int>> mp;

        for (int i = 0; i < n; ++i) {
            int m; cin >> m;
            for (int j = 0; j < m; ++j) {
                int stamp; cin >> stamp;
                if (mp.count(stamp))
                    mp[stamp].insert(i);
                else
                    mp[stamp] = {i};
            }
        }
        int unique = 0;
        for (auto&[label, st] : mp) {
            if (st.size() == 1) {
                unique++;
                friends[*st.begin()]++;
            }
        }

        cout << "Case " << t << ": ";
        for (int i = 0; i < friends.size(); ++i) {
            double percent = (double)friends[i]/unique * 100;
            cout << fixed << setprecision(6) << percent << "%";

            if (i != friends.size() - 1)
                cout << " ";
            else
                cout << '\n';
        }
    }
}
