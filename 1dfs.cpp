//DFS

#include <vector>
#include <stack>
#include <unordered_map>
#include <iostream>

using namespace std;

class DFS {
public:
    int **adjMatrix;
    stack<int> node;
    unordered_map<int, bool> visited;

    DFS(int n) {
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

    void DFS_Traversal(int source, int n) {

        node.push(source);
        cout<<endl;

        while(!node.empty()){

            int currentNode = node.top();
            node.pop();
            

            if(visited[currentNode] == 0){
                visited[currentNode] = 1;
                cout<<currentNode;
                for(int i=n-1;i>=0;i--){
                    if (adjMatrix[currentNode][i] != 0 && !visited[i]) {
                        node.push(i);
                    }
                }
            }
               
        }
    }
};

int main() {
    DFS bfs(9);
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
    

    bfs.DFS_Traversal(2,9);
    return 0;
}
