#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
  
// class Graph{
//     public:
//     unordered_map<int, list<int> > adjList;

//     void addNode(int u, int v, bool direction){
//         if(direction == 1){
//             // u -> v
//             adjList[u].push_back(v);
//         }else{
//             // u -> v
//             // v -> u
//             adjList[u].push_back(v);
//             adjList[v].push_back(u);
//         }
//         printGraph();
//         cout<<endl;
//     }

//     void printGraph(){
//         for(auto adj : adjList){
//             cout<<adj.first<<" : { ";
//             for(auto l : adj.second){
//                 cout<<l<<", ";
//             }
//             cout<<" }" <<endl;
//         }
//     }
    
// };

template<typename T>

class Graph{
    public:
    unordered_map<T, list<pair<T, T>>> adjList;

    void addNode(T u, T v, T weight, bool direction){
        // if direction == 0 undirected
        // if direction == 1 directed
        if(direction == 1){
            // u -> v
            adjList[u].push_back({v, weight});
        }else{
            adjList[u].push_back({v, weight});
            adjList[v].push_back({u, weight});
        }
        cout<<"Printing graph"<<endl;
        printGraph();
    }

    void printGraph(){
        for(auto adj : adjList){
            cout<<adj.first<<" : ";
            for(pair<T, T> p : adj.second){
                cout<<"{ "<<p.first<<", "<<p.second<<" }";
            }
            cout<<endl;
        }
    }


    void bfs(T src, unordered_map<T, bool>& isVisited){
        // maintain adjecency matricx
        // maintain visited map

        // maintain queue
        queue<T> q;
        // push the front node
        q.push(src);
        isVisited[src] = true;
        while(!q.empty()){
            // get the front node
            T front = q.front();
            // Pop the front node
            q.pop();
            // Print the data
            cout<<front<<"  ";

            // Now push the neighbours
            for(auto nbr : adjList[front]){
                T nextNode = nbr.first;

                if(!isVisited[nextNode]){
                    q.push(nextNode);
                    isVisited[nextNode] = true;
                }
            }
        }
    }

    void dfs(T src, unordered_map<T, bool>& isVisited){


        isVisited[src] = true;
        cout<<src<<"  ";

        for(auto adj : adjList[src]){
            T nbrdata = adj.first;
            if(!isVisited[nbrdata]){
                dfs(nbrdata, isVisited);
            }
        }
    }


    void BFS(int src, unordered_map<int, bool>& mp, int parts){
        // make the visited table
        queue<int> q;
        // push the src node and mark the visited true
        q.push(src);
        mp[src] = true;

        while(!q.empty()){
            // get the front
            int front = q.front();
            q.pop();
            cout<<front <<"  ";

            for(auto nbr : adjList[front]){
                int nbrData = nbr.first;

                if(!mp[nbrData]){
                    q.push(nbrData);
                    mp[nbrData] = true;
                }
            }
        }

    }

    void DFS(int src, unordered_map<int, bool>& mp){
        mp[src] = true;
        cout<<src<<" ";

        for(auto nbr : adjList[src]){
            int nbrData = nbr.first;
            if(!mp[nbrData]){
                mp[nbrData] = true;
                DFS(nbrData, mp);
            }
        }
    }


};


    // void dfs(vector<vector<char>>& grid, int r, int c) {
    //     int numRows = grid.size();
    //     int numCols = grid[0].size();

    //     // Boundary checks: Stop if we go off the grid or hit water
    //     if (r < 0 || c < 0 || r >= numRows || c >= numCols || grid[r][c] == '0') {
    //         return;
    //     }

    //     // Sink the current part of the island by changing it to 0
    //     grid[r][c] = '0';
    //     dfs(grid, r + 1, c); // Down
    //     dfs(grid, r - 1, c); // Up
    //     dfs(grid, r, c + 1); // Right
    //     dfs(grid, r, c - 1); // Left
    // }

    // int numIslands(vector<vector<char>>& grid) {
    //     if (grid.empty() || grid[0].empty()) {
    //         return 0;
    //     }

    //     int numRows = grid.size();
    //     int numCols = grid[0].size();
    //     int islandCount = 0;

    //     for (int i = 0; i < numRows; ++i) {
    //         for (int j = 0; j < numCols; ++j) {
    //             if (grid[i][j] == '1') {
    //                 islandCount++;
    //                 dfs(grid, i, j);
    //             }
    //         }
    //     }

    //     return islandCount;  
    // }



int main(){
    Graph<int> g;

    g.addNode(1, 2, 10, 1);
    g.addNode(1, 3, 20, 1);
    g.addNode(2, 3, 30, 1);
    g.addNode(2, 4, 15, 1);
    g.addNode(3, 4, 25, 1);
    // g.addNode(4, 5, 35, 1);
    g.addNode(5, 6, 40, 1);
    g.addNode(6, 1, 50, 1);

    cout<<"Printing graph traversal"<<endl;
    // g.BFS(1);
    // this is big mistake to handle the disconnected format
    unordered_map<int, bool> isVisited;
    // int parts = 0;
    // for(int i = 1; i<6; i++){
    //     if(!isVisited[i]){
    //         g.BFS(i, isVisited, parts);
    //     }
        
    // }
    int count = 0;
    g.DFS(1, isVisited);
    for(int i = 1; i<6; i++){
        if(!isVisited[i]){
            count++;
            g.DFS(i, isVisited); 
        }
    }
    cout<<"\n Number of components : "<<count<<endl;
    // return 0;
};