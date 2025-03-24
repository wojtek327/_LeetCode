long long maxPoints(int** points, int pointsSize, int* pointsColSize) {
    int i = 0;
    int j = 0;
    int n = pointsSize;
    int m = pointsColSize[0];

    long long *dp1 = (long long*)malloc(sizeof(long long) * m);
    long long max = (long long*)malloc(sizeof(long long) * m);
    long long *c = (long long*)malloc(sizeof(long long) * m);
    long long *dp2 = (long long*)malloc(sizeof(long long) * m);

    //Przepisujemy punkty z pierwszego wiersza
    for(j = 0; j < m; j++) {
        dp1[j] = points[0][j];
    }

    for(i = 1; i < n; i++){
        for(j = 1, dp2[0] = dp1[0]; j < m; j++)
        {
            dp2[j] = dp2[j - 1] - 1 > dp1[j] ? dp2[j - 1] - 1 : dp1[j];
        }

        for(j = m - 1, max = 0; j >= 0; j--){
            max = max - 1 > dp1[j] ? max - 1 : dp1[j];
            dp2[j] = points[i][j] + (dp2[j] > max ? dp2[j] : max);
        }

        c = dp1, dp1 = dp2, dp2 = c;
    }

    free(dp2);
    long long res = 0;
    for(i = 0; i < m; i++)
        if(dp1[i] > res) res = dp1[i];

    free(dp1);
    return res;
}
