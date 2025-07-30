int minVal(const int val1, const int val2) {
    if(val1 < val2){
        return val1;
    } 
    return val2;
}


int minCostClimbingStairs(int* cost, int costSize) {
    int prev = 0;
    int curr = 0;

    for (int i = 2; i <= costSize; ++i) {
        int next = minVal(cost[i - 2] + prev, cost[i - 1] + curr);
        prev = curr;
        curr = next;
    }

    return curr;
}