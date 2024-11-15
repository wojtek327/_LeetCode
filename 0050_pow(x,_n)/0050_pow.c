double myPow(double x, int n) {
        if (x == 0.0) {
        return 0.0;
    }
    else if (x == 1.0) {
        return 1.0;
    }
    else if (x == -1.0) {
        return (n % 2 == 0) ? 1.0 : -1.0;
    }
    else if (n == 0) {
        return 1.0;
    }

    bool isNegative = n < 0;
    long long exp = n;
    if (isNegative) {
        exp = -exp;
    }

    double result = 1.0;
    double current_product = x;

    while (exp > 0) {
        if (exp % 2 == 1) {
            result *= current_product;
        }
        current_product *= current_product;
        exp /= 2;
    }

    return isNegative ? 1.0 / result : result;
}
