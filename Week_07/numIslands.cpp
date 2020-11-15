// Union Find
class UnionFind {
public:
    UnionFind(int n, vector<vector<char>>& grid) {
        parent = vector<int>(n, 0);
        for (int i = 0; i < n; i++) {
            int x = i / grid[0].size();
            int y = i % grid[0].size();
            if (grid[x][y] == '1') {
                count++;
            }
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (x == parent[x]) {
            return x;
        }
        
        auto px = find(parent[x]);
        parent[x] = px;
        return px;
    }
    
    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px != py) {
            parent[px] = py;
            count--;
        }
    }

int getCount() {
    return count;
}
private:
    vector<int> parent;
    int count = 0;
};
class Solution {
    vector<vector<int>> dirs = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    int M;
    int N;
public:
    int numIslands(vector<vector<char>>& grid) {
        M = grid.size();
        N = grid[0].size();
        UnionFind uf(M * N, grid);
        
        
        vector<vector<bool>> visited(M, vector<bool>(N, false));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                visited[i][j] = true;
                for (const auto& dir : dirs) {
                    auto ni = i + dir[0];
                    auto nj = j + dir[1];
                    if (ni < 0 || nj < 0 || ni >= M || nj >= N ||
                        grid[ni][nj] == '0' || visited[ni][nj]) {
                        continue;        
                    } 
                    
                    uf.unite(i * N + j, ni * N + nj);
                }
            }
        }
    }   
    return uf.getCount();
    }
};


