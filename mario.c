#include <stdio.h>
#include <cs50.h>

int main(void)
{

    int psize;
//prompting the gamer
    do
    {
        psize = get_int("Enter size of pyramid: \n");
    }
    while(psize < 1 || psize > 8);

//initialize global counter
    int j = psize;

//global loop to ensure there are psize rows
    do
    {
        int i = j;
        //print psize-j spaces
        do
        {
            if (i == 1)
            {
                break;
            }
            printf(" ");
            i = i - 1;
        }
        while (i > 1);
        int k = psize - (j - 1);
        //print balance of # symboles
        do
        {
            printf("#");
            k = k - 1;
        }
        while (k > 0);

        printf("\n");
        j = j - 1;

    }
    while (j > 0);
}