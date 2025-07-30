int maxArea(int* height, int heightSize){
    int start = 0;
    int end = heightSize - 1;
    int max = 0;

    while(start < end) {
        int area = (end - start);

        if(height[start] < height[end]) {
            area = area * height[start++];
        } else {
            area = area * height[end--];
        }

        if(area > max) {
            max = area;
        } else {
            max = max;
        }
    }
    return max;
}


//------------------------------------------------
int maxArea(int* height, int heightSize) {
    int l = 0;
    int r = heightSize - 1;
    int maxArea = 0;

    while(l<=r) {
        int w = r - l;
        int h = 0;

        if(height[l] < height[r]) {
            h = height[l];
        } else {
            h = height[r];
        }
        int tmpmaxArea = w * h;

        if(tmpmaxArea > maxArea) {
            maxArea = tmpmaxArea;
        }

        if(height[l]>height[r]){
            r--;
        }
        else {
            l++;
        }
    }

    return maxArea;
}
