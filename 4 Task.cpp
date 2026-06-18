#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long k;
    if (!(cin >> n >> k)) return 0;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }

    string encrypted;
    cin >> encrypted;

    string decrypted = encrypted; // строка для результата
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            vector<int> cycle;
            int curr = i;
            while (!visited[curr]) {
                visited[curr] = true;
                cycle.push_back(curr);
                curr = p[curr];
            }

            int len = cycle.size();
            int shift = k % len;

            for (int j = 0; j < len; j++) {
                int encrypted_pos = cycle[j];
                int original_pos = cycle[(j + shift) % len];
                
                decrypted[original_pos] = encrypted[encrypted_pos];
            }
        }
    }

    cout << decrypted << "\n";

    return 0;
}
