/******************
Name: Shani Attiya
ID:322264748
Assignment: EX2
*******************/

#include <stdio.h>

int main()
{
    int userChoice;
    printf("Welcome to our games, please choose an option\n");
    do
    {
        // Displaying the menu
        printf("1: Ducky's Unity Game\n");
        printf("2: The Memory Game\n");
        printf("3: Professor Pat's Power Calculation\n");
        printf("4: The Duck Parade\n");
        printf("5: The Mystery of the Repeated Digits\n");
        printf("6: Good Night Ducks\n");
        scanf("%d", &userChoice);

        // checking for valid input
        if (userChoice < 1 || userChoice > 6)
        {
            printf("Invalid option, please try again\n\n");
        }
    } while (userChoice < 1 || userChoice > 6);

    switch (userChoice) // going by the selected choices
    {
    case 1:
        int Duckynum, bit, corns = 0;
        printf("please enter a positive number:");
        scanf("%d", &Duckynum);

        // checking if the input is valid
        while (Duckynum <= 0)
        {
            printf("Invalid number, try again");
            scanf("%d", &Duckynum);
        }
        // checking the lsb and if its 1 -- adding to Ducky's corns!
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
    case 2:
        int numOfDucks, sound, saveSounds, produce = 0;
        printf("please enter a positive number:");
        scanf("%d", &numOfDucks);

        // checking if the input is valid
        while ((numOfDucks <= 0 || numOfDucks > 64))
        {
            printf("Invalid number, try again");
            scanf("%d", &numOfDucks);
        }
        // the user decides a sound for each duck. than we save it
        for (int duck = 1; duck < numOfDucks; duck++) 
        {
            printf("duck %d do QUAK? 1 for yes, 0 for no\n", duck);
            scanf("%d", &sound);
            while (sound != 0 && sound != 1)
            {
                printf("Invalid input, enter 1 for QUAK or 0 for SH...: \n");
                scanf("%d", &sound);
            }
            saveSounds |= ((long long)sound << duck);
        }
         // printing what each duck is saying
        for (int i = 1; i < numOfDucks; i++)
        {
            produce = saveSounds & 1;
            saveSounds = saveSounds >> 1;
            if (produce == 1)
            {
                printf("Duck number %d says QUAK \n", i);
            }
            else
            {
                printf("Duck number %d says Sh..\n", i);
            }
        }

        break;
        
    case 3:
        printf("3");
        break;
    case 4:
        printf("4");
        break;

    case 5:
        printf("5");
        break;

    case 6:
        printf("Good Night! see tou at the pond tomorrow.\n");
        break;
    }

    return 0;
}
