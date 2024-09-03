//1 <= s.length <= 100
//1 <= k <= 10
//replace with alphabet position
//'a' - 1 => ASCII 97(DEC) => 97 - 96
//'b' - 2 => ASCII 98(DEC) => 98 - 96
int getLucky(char* s, int k) {
    int sum = 0;
    int n = strlen(s);

    for(int i=0;i<n;i++){
        int num =(s[i]-'a'+1);
        while(num>0){
            sum+=num%10;
            num/=10;
        }
    }

    if(sum == 0) { 
        return 0;
    }

    while(--k>0){
        int total = 0;
        while(sum>0){
            total += sum%10;
            sum/=10;
        }
        sum = total;
    }
    
    return sum;
}