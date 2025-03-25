// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    int low = 0;
    int high = (n);

    while(high > (low + 1)) {
        int mid = low + (high - low) / 2;

        if(isBadVersion(mid) == true) {
            high = mid;
        }
        else {
            low = mid;
        }
    }

    return high;
}
