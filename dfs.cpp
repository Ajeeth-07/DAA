#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

void addEdge(unordered_map<int,vector<int>> &graph, int u, int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void DFS(unordered_map<int,vector<int>> &graph, int start){
    unordered_map<int,bool> visited;
    stack<int> stk;
    stk.push(start);

    while(!stk.empty()){
        int curr = stk.top();
        stk.pop();

        if(visited[curr])
            continue;

        cout << curr << " ";
        visited[curr] = true;

        for(int i=0;i<graph[curr].size();i++){
            if(!visited[graph[curr][i]])
                stk.push(graph[curr][i]);
        }
    }
}

int main()
{
    unordered_map<int,vector<int>> graph;
    addEdge(graph,0,1);
    addEdge(graph,0,2);
    addEdge(graph,1,2);
    addEdge(graph,2,3);
    addEdge(graph,3,3);

    cout << "Depth-First Search starting from vertex 2: ";
    DFS(graph,2);

    return 0;
}

