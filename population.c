#include <cs50.h>
#include <stdio.h>


int main(void)
{
    int startsize;
    int endsize;

    // TODO: Prompt for start size
    do
    {

        startsize = get_int("Enter start size:\n");

    }
    while (startsize < 9);

    // TODO: Prompt for end size
    do
    {
        endsize = get_int("Enter end size:\n");
    }
    while (endsize<startsize);

    // TODO: Calculate number of years until we reach threshold

    int population = startsize;
    int grow = startsize / 3;
    int die = startsize / 4;

    int i = 0;
    while (population<endsize) {
        population = population + grow - die;
        grow = population / 3;
        die = population / 4;
        i = i + 1;

    }

    // TODO: Print number of years
    printf("Years: %i\n", i);


}