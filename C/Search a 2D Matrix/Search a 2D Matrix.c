// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.
 

// Example 1:


// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true
// Example 2:


// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
// Output: false
 

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 100
// -104 <= matrix[i][j], target <= 104

//My way

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int *ptr, find = 0;
    if(matrixSize == 1){
        ptr = matrix[0];
    }else {
        for(int i = 0; i < matrixSize; i++){
            if(matrix[i][0] == target)
                return true;
                
            if(matrix[i][0] > target){
                if(i == 0){
                    return false;
                }
                find = 1;
                ptr = matrix[i-1];
                break;
            }
        }
        if(find == 0){
            ptr = matrix[matrixSize-1];
        }
    }
    printf("the row is:%d\n",*ptr);
    int start = 0, end = *matrixColSize-1;
    while(start < end){
        printf("%d\t%d\n", start, end);
        if(ptr[(start+end)/2] > target){
            end = (start+end)/2-1;
        } else if (ptr[(start+end)/2] < target){
            start = (start+end)/2+1;
        } else{
            return true;
        }
    }

    if(ptr[start] == target){
        return true;
    }
    return false;
}