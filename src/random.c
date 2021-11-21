#include <stdio.h>
#include <stdlib.h>

#include "../include/constants.h"
#include "../include/header.h"

int rdtsc()
{
    __asm__ __volatile__("rdtsc");
}

int *random_flights()
{
    /*Generates different random numbers. (note: find a cleaner algorithm)*/
    const int MIN = 0, MAX = 25;
    static int tab[NUM_FLIGHTS];
    srand(rdtsc());

    tab[0] = (rand() % (MAX - MIN + 1)) + MIN;
    while (tab[0] == tab[1])
        tab[1] = (rand() % (MAX - MIN + 1)) + MIN;
    while (tab[0] == tab[2] || tab[1] == tab[2])
        tab[2] = (rand() % (MAX - MIN + 1)) + MIN;
    while (tab[0] == tab[3] || tab[1] == tab[3] || tab[2] == tab[3])
        tab[3] = (rand() % (MAX - MIN + 1)) + MIN;
    while (tab[0] == tab[4] || tab[1] == tab[4] || tab[2] == tab[4] || tab[3] == tab[4])
        tab[4] = (rand() % (MAX - MIN + 1)) + MIN;

    return tab;
}

void *random_price()
{
    static int tab[NUM_FLIGHTS];
    const int MIN = 50, MAX = 300;
    srand(rdtsc());
    for (int i = 0; i < NUM_FLIGHTS; i++)
    {
        tab[i] = (rand() % (MAX - MIN + 1)) + MIN;
    }
    return tab;
}

void random_seat(BoardingPass *BoardingPass){
    const int MIN = 0,MAX=9;
    srand(rdtsc());
    char *str[10]={"A","B","C","D","E","F","G","H","I","J"};
    char *num[10]={"1","2","3","4","5","6","7","8","9","10"};
    char random_seat[3]="";

    int r=rand() % (MAX - MIN + 1) + MIN;
    
    sprintf(BoardingPass->seat,"%s-%s",str[r],num[r]);

}

void *random_minute()
{
    const int MIN = 10, MAX = 59;
    static int tab[NUM_FLIGHTS];
    srand(rdtsc());

    for (int i = 0; i < NUM_FLIGHTS; i++)
    {
        tab[i] = (rand() % (MAX - MIN + 1)) + MIN;
    }
    return tab;
}

void *random_hour(int h)
{
    const int MIN = h + 1, MAX = 23;
    static int tab[NUM_FLIGHTS];
    srand(rdtsc());

    for (int i = 0; i < NUM_FLIGHTS; i++)
    {
        tab[i] = (rand() % (MAX - MIN + 1)) + MIN;
    }
    return tab;
}