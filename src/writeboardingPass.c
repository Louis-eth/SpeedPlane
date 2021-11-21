#include <stdio.h>
#include <stdlib.h>

#include "../include/constants.h"
#include "../include/header.h"

void writeBoardingPass(UserInfos UserInfos,BoardingPass BoardingPass)
{
    FILE* boarding = NULL;
    boarding=fopen("boardingPass_SpeedPlane.csv","w");

    char *str[5] = {
        UserInfos.firstName,
        UserInfos.lastName,

        BoardingPass.from,
        BoardingPass.to,
        BoardingPass.seat,
    };

    int num[4]={
        BoardingPass.day,
        BoardingPass.month,
        BoardingPass.hour,
        BoardingPass.min,
    };

    fprintf(boarding,"Firstname;Lastname;From;To;Seat;Date;Hour\n");

    for (int i = 0; i < 5; i++)
    {
        fprintf(boarding,"%s;",str[i]);
    }

    for(int i=0; i<3;i++)
    {
        if (i == 0){
            fprintf(boarding,"%d/%d;",num[i],num[i+1]);
        }

        if(i == 2){
            fprintf(boarding,"%d:%d",num[i],num[i+1]);
        }
    }

    fclose(boarding);
}