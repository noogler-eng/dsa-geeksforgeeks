#include<iostream>
#include<vector>
using namespace std;

//
void makeSet(vector<int> &parent, vector<int> &rank, int n){
    
    // nodes from 0 to n-1
    // parent of itself initlially and rank of all is 0 in starting
    for(int i=0; i<n; i++){
        parent[i] = i;
        rank[i] = i;
    }
}

// top most element os final parent of each node
// but short term parent is just above it
int findParent(vector<int> &parent, int node){
    if(parent[node] == node) {
        // it means top most element which is parent of every node
        return node;
    }

    // recursively smmaller part
    // path commpression is done here
    return parent[node] = findParent(parent, parent[node]);
}

// combining an two disconnected components of graph
void unionSet(int u, int v, vector<int> &parent, vector<int> &rank){
    int rankOfU = rank[findParent(parent, u)];
    int rankOfV = rank[findParent(parent, v)];
    

    if(rankOfU > rankOfV){
        // here no effect on rank or depth of tree
        parent[v] = u;
    }else if(rankOfV > rankOfU){
        // here no effect on rank or depth of tree
        parent[u] = v;
    }else{
        parent[u] = v;
        // here rank of parent will be increases as depth increases
        rank[u]++;
    }
}

// 
int minimumSpanningTree(vector<vector<int>> & edges, int n){
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);
    return 0;
}


// if any two nodes are given then check if they lie in same component or not ?
// check with their parent node is same then yes both lie in same otherwise no.