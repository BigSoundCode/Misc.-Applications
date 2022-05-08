#include <stdio.h>
#include <cs50.h>


//Takes users name and prints "Hello, name"
int main(void)
{
    string name = get_string("What is your name?\n");
    printf("hello, %s\n", name);
}