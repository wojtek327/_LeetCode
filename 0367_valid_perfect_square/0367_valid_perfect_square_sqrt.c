bool isPerfectSquare(int num) {
    if (num >= 0) {
        long long sr = sqrt(num);
        return (sr * sr == num);
    }

    return false;
}
