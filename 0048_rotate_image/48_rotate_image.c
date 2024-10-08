void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    //transpose
    for(int i = 0; i<matrixSize; i++) {
        for(int j = i+1; j<matrixSize; j++) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
    }

    //reflection
    for(int i = 0; i<matrixSize; i++) {
        for(int j = 0; j<(matrixSize / 2); j++) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[i][matrixSize - j - 1];
            matrix[i][matrixSize - j - 1] = tmp;
        }
    }
}
