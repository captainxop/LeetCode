class Solution {
public:
    
    int n, m;
    bool mark[55][55];
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        n = image.size(), m = image[0].size();
        memset(mark, 0, sizeof(mark));
        fill(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
    
     void fill(vector<vector<int>>& image, int i, int j, int oldColor, int newColor)
     {
        if(i < 0 || i >= n || j < 0 || j >= m) return;
        if(mark[i][j]) return;
        if(image[i][j] != oldColor) return;
        
        mark[i][j] = 1;
        image[i][j] = newColor;
        
        fill(image, i, j + 1, oldColor, newColor);
        fill(image, i, j - 1, oldColor, newColor);
        fill(image, i + 1, j, oldColor, newColor);
        fill(image, i - 1, j, oldColor, newColor);
    }
};
