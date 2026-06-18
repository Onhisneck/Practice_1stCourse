#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    string encrypted;
    cin >> encrypted;

    for (int step = 0; step < k; step++) {
        string current = encrypted;
        for (int i = 0; i < n; i++) {
            encrypted[p[i] - 1] = current[i];
        }
    }

    cout << encrypted << "\n";

    return 0;
}
