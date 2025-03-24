INT MIN -2147483648.
INT_MAX  2147483647.

int divide(int dividend, int divisor) {
    if (dividend == -2147483648 && divisor == -1) {
        return INT_MAX;
    }

    return (int)(dividend / divisor);
}

int divide(int dividend, int divisor) {
    return (dividend == -2147483648 && divisor == -1)? INT_MAX:dividend/divisor;
}