#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long card;
    do
    {
        card = get_long("Number: ");
    }
    while(card < 0);

    long temp1 = card;
    long temp2 = card;
    int count = 2;
    while (temp2 > 100)
    {
        temp2 /= 10;
        count += 1;
    }
    temp1 = temp2/10;

    int sum = 0;
    long current = 1;
    for (int i = 0; i < count/2+1; i++)
    {
        current *= 100;
        int current_num = ((card % current)/(current/10))*2;
        if (current_num > 10)
        {
            sum += 1 + (current_num%10);
        }
        else
        {
        sum += current_num;
        }
    }

    current = 10;
    for (int i = 0; i < count/2; i++)
    {
        int current_num = ((card % current)/(current/10));
        sum += current_num;
        current *= 100;
    }

    if (sum%10 == 0)
    {

        if ( temp1 == 4 && (count == 13 || count == 16) )
        {
            printf("VISA\n");
        }
        else if ((temp2 == 34 || temp2 == 37) && count == 15 )
        {
            printf("AMEX\n");
        }
        else if ((temp2 == 51 || temp2 == 52 || temp2 == 53 || temp2 == 54 || temp2 == 55) && count == 16 )
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }

    }
    else
    {
        printf("INVALID\n");
    }
}
