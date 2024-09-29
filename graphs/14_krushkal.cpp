// krushkal algorithm is implemted by disjoint_algo
// need of linear ds instead of adj list
// finding parent of each 
// if parent[u] == parent[v] then do nothing
// if diff then merge them with thier weight
// uing min heap so that minimum weight will upward with thier u and v
// pair<int, pair<int, int>>.  === {wt, {u, v}}


#include<iostream>
#include<vector>
using namespace std;

// this is comparotor makes for soting if a[2] < b[2] then true otherwise its false
bool cmp(vector<int> &a, vector<int> &b){
    return a[2] < b[2];
}

// this is only for iniltization os parent and rank vector
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

// formaing an mst for this graph of given edges
vector<pair<pair<int, int>, int>> minimumSpanningTree(vector<vector<int>> &edges, int n){
    // this is how we sort an vector and with comparator
    sort(edges.begin(), edges.end(), cmp);
    
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);
    vector<pair<pair<int, int>, int>> mst;

    // starting from node 0 to size-1;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int parentOfU = findParent(parent, u);
        int parentOfV = findParent(parent, v);
        int wt = edges[i][2];

        if(parentOfU != parentOfV){
            // joining them in this case
            mst.push_back({{u, v}, wt});
        }else{
            // do nothing in this case
        }
    }
    return mst;
}


// time complexistes mlog(n) + o(1)  where m is edges as o(1) is constanr for finding parent
// space complexity is o(2n)