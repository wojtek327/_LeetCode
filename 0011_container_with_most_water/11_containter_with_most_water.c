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
