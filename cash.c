#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int owed;
    do
    {
        owed = get_int("Change owed: ");
    }
    while (owed < 0);

    int current = 0;
    int count = 0;

    while (owed != current)
    {
        if ((owed - current) >= 25)
        {
            current += 25;
            count += 1;
        }
        else if ((owed - current) >= 10)
        {
            current += 10;
            count += 1;
        }
        else if ((owed - current) >= 5)
        {
            current += 5;
            count += 1;
        }
        else
        {
            count += owed - current;
            break;
        }
    }

    printf("%i\n", count);
}
