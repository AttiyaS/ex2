/******************
Name: Shani Attiya
ID:322264748
Assignment: EX2
*******************/

#include <stdio.h>

int main()
{
    int userChoice;

    do
    {
        // Displaying the menu
        printf("\n Welcome to our games, please choose an option:\n");
        printf("1. Ducky's Unity Game\n");
        printf("2. The Memory Game\n");
        printf("3. Professor Pat's Power Calculation\n");
        printf("4. The Duck Parade\n");
        printf("5. The Mystery of the Repeated Digits\n");
        printf("6. Good Night Ducks\n");
        scanf("%d", &userChoice);

        // checking for valid input
        if (userChoice < 1 || userChoice > 6)
        {
            printf("Invalid option, please try again\n");

            // to prevent entering the switch with an invalid input
            continue;
        }

        // going by the selected choices
        switch (userChoice)
        {
            // Ducky's Unity Game: each 1=1 corn
        case 1:

            // getting the input
            int Duckynum, bit, corns = 0;
            printf("please enter a positive number:\n");
            scanf("%d", &Duckynum);

            // checking if the input is valid
            while (Duckynum <= 0)
            {
                printf("please enter a positive number\n");
                scanf("%d", &Duckynum);
            }
            // checking the lsb and if its 1 -- adding 1 to Ducky's corns!
            while (Duckynum > 0)
            {
                bit = Duckynum & 1;
                Duckynum = Duckynum >> 1;
                if (bit == 1)
                {
                    corns++;
                }
            }
            printf("Ducky earns %d corns", corns);

            break;
            // The Memory Game
        case 2:
            long numOfDucks;
            int sound, saveSounds, produce, duckind = 0;
            printf("please enter the number of ducks:\n");
            scanf("%ld", &numOfDucks);
            printf("you entered %ld ducks\n", numOfDucks);
            // checking if the input is valid
            while ((numOfDucks <= 0 || numOfDucks > 64))
            {
                printf("Invalid number, try again");
                scanf("%ld", &numOfDucks);
            }

            // the user decides a sound for each duck. 1 QUAK 0 SH..  than we save it
            for (int duck = 0; duck < numOfDucks; duck++)
            {
                duckind = duck + 1;
                printf("duck %d do QUAK? 1 for yes, 0 for no\n", duckind);
                scanf("%d", &sound);

                // preventing an invalid input
                while (sound != 0 && sound != 1)
                {
                    printf("Invalid input, enter 1 for QUAK or 0 for SH...: \n");
                    scanf("%d", &sound);
                }

                saveSounds |= ((long long)sound << duck);
            }
            // printing what each duck is saying
            for (int i = 0; i < numOfDucks; i++)
            {
                produce = saveSounds & 1;
                saveSounds = saveSounds >> 1;
                if (produce == 1)
                {
                    duckind = i + 1;
                    printf("duck number %d do Quak\n", duckind);
                }
                else if (produce == 0)
                {
                    printf("duck number %d do Sh..\n", duckind);
                }
            }

            break;

        case 3:
            int numBase, numExp = 0;
            int result = 1;
            printf("please enter the number\n");
            scanf("%d", &numBase);
            printf("please enter the exponent\n");
            scanf("%d", &numExp);

            // this loop starting duplicates the base by itself expo time
            for (int i = 0; i < numExp; i++)
            {
                result = result * numBase;
            }
            printf("your power is: %d \n", result);
            break;

        case 4:

            int num_of_ducks = 0;
            do
            {
                printf("please enter number of ducks:\n");
                scanf("%d", &num_of_ducks);

                // checking for an invalid input..
                if ((num_of_ducks > 64 || num_of_ducks < 0))
                {
                    printf("invalid number, please try again");
                    continue;
                }

                // printing duck: 3 lines each time there is a 10: 1

                int start = 0;

                while (start < num_of_ducks)
                {
                    int count = num_of_ducks - start;
                    if (count > 10)
                        count = 10;  

                    // line 1: head
                    for (int i = 0; i < count; i++)
                    {
                        printf(" _");
                    }
                    printf("\n");

                    // line 2: body
                    for (int i = 0; i < count; i++)
                    {
                        printf(" __(o)>");
                    }
                    printf("\n");

                    // line 3: legs
                    for (int i = 0; i < count; i++)
                    {
                        printf(" \\___)");
                    }
                    printf("\n");

                    //next 10 ducks
                    start += 10;
                }

            } while ((num_of_ducks > 64 || num_of_ducks < 0));

            break;

        case 5:
            long choice, mask, temp, dig_for_mask, num_for_temp = 0;

            printf("please enter number\n");
            scanf("%ld", &choice);
            mask = choice;

            while (mask > 0)
            {
                // taking the 1st digit from the right
                dig_for_mask = mask % 10;
                // then "removing" it
                mask = mask / 10;
                temp = mask;

                while (temp > 0)
                {
                    num_for_temp = temp % 10;

                    if (num_for_temp == dig_for_mask)
                    {
                        printf(" %ld appears more than once!\n", dig_for_mask);
                        break;
                    }
                    temp = temp / 10;
                }
            }

            break;

        case 6:
            printf("Good night! See you at the pond tomorrow.\n");
            break;
        }
    } while (userChoice != 6);

    return 0;
}
