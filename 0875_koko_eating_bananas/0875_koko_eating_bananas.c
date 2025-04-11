long check_time(const int piles[], const int len, const int k) {
    long totalHours = 0;
    for (int i = 0; i < len; i++){
        if((piles[i] % k) == 0){
            totalHours += (piles[i] / k);
        }
        else{
            totalHours += ((piles[i] / k) + 1);
        }
    }
    return totalHours;
}

int minEatingSpeed(int* piles, int pilesSize, int h) {
    int low = 1;            //Minimalna ilość bananów do zjedzenia
    int high = piles[0];    //Maksymalna ilość bananów do zjedzenia w ciągu jednej godziny

    //szukamy maksymalnej ilości bananów
    for(int i = 1; i < pilesSize; i++){
        if(piles[i] > high){
            high = piles[i];
        }
    }

    while(low <= high) {
        int mid = low + (high - low)/2;

        if(check_time(piles, pilesSize, mid) <= h){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    return low;
}
