int search_matrix(int** matrix, int rows, int cols, int value) {
    if (rows == 0 || cols == 0) {
        return 0;
    }

    int low = 0;
    int high = rows * cols - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int number = matrix[mid / cols][mid % cols];

        if (value < number) {
            mid = high - 1;
        } else if (value > number) {
            mid = low + 1;
        } else {
            return 1;
        }
    }

    return 0;

}
