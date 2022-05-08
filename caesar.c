#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
string cipher(string plaintext, int val);
int key;
//cipher program. Rotates (shifts) an inputed plaintext message and encrypts it
//Takes commandline argument of positive integer and uses that to rotate message


int main(int argc, char *argv[])


{

    if (argc > 2 || argc < 2)
    //check for too many command line inputs
    {
        printf("Error: Too many or not enough command line arguments\n");
        return 1;
        exit(1);

    }

    if (argc == 2)

    {
        //validate key
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            //found this isdigit method on stack overflow
            if (!isdigit(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
                exit(1);
            }
        }

        //convert commandline characters into integers with method suggested in problem set.
        key = atoi(argv[1]);
        if (key < 1)
        {
            printf("Usage: ./caesar key\n");
            return 1;
            exit(1);

        }

    }


    string msg = get_string("Plaintext: ");
    //below deals with keys > 26. since alphabet is 26 letters long, the remainder gives the
    //equivalent value after the rotation has happened fully/
    if (key > 26)
    {
        key = key % 26;
    }


    string ciphermessage = cipher(msg, key);
    printf("Ciphertext: %s\n", ciphermessage);



}

//function to scramble message. Key logic is to check if rotating value sends letter above 122, must check for that in advance to avoid serious problems!!

string cipher(string plaintext, int val)

{
    int length = strlen(plaintext);
    for (int i = 0; i < length; i++)

    {
        if (plaintext[i] < 65 || plaintext[i] > 122)
        {
            continue;
        }

        else if (plaintext[i] > 90 && plaintext[i] < 97)

        {
            continue;
        }

        if (isupper(plaintext[i]))
        {
            plaintext[i] = plaintext[i] + val;

            if (plaintext[i] > 90)

            {
                plaintext[i] = plaintext[i] - 26;
            }

        }

        else if (islower(plaintext[i]))
        {
            if (plaintext[i] + val > 122)
            {
                plaintext[i] = plaintext[i] - 26;
                plaintext[i] = plaintext[i] + val;
            }


            else
            {
                plaintext[i] += val;
            }
        }




    }

    return plaintext;

}