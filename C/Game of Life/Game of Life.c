// According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

// The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

// Any live cell with fewer than two live neighbors dies as if caused by under-population.
// Any live cell with two or three live neighbors lives on to the next generation.
// Any live cell with more than three live neighbors dies, as if by over-population.
// Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
// The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the current state of the m x n grid board, return the next state.

 

// Example 1:


// Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
// Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
// Example 2:


// Input: board = [[1,1],[1,0]]
// Output: [[1,1],[1,1]]
 

// Constraints:

// m == board.length
// n == board[i].length
// 1 <= m, n <= 25
// board[i][j] is 0 or 1.
 

// Follow up:

// Could you solve it in-place? Remember that the board needs to be updated simultaneously: You cannot update some cells first and then use their updated values to update other cells.
// In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches upon the border of the array (i.e., live cells reach the border). How would you address these problems?

//My way

/*
    本輪附近少於兩個存活者,下回合死亡
    附近有兩個或三個存活者,活到下回合
    附近有三個以上存活者下回合死亡 => 人口過剩
    死亡後附近有剛好三個下回合的存活者 => 復活

    統整: 
        當前節點附近 活人少於兩個先死亡 : 活人大於等於兩個活著
        全部死活清算一輪後,紀錄死亡發生位置並且看附近下回合存活者有無等於三個
*/

int reproduction(int **board, int row, int col , int rowTot, int colTot){
    int liveCnt = 0;
    if(row < rowTot-1 && row > 0){
        if(board[row-1][col] == 1)
            liveCnt++;
        if(board[row+1][col] == 1)
            liveCnt++;
        if(col < colTot-1 && col > 0){
            if(board[row-1][col-1] == 1)
                liveCnt++;
            if(board[row][col-1] == 1)
                liveCnt++;
            if(board[row+1][col-1] == 1)
                liveCnt++;
            if(board[row-1][col+1] == 1)
                liveCnt++;
            if(board[row][col+1] == 1)
                liveCnt++;
            if(board[row+1][col+1] == 1)
                liveCnt++;
        }else if(col == 0 && colTot > 1){
            if(board[row-1][col+1] == 1)
                liveCnt++;
            if(board[row][col+1] == 1)
                liveCnt++;
            if(board[row+1][col+1] == 1)
                liveCnt++;
        }else if(col == colTot-1 && colTot > 1){
            if(board[row-1][col-1] == 1)
                liveCnt++;
            if(board[row][col-1] == 1)
                liveCnt++;
            if(board[row+1][col-1] == 1)
                liveCnt++;
        }
    }else if(row == 0 && rowTot > 1){
        if(board[row+1][col] == 1)
            liveCnt++;
        if(col < colTot-1 && col > 0){
            if(board[row][col-1] == 1)
                liveCnt++;
            if(board[row+1][col-1] == 1)
                liveCnt++;
            if(board[row][col+1] == 1)
                liveCnt++;
            if(board[row+1][col+1] == 1)
                liveCnt++;
        }else if(col == 0 && colTot > 1){
            if(board[row][col+1] == 1)
                liveCnt++;
            if(board[row+1][col+1] == 1)
                liveCnt++;
        }else if(col == colTot-1 && colTot > 1){
            if(board[row][col-1] == 1)
                liveCnt++;
            if(board[row+1][col-1] == 1)
                liveCnt++;
        }
    }else if(row == rowTot-1 && rowTot > 1){
        if(board[row-1][col] == 1)
            liveCnt++;
        if(col < colTot-1 && col > 0){
            if(board[row-1][col-1] == 1)
                liveCnt++;
            if(board[row][col-1] == 1)
                liveCnt++;
            if(board[row-1][col+1] == 1)
                liveCnt++;
            if(board[row][col+1] == 1)
                liveCnt++;
        }else if(col == 0 && colTot > 1){
            if(board[row-1][col+1] == 1)
                liveCnt++;
            if(board[row][col+1] == 1)
                liveCnt++;
        }else if(col == colTot-1 && colTot > 1){
            if(board[row-1][col-1] == 1)
                liveCnt++;
            if(board[row][col-1] == 1)
                liveCnt++;
        }
    }
    if(liveCnt == 3)
        return 1;
    return 0;
}

int isAlive(int **board, int row, int col , int rowTot, int colTot){
    int liveCnt = 0;
    if(row < rowTot-1 && row > 0){
        if(board[row-1][col] == 1)
            liveCnt++;
        if(board[row+1][col] == 1)
            liveCnt++;
        if(col < colTot-1 && col > 0){
            if(board[row-1][col-1] == 1)
                liveCnt++;
            if(board[row][col-1] == 1)
                liveCnt++;
            if(board[row+1][col-1] == 1)
                liveCnt++;
            if(board[row-1][col+1] == 1)
                liveCnt++;
            if(board[row][col+1] == 1)
                liveCnt++;
            if(board[row+1][col+1] == 1)
                liveCnt++;
        }else if(col == 0 && colTot > 1){
            if(board[row-1][col+1] == 1)
                liveCnt++;
            if(board[row][col+1] == 1)
                liveCnt++;
            if(board[row+1][col+1] == 1)
                liveCnt++;
        }else if(col == colTot-1 && colTot > 1){
            if(board[row-1][col-1] == 1)
                liveCnt++;
            if(board[row][col-1] == 1)
                liveCnt++;
            if(board[row+1][col-1] == 1)
                liveCnt++;
        }
    }else if(row == 0 && rowTot > 1){
        if(board[row+1][col] == 1)
            liveCnt++;
        if(col < colTot-1 && col > 0){
            if(board[row][col-1] == 1)
                liveCnt++;
            if(board[row+1][col-1] == 1)
                liveCnt++;
            if(board[row][col+1] == 1)
                liveCnt++;
            if(board[row+1][col+1] == 1)
                liveCnt++;
        }else if(col == 0 && colTot > 1){
            if(board[row][col+1] == 1)
                liveCnt++;
            if(board[row+1][col+1] == 1)
                liveCnt++;
        }else if(col == colTot-1 && colTot > 1){
            if(board[row][col-1] == 1)
                liveCnt++;
            if(board[row+1][col-1] == 1)
                liveCnt++;
        }
    }else if(row == rowTot-1 && rowTot > 1){
        if(board[row-1][col] == 1)
            liveCnt++;
        if(col < colTot-1 && col > 0){
            if(board[row-1][col-1] == 1)
                liveCnt++;
            if(board[row][col-1] == 1)
                liveCnt++;
            if(board[row-1][col+1] == 1)
                liveCnt++;
            if(board[row][col+1] == 1)
                liveCnt++;
        }else if(col == 0 && colTot > 1){
            if(board[row-1][col+1] == 1)
                liveCnt++;
            if(board[row][col+1] == 1)
                liveCnt++;
        }else if(col == colTot-1 && colTot > 1){
            if(board[row-1][col-1] == 1)
                liveCnt++;
            if(board[row][col-1] == 1)
                liveCnt++;
        }
    }else{
        if(col < colTot-1 && col > 0){
            if(board[row][col-1] == 1)
                liveCnt++;
            if(board[row][col+1] == 1)
                liveCnt++;
        }
    }
    if(liveCnt == 2 || liveCnt == 3)
        return 1;
    return 0;
}

typedef struct dead{
    int row;
    int col;
}Dead;

void gameOfLife(int** board, int boardSize, int* boardColSize){
    if(boardSize == 1 && *boardColSize == 1){
        board[0][0] = 0;
        return;
    }
    int **nextBoard = (int**)malloc(sizeof(int*) * boardSize);

    for(int i = 0; i < boardSize; i++){
        nextBoard[i] = (int*)malloc(sizeof(int) * (*boardColSize));
        memset(nextBoard[i], 0, sizeof(int) * (*boardColSize));
    }
    Dead arr[boardSize*(*boardColSize)];
    int len = 0;
    memset(arr,0,sizeof(arr));
    for(int i = 0; i < boardSize; i++){
        for(int j = 0; j < *boardColSize; j++){
            if(board[i][j] == 0){
                nextBoard[i][j] = reproduction(board, i, j, boardSize, *boardColSize);
                continue;
            }
            nextBoard[i][j] = isAlive(board, i, j, boardSize, *boardColSize);
        }
    }
    for(int i = 0; i < boardSize; i++){
        for(int j = 0; j < *boardColSize; j++){
            board[i][j] = nextBoard[i][j];
        }
    }
    for(int i = 0; i < boardSize; i++)
        free(nextBoard[i]);
    free(nextBoard);
}