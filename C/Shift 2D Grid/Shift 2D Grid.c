// Given a 2D grid of size m x n and an integer k. You need to shift the grid k times.

// In one shift operation:

// Element at grid[i][j] moves to grid[i][j + 1].
// Element at grid[i][n - 1] moves to grid[i + 1][0].
// Element at grid[m - 1][n - 1] moves to grid[0][0].
// Return the 2D grid after applying shift operation k times.

 

// Example 1:


// Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 1
// Output: [[9,1,2],[3,4,5],[6,7,8]]
// Example 2:


// Input: grid = [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]], k = 4
// Output: [[12,0,21,13],[3,8,1,9],[19,7,2,5],[4,6,11,10]]
// Example 3:

// Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 9
// Output: [[1,2,3],[4,5,6],[7,8,9]]
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m <= 50
// 1 <= n <= 50
// -1000 <= grid[i][j] <= 1000
// 0 <= k <= 100

//My way


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** shiftGrid(int** grid, int gridSize, int* gridColSize, int k, int* returnSize, int** returnColumnSizes){
    *returnSize = gridSize;
    *returnColumnSizes = (int*)malloc(sizeof(int) * gridSize);
    int **result = (int**)malloc(sizeof(int*) * gridSize);
    for(int i = 0; i < gridSize; i++){
        result[i] = (int*)malloc(sizeof(int) * (*gridColSize));
        (*returnColumnSizes)[i] = *gridColSize;
        memset(result[i],0,sizeof(int) * (*gridColSize));
    }
    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < *gridColSize; j++){
            int row = ((j + k) / (*gridColSize)) % gridSize;
            int col = k % (*gridColSize);
            result[(i+row)%gridSize][(j+col)%(*gridColSize)] = grid[i][j];
        }
    }
    return result;
}