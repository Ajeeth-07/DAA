#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// A structure to represent a graph
struct Graph {
  int V; // Number of vertices
  vector<vector<int>> adj; // Adjacency list

  // Constructor
  Graph(int V) {
    this->V = V;
    adj.resize(V);
  }

  // Add an edge to the graph
  void addEdge(int u, int v) {
    adj[u].push_back(v);
  }
};

// BFS function
void bfs(Graph &g, int s) {
  // Mark all the vertices as not visited
  bool visited[g.V];
  for (int i = 0; i < g.V; i++) {
    visited[i] = false;
  }

  // Create a queue
  queue<int> q;

  // Mark the source vertex as visited and enqueue it
  visited[s] = true;
  q.push(s);

  // Loop until the queue is empty
  while (!q.empty()) {
    // Dequeue the vertex at the front of the queue
    int u = q.front();
    q.pop();

    // Print the vertex
    cout << u << endl;

    // Iterate over all the neighbors of the dequeued vertex
    for (int v : g.adj[u]) {
      // If the neighbor is not visited, mark it visited and enqueue it
      if (!visited[v]) {
        visited[v] = true;
        q.push(v);
      }
    }
  }
}

int main() {
  // Get the number of vertices from the user
  int V;
  cin >> V;

  // Create a graph
  Graph g(V);

  // Add edges to the graph
  for (int i = 0; i < V; i++) {
    int u, v;
    cin >> u >> v;
    g.addEdge(u, v);
  }

  // Get the source vertex from the user
  int s;
  cin >> s;

  // Print the BFS traversal of the graph starting from vertex 0
  bfs(g, s);

  return 0;
}