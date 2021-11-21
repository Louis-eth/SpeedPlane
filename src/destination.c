#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "../include/constants.h"
#include "../include/header.h"

static void init_clock(GetTime *get_time);
static int largest_word(int *f,char *flights[]);
static void space_char(int max,int fx);

BoardingPass set_destination(char *flights[],int *f,int hack)
{
    BoardingPass BoardingPass;

    GetTime GetTime;
    init_clock(&GetTime);

    _DRED_ printf("\t\t------>FLIGHTS AVAILABLE TODAY (%02d/%02d - %02d:%02d)<------\n\n", GetTime.day, GetTime.month, GetTime.hour, GetTime.min); _RESET_

    printf("From : ");
    scanf("%s",BoardingPass.from);

    int max=largest_word(f,flights);

    int *price=random_price();
    if (hack){
        for (int i = 0; i < NUM_FLIGHTS; i++)
        {
            price[i]=0;
        }      
    }
    
    int *hour=random_hour(GetTime.hour);
    int *min=random_minute();

    for (int i = 0; i < NUM_FLIGHTS; i++)
    {
        printf("%d- %s   --->   %s",i,BoardingPass.from, flights[f[i]]);
        space_char(max, strlen(flights[f[i]]));
        printf("-------->   departure at %d:%d   ", hour[i], min[i]);
        printf("-------->   Starting at $%d\n", price[i]);
    }
    int destCh = INIT;
    while(destCh>NUM_FLIGHTS){
        printf("Choice : ");
        scanf("%d",&destCh);
    }
    BoardingPass.hour = hour[destCh];
    BoardingPass.min = min[destCh];
    BoardingPass.day=GetTime.day;
    BoardingPass.month=GetTime.month;

    strcpy(BoardingPass.to,flights[f[destCh]]);

    BoardingPass.price = price[destCh];

    return BoardingPass;

}

static void init_clock(GetTime *get_time)
{
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);

    get_time->hour = local->tm_hour;
    get_time->min = local->tm_min;
    get_time->day = local->tm_mday;
    get_time->month = local->tm_mon + 1;
}

static int largest_word(int *f,char *flights[]){
    int max=0;
    for (int i = 0; i < NUM_FLIGHTS; i++)
    {
        if(strlen(flights[f[i]])>max){
            max=strlen(flights[f[i]]);
        }
    }
    return max;
}
static void space_char(int max,int fx){
    //3->number of space_chars
    int space_char=0;
    int i=0;
    space_char=(max-fx)+3;
    while(space_char>i){
        printf(" ");//space_char()
        i++;
    }
}