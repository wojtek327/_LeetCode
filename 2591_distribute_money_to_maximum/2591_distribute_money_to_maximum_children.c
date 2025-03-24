//1 <= money <= 200
//2 <= children <= 30
int distMoney(int money, int children) {
    if (children == 0)    { return 0; }
    if (money == 0)       { return 0; }

    if (children > money) { return -1; }
    if (children == money){ return 0; }

    if ((children * 8) == money) { return children; }

    if ((children * 8) < money) { return children - 1; }
    else if (money < (8+children-1) || (children==2 && money==12) ) {
        return 0;
    }

    if((money - ((money - children)/7  * 8)==4 && children-(money-children)/7==1 ))
    {
        return (money-children)/7-1;
    } else {
        return (money-children)/7;
    }
}
