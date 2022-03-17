#include <stdio.h>

int n, firstd, count, lastd,secondd;

char* odigit[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

char* twdigits[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

char* thdigits[] = {"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};


int main()
{

        do
        {

            printf("\nInsert number from 1 to 1000: \n");

            scanf("\n%d", &n);      //Input number into n

            firstd = n;             //firstd == first digit, used for numbers with 2 or more digits

            if(n<=0 || n>1000)
            {

                printf("\nInvalid number\n");       //validating inserted data
            }
            else
            {

                if(n > 0 && n < 10)
                {

                    printf("%s\n", odigit[n - 1]);      //print numbers from 1 to 10

                }
                else

                    if(n >= 10 && n <= 19)
                    {

                        printf("%s\n", twdigits[n - 10]);       //print numbers  from 10 to 19

                    }
                    else

                        if(n >= 20 && n <= 99)
                        {

                            while(firstd >= 10)

                            {
                                firstd = firstd / 10;       //check what is the first digit of the number
                            }

                            lastd = n % 10;                 //check what is the last digit of the number

                            if(lastd != 0)
                            {

                                printf("%s %s\n", thdigits[firstd - 2], odigit[lastd - 1]); //print numbers from 20 to 99. that doesnt have zero as last number (like 20,30,40..)

                            }
                            else
                            {

                                printf("%s\n", thdigits[firstd - 2]); //print numbers with from 20 to 99 that the second one is zero

                            }

                        }
                        else if(n >= 100 && n <= 999)
                        {

                            while(firstd >= 10)

                            {
                                firstd = firstd / 100;      //check the first digit of 3
                                secondd = (n / 10) % 10;    //check the second digit of 3
                                lastd = n % 10;             // check the last digit of 3

                            }

                            if(secondd == 0 && lastd == 0)
                            {

                                printf("%s hundred \n", odigit[firstd - 1]); //full "hundred numbers" (100, 200, 300)

                            }
                            else if(secondd == 0)
                            {

                                printf("%s hundred %s\n", odigit[firstd - 1], odigit[lastd - 1]); //print numbers that second digit is zero (like 201, 202...)

                            }
                            else if(secondd == 1 && lastd == 0)
                            {

                                printf("%s hundred %s\n", odigit[firstd - 1], twdigits[secondd - 1]); //print number 10 of hundreds (two hundred ten)

                            }
                            else if(secondd == 1 && lastd != 0)
                            {

                                printf("%s hundred %s\n", odigit[firstd - 1], twdigits[secondd + lastd - 1]); //print numbers from 11 to 19 of hundreds (for ex: 211)

                            }
                            else if(secondd != 1 && secondd != 0 && lastd == 0)
                            {

                                printf("%s hundred %s\n", odigit[firstd - 1], thdigits[secondd - 2]); //print when second digit != 0 and 1 (ou seja, 220, 230, 340,550)

                            }
                            else
                            {

                                printf("%s hundred %s %s\n", odigit[firstd - 1], thdigits[secondd - 2], odigit[lastd - 1]);

                            }



                        }
                        else
                        {

                            printf("one thousand\n\n"); //as no numbers over 1000 are allowed, it was used only one print for it.

                        }

            }

        }

        while(n<=0 || n>1000);


        system("PAUSE");
    }
