// Miminim path Effort (dijkastra's)
#include<vector>
#include <queue>
using namespace std;

// finding the shortest path between (0, 0) to (n-1, m-1);
// finding the solution usinf dijkstra's solution 
// (valid for both directed and undirected graph)
// minimum effort = max(diff between consective path cell)

// at the end we have to take the weight of edge to be diff between two cells
// time complexity is Elog(v) where E = n * m * 4, V = n * m

class Solution {
  public:
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        // making of min heap as prioirti queue
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minPQ;    
        
        
        // pusing max the path diff until reach here and coordinates 
        // [1, 2, 2]
        // [3, 8, 2]
        // [5, 3, 5]
        
        vector<vector<int>> ans(rows, vector<int>(columns, INT_MAX));
        int rd[] = {1, 0, -1, 0};
        int cd[] = {0, 1, 0, -1};
        
        minPQ.push({0, {0,0}});
        ans[0][0] = 0;
        while(!minPQ.empty()){
            int maxPathDiff = minPQ.top().first;
            int r = minPQ.top().second.first;
            int c = minPQ.top().second.second;
            minPQ.pop();
            
            // returning the final point ans
            if (r == rows - 1 && c == columns - 1) {
                return maxPathDiff;
            }
            
            for(int i=0; i<4; i++){
                int new_r = r + rd[i];
                int new_c = c + cd[i];
                
                if(new_r >=0 && new_r <rows && new_c >=0 && new_c <columns){
                    int nextH = heights[new_r][new_c];
                    // tkaing the maximum till now point if it is smaller then present in ans array
                    // then replacing it
                    int newEffort = max(maxPathDiff, abs(nextH - heights[r][c]));
                    if(newEffort < ans[new_r][new_c]){
                        ans[new_r][new_c] = newEffort;
                        minPQ.push({newEffort, {new_r, new_c}});
                    }
                }
            }
        }

        // if there is no path then returning -1
        return -1;
    }
};


