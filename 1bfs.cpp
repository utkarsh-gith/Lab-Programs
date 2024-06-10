//BFS

#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>

using namespace std;

class BFS {
public:
    int **adjMatrix;
    queue<int> nodeQueue;
    unordered_map<int, bool> visited;

    BFS(int n) {
        adjMatrix = new int *[n];
        for(int i=0;i<n;i++)
        {
            adjMatrix[i] = new int[n];
            for (int j = 0; j < n; ++j) {
                adjMatrix[i][j] = 0; 
            }
        } 
       
    }

    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
    }

    void BFS_Traversal(int source, int n) {

        nodeQueue.push(source);

        while (!nodeQueue.empty()) {

            int currentNode = nodeQueue.front();
            nodeQueue.pop();

            if(visited[currentNode] == 0){

                visited[currentNode] = true;
                cout << currentNode << " ";
                
                for (int i = 0; i < n; i++) {
                    if (adjMatrix[currentNode][i] != 0) {
                        nodeQueue.push(i);
                    }
                }
            }
        }
        cout << endl;
    }
};

int main() {
    BFS bfs(9);
    bfs.addEdge(2, 6);
    bfs.addEdge(2, 3);
    bfs.addEdge(1, 3);
    bfs.addEdge(3, 4);
    bfs.addEdge(6, 1);
    bfs.addEdge(6, 7);
    bfs.addEdge(5, 7);
    bfs.addEdge(1, 5);
    bfs.addEdge(1, 8);
    bfs.addEdge(4, 8);
    bfs.addEdge(8, 5);
    bfs.addEdge(7, 0);
    

    bfs.BFS_Traversal(2,9);
    return 0;
}
