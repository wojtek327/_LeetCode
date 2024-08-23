public class Solution {
    public int MySqrt(int x) {
        ulong i=1;

        while((i*i)<=(ulong)x) {
            i++;
        }

        return (int)(i-1);
    }
}