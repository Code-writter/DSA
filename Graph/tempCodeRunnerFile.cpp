
    void bfs(T src, unordered_map<int, bool>& isVisited){
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
};


int main(){
    Graph<int> g;

    g.addNode(1, 2, 10, 1);
    g.addNode(1, 3, 20, 1);
    g.addNode(2, 3, 30, 1);

    cout<<"Printing graph traversal"<<endl;
    // g.bfs(1);
    // this is big mistake
    unordered_map<int, bool> isVisited;
    for(int i = 0; i<2; i++){
        if(!isVisited[i]){
            g.bfs(i, isVisited);
        }
    }
    
    return 0;
};