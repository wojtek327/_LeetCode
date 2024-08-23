//Ceiling of average
int minimizeArrayValue(int* nums, int numsSize){
    double a = 0.0;
    double b = 0.0;

    for(int i = 0; i<numsSize; i++)
    {
        b += nums[i];
        if(a<=ceil(b/(i+1))) {
            a=ceil(b/(i+1));
        }
    }
    return (int)a;
}
/*
e.x. [3,7,1,6]
i_0 - b = 3,
      a = 3
i_1 b = 10 (3 + 7) ;
    a = 10/2 = 5
i_2 b = 11 (3 + 7 + 1);
    a = 5 (ceil lower then 5 => 11/(2+1))
i_3 b = 17 (3 + 7 + 1 + 6)
    a = 5 (ceil lower ten 5 => 17/(3+1))
*/
