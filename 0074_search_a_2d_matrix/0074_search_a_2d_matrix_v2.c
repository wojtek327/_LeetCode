//O(log(matrixSize))+O(log(matrixColSize))=O(log(matrixSize⋅matrixColSize))

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    if(matrixSize == 0 || *matrixColSize == 0) {
        return false;
    }

    int left = 0;
    int right = matrixSize - 1;

    while(left <= right) {
        int mid = left + (right - left)/2;

        if(matrix[mid][0] <= target && matrix[mid][*matrixColSize - 1] >= target)
        {
            int leftRow = 0;
            int rightRow = (*matrixColSize) - 1;
             while(leftRow <= rightRow) {
                int midrow = leftRow + (rightRow - leftRow)/2;

                if(matrix[mid][midrow] == target) {
                    return true;
                }

                if(matrix[mid][midrow] < target) {
                    leftRow = midrow + 1;
                } else {
                    rightRow = midrow - 1;
                }
             }
        }

        if(matrix[mid][0] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return false;
}
