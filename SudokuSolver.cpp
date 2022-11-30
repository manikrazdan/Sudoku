bool isValid(int row,int col,int num,int matrix[9][9]) {
    for (int i=0;i<9;i++) {
        if (matrix[i][col]==num) {
            return false;
        }
        if (matrix[row][i]==num) {
            return false;
        }
        if (matrix[3*(row/3)+i/3][3*(col/3)+i%3]==num) {
            return false;
        }
    }
    return true;
}
bool isItSudoku(int matrix[9][9]) {
    for (int row=0;row<9;row++) {
        for (int col=0;col<9;col++) {
            if (matrix[row][col]) continue;
            for (int num=1;num<=9;num++) {
                if (!isValid(row,col,num,matrix)) continue;
                matrix[row][col]=num;
                if (isItSudoku(matrix)) return true;
                matrix[row][col]=0;
            }
            return false;
        }
    }
    return true;
}
