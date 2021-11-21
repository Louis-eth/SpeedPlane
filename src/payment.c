#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "../include/constants.h"
#include "../include/header.h"

static void delay(int number_of_seconds);

void payment(UserInfos UserInfos,BoardingPass BoardingPass)
{
    _DRED_ printf("\t\t------>PAYMENT<------\n\n");_RESET_
    
    printf("Firstname : %s\n",UserInfos.firstName);
    printf("Lastname  : %s\n",UserInfos.lastName);
    printf("Email     : %s\n",UserInfos.email);

    printf("From      : %s\n",BoardingPass.from);
    printf("To        : %s\n",BoardingPass.to);
    printf("Date      : %02d/%02d - %02d:%02d\n",BoardingPass.day,BoardingPass.month,BoardingPass.hour,BoardingPass.min);
    //printf("At %02d:%02d \n",BoardingPass.hour,BoardingPass.min);

    random_seat(&BoardingPass);
    printf("Seat      : %s\n",BoardingPass.seat);
    
    printf("PRICE : $%d\n\n",BoardingPass.price+BoardingPass.class+BoardingPass.meal);


    printf("Ethereum address : 0xB552f61455348D6adAF997C279F43f8C51dB8FAD\n");

    system("pause");

    printf(".\n");
    delay(1);
    printf("..\n");
    delay(1);
    printf("...\n");


    _DGREEN_ printf("-payment received-\n"); _RESET_

}

static void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
  
    // Storing start time
    clock_t start_time = clock();
  
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}