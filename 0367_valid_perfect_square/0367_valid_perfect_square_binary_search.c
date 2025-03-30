bool isPerfectSquare(int num) {
    if (num <= 1) {
        return true;
    }

    int low = 0;
    int high = num;

    while(low <= high) {
        long long mid = low + (high - low) / 2;

        long long tmp_sqr = mid * mid;

        if(tmp_sqr == num) {
            return true;
        }

        if(tmp_sqr < num) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return false;
}
