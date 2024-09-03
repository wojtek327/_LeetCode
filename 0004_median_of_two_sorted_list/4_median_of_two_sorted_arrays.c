//C O(log (m+n))
//Binary search
/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).
mediana - wartość środkowa
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }

    int x = nums1Size;
    int y = nums2Size;
    int low = 0, high = x;

    while (low <= high) {
        int partitionX = (low + high) / 2;
        int partitionY = (x + y + 1) / 2 - partitionX;

        int maxX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int minX = (partitionX == x) ? INT_MAX : nums1[partitionX];

        int maxY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int minY = (partitionY == y) ? INT_MAX : nums2[partitionY];

        if (maxX <= minY && maxY <= minX) {
            if ((x + y) % 2 == 0) {
                return ((double)fmax(maxX, maxY) + fmin(minX, minY)) / 2;
            } else {
                return (double)fmax(maxX, maxY);
            }
        } else if (maxX > minY) {
            high = partitionX - 1;
        } else {
            low = partitionX + 1;
        }
    }

    return -1.0;
}

//C o(m + n)
/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
mediana - wartość środkowa
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    double response = 0;
    int nums3Size = nums1Size + nums2Size;

    //zabezpieczenie jesli bedzie 0
    if (nums3Size == 0) { return 0; }

    int *nums3 = (int *) malloc(sizeof(int)*nums3Size);

    //zabezpieczeni jesli jedna z tablic jest 0
    if (nums1Size == 0) {
        for (int i=0; i < nums2Size; i++) {
            nums3[i] = nums2[i];
        }
    }
    else if (nums2Size == 0) {
        for (int i=0; i < nums1Size; i++) {
            nums3[i] = nums1[i];
        }
    }

    //Sortowanie elementów w trzeciej tablicy
    if(nums1Size != 0 && nums2Size != 0)
    {
        int j=0;
        int k=0;
        for (int i=0; i < nums3Size; i++) {
            if (k == nums2Size && j < nums1Size){
                nums3[i] = nums1[j];
                j++;
            }
            else if (j == nums1Size && k < nums2Size) {
                nums3[i] = nums2[k];
                k++;
            }
            else if (nums2[k] < nums1[j]) {
                nums3[i] = nums2[k];
                k++;
            }
            else if (nums1[j] <= nums2[k]){
                nums3[i] = nums1[j];
                j++;
            }
        }
    }

    if (nums3Size == 1) { return nums3[0]; }
    if (nums3Size % 2 == 0)
    {
       int index = nums3Size / 2;
       double median = (nums3[index-1]+nums3[index])/(double)2;
       return median;
    }
    else
    {
        return nums3[nums3Size/2];
    }

    return -1.0;
}
