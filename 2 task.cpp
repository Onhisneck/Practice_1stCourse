#include <iostream>
#include <vector>

using namespace std;

// Глобальные массивы, потому что так проще
int matrix[1005][1005]; 
bool visited[1005];
int n, m;

void dfs(int v) {
    visited[v] = true;
    for (int i = 1; i <= n; i++) {
        // Проверяем связь через матрицу смежности
        if (matrix[v][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    // Ускорение ввода-вывода
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> m)) return 0;

   
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
        for (int j = 1; j <= n; j++) {
            matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        matrix[u][v] = 1;
        matrix[v][u] = 1; // граф ненаправленный
    }

    int components = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            components++;
            dfs(i); // Запускаем обход от новой компоненты
        }
    }

    // Минимальное число ребер для соединения K компонент — это K - 1
    cout << components - 1 << "\n";

    return 0;
}
