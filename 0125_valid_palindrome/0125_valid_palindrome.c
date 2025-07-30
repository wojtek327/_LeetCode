bool checkIfLowerCaseCharOrNumber(char c)
{
    if(('a' <= c && c <= 'z') || ('0' <= c && c <= '9'))
    {
        return true;
    }
    return false;
}

bool checkIfUpperCaseChar(char c)
{
    if('A' <= c && c <= 'Z')
    {
        return true;
    }
    return false;
}

bool isPalindrome(char * s){
    int j = 0;
    int k = 0;

    for(int i = 0; s[i] != '\0' ; i++)
    {
        if(checkIfLowerCaseCharOrNumber(s[i]))
        {
            s[j++] = s[i];
        }
        else if(checkIfUpperCaseChar(s[i]))
        {
            s[j++] = s[i] + 32;
        }
    }

    j-=1;

    while(k<(j))
    {
        if(s[k++] != s[j--])
        {
            return false;
        }
    }
    return true;
}
