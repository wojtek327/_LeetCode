// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    long int low = 0;
    long int high = (n-1);

    while(high >= (low)) {
        long int mid = (high + low) / 2;

        if(isBadVersion(mid) == true) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return high + 1;
}
