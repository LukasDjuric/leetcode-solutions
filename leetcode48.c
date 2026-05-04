// Rotate Image (LeetCode 48)
//
// Approach:
// - Layer-by-layer rotation (processing matrix in "rings")
// - Each layer is rotated by shifting elements in 4 directions
//
// Time Complexity: O(n^2)
// Space Complexity: O(1)
//
// Notes:
// - In-place rotation without using extra matrix
// - Focus is on index manipulation rather than standard transpose approach
void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    int i, j, k, tmp, n;
    for(k = 0; k < matrixSize / 2; k++){    // k represents current layer (from outer to inner)
        n = matrixSize - 2 * k;             // n is the effective size of the current layer
        for(j = 0; j < n - 1; j++){
            tmp = matrix[k][k];             // store first element of the layer to rotate later
            for(i = 0; i < n - 1; i++){
            matrix[k + i][k] = matrix[k + i + 1][k];
            }
            for(i = 0; i < n - 1; i++){
                matrix[k + n - 1][k + i] = matrix[k + n - 1][k + i + 1];
            }
            for(i = 0; i < n - 1; i++){
                matrix[k + n - 1 - i][k + n - 1] = matrix[k + n - 2 - i][k + n - 1];
            }
            for(i = 0; i < n - 2; i++){
                matrix[k][k + n - 1 - i] = matrix[k][k + n - 2 - i];
            }
            matrix[k][k + 1] = tmp;
        }
    }
}

