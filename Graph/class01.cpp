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
};


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
    // g.bfs(1);
    // this is big mistake to handle the disconnected format
    unordered_map<int, bool> isVisited;
    // for(int i = 1; i<2; i++){
    //     if(!isVisited[i]){
    //         g.bfs(i, isVisited);
    //     }
    // }
    // g.dfs(1, isVisited);
    for(int i = 1; i<6; i++){
        if(!isVisited[i]){
            g.dfs(i, isVisited); 
        }
    }
    return 0;
};