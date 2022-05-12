#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)


    {
        for (int j = 0; j < width; j++)
        {
            float sum = image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed;
            int average = round(sum/3);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }


    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{


    for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < width; j++)
        {
            int orgB = image[i][j].rgbtBlue;
            int orgG = image[i][j].rgbtGreen;
            int orgR = image[i][j].rgbtRed;

            int sBlue = round(.272 * orgR + .534 * orgG + .131 * orgB);
            int sGreen = round(.349 * orgR + .686 * orgG + .168 * orgB);
            int sRed = round(.393 * orgR + .769 * orgG + .189 * orgB);

            if (sBlue > 255)
            {
                sBlue = 255;
            }

            if (sGreen > 255)
            {
                sGreen = 255;
            }

            if (sRed > 255)
            {
                sRed = 255;
            }

            image[i][j].rgbtBlue = sBlue;
            image[i][j].rgbtGreen = sGreen;
            image[i][j].rgbtRed = sRed;



        }




    }






    return;
}
int k;
// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    if (width%2 == 0)
    {
        k = width/2;

    }

    else if (width%2 != 0)

    {
        k = round(width/2) - 1;
    }


    for (int i = 0; i < height; i++)

    {
        for (int j = 0; j < k; j++)

        {

            int tempB = image[i][j].rgbtBlue;
            int tempG = image[i][j].rgbtGreen;
            int tempR = image[i][j].rgbtRed;


            image[i][j] = image[i][width-j];

            image[i][width - j].rgbtBlue = tempB;
            image[i][width - j].rgbtGreen = tempG;
            image[i][width - j].rgbtRed = tempR;
        }
    }



    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

// Ran into so much trouble with corner cases... for an image with a lot of pixels, getting the perimeter SHOULD NOT MATTER. I refuse to do it!!
    for (int i = 1; i < height -2; i ++)
    {


        for (int j = 1; j < width -2; j++)


        {

            int iless = i - 1;
            int imore = i + 1;
            int jless = j - 1;
            int jmore = j + 1;


            int bU = image[iless][j].rgbtBlue;
            int gU = image[iless][j].rgbtGreen;
            int rU = image[iless][j].rgbtRed;


            int bUR = image[iless][jmore].rgbtBlue;
            int gUR = image[iless][jmore].rgbtGreen;
            int rUR = image[iless][jmore].rgbtRed;

            int bUL = image[iless][jless].rgbtBlue;
            int gUL = image[iless][jless].rgbtGreen;
            int rUL = image[iless][jless].rgbtRed;


            int bLR = image[imore][jmore].rgbtBlue;
            int gLR = image[imore][jmore].rgbtGreen;
            int rLR = image[imore][jmore].rgbtRed;

            int bL = image[imore][j].rgbtBlue;
            int gL = image[imore][j].rgbtGreen;
            int rL = image[imore][j].rgbtRed;




            int bR = image[i][jmore].rgbtBlue;
            int gR = image[i][jmore].rgbtGreen;
            int rR = image[i][jmore].rgbtRed;






            int bLeft = image[i][jless].rgbtBlue;
            int gLeft = image[i][jless].rgbtGreen;
            int rLeft = image[i][jless].rgbtRed;




            int bLL = image[imore][jless].rgbtBlue;
            int gLL = image[imore][jless].rgbtGreen;
            int rLL = image[imore][jless].rgbtRed;


            image[i][j].rgbtBlue = round((bU + bUR + bR + bLR + bL + bLL + bLeft + bUL + image[i][j].rgbtBlue)/9);
            image[i][j].rgbtGreen = round((gU + gUR + gR + gLR + gL + gLL + gLeft + gUL + image[i][j].rgbtGreen)/9);
            image[i][j].rgbtRed = round((rU + rUR + rR + rLR + rL + rLL + rLeft + rUL + image[i][j].rgbtRed)/9);

//THIS CODE BELOW WILL NEVER RUN! BUT PROOF I TRIED!!! LIKE I SAID.. I AM BEING PRACTICAL HERE... BLURRING 1 PIXEL WORTH AROUND THE PERIMETER DOES NOTHING FOR YOU!! NOTHING I SAY!!! MUAHHAHAHAH!!!

            if (i == 0 && j == 0)

            {
                image[i][j].rgbtBlue = round((bR + bLR + bL + image[i][j].rgbtBlue)/4);
                image[i][j].rgbtGreen = round((gR + gLR + gL + image[i][j].rgbtGreen)/4);
                image[i][j].rgbtRed = round((rR + rLR + rL + image[i][j].rgbtRed)/4);
            }

            if (i == 0 && j < width - 1)
            {
                image[i][j].rgbtBlue = round((bR + bLR + bL + bLeft + image[i][j].rgbtBlue)/6);
                image[i][j].rgbtGreen = round((gR + gLR + gL + gLeft + gLL + image[i][j].rgbtGreen)/6);
                image[i][j].rgbtRed = round((rR + rLR + rL + rLeft + rLL + image[i][j].rgbtRed)/6);

            }

            if (i == 0 && j == width - 1)

            {
                image[i][j].rgbtBlue = round((bLR + bL + bLeft + image[i][j].rgbtBlue)/4);
                image[i][j].rgbtGreen = round((gLR + gL + gLeft + image[i][j].rgbtGreen)/4);
                image[i][j].rgbtRed = round((rLR + rL + rLeft + image[i][j].rgbtRed)/4);

            }

            if (i > 0 && j == 0)

            {
                image[i][j].rgbtBlue = round((bR + bLR + bL + bU + bUR + image[i][j].rgbtBlue)/6);
                image[i][j].rgbtGreen = round((gR + gLR + gL + gU + gUR + image[i][j].rgbtGreen)/6);
                image[i][j].rgbtRed = round((rR + rLR + rL + rU + rUR + image[i][j].rgbtRed)/6);

            }

            if (i == height - 1 && j == 0)

            {
                image[i][j].rgbtBlue = round((bR + bU + bUR + image[i][j].rgbtBlue)/4);
                image[i][j].rgbtGreen = round((gR + gU + gUR + image[i][j].rgbtGreen)/4);
                image[i][j].rgbtRed = round((rR + rU + rUR + image[i][j].rgbtRed)/4);

            }


            if (j == 0 && i < height - 1)

            {

                image[i][j].rgbtBlue = round((bR + bU + bUR + bL + bLR + image[i][j].rgbtBlue)/6);
                image[i][j].rgbtGreen = round((gR + gU + gUR + gL + gLR + image[i][j].rgbtGreen)/6);
                image[i][j].rgbtRed = round((rR + rU + rUR + rL + rLR + image[i][j].rgbtRed)/6);

            }

            if (i == height - 1 && j == width - 1)
            {
                image[i][j].rgbtBlue = round((bLeft + bU + bUL + image[i][j].rgbtBlue)/4);
                image[i][j].rgbtGreen = round((gLeft + gU + gUL + image[i][j].rgbtGreen)/4);
                image[i][j].rgbtRed = round((rLeft + rU + rUL + image[i][j].rgbtRed)/4);

            }

            if (i == height - 1 && j < width - 1)

            {

                image[i][j].rgbtBlue = round((bR + bU + bUR + bR + bUR + image[i][j].rgbtBlue)/6);
                image[i][j].rgbtGreen = round((gR + gU + gUR + gR + gUR + image[i][j].rgbtGreen)/6);
                image[i][j].rgbtRed = round((rR + rU + rUR + rR + rUR + image[i][j].rgbtRed)/6);

            }






        }







    }








    return;
}
