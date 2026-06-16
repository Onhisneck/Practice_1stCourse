#include <iostream>
#include <vector>

using namespace std;

// Аккуратный DFS через список смежности, переданный по ссылке
void dfs(int vertex, const vector<vector<int>>& graph, vector<bool>& visited) {
    visited[vertex] = true;
    for (int neighbor : graph[vertex]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited);
        }
    }
}

int main() {
    // Оптимизация ввода-вывода для олимпиадных задач
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nodes, edges;
    if (!(cin >> nodes >> edges)) return 0;

    // Используем динамический список смежности вместо тяжелой матрицы
    vector<vector<int>> graph(nodes + 1);
    vector<bool> visited(nodes + 1, false);

    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int connected_components = 0;
    for (int i = 1; i <= nodes; ++i) {
        if (!visited[i]) {
            connected_components++;
            dfs(i, graph, visited);
        }
    }

    // Ответ: количество компонент минус один
    cout << (connected_components - 1) << "\n";

    return 0;
}
