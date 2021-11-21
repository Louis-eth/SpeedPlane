#include <stdio.h>
#include <stdlib.h>

#include "../include/header.h"
#include "../include/constants.h"

// Essayer tableau avec enumération pour plus facile. 

int optionClass(int hack){
    _DRED_ printf("\t\t------>OPTIONS<------\n\n");_RESET_

    Class Class;
    int class[NUM_FLIGHTS];

    if(!hack){
        class[Eco]=0;
        class[PrenEco]=200;
        class[Business]=400;
        class[First]=1000;
    }
    
    _DBLUE_ printf("\tCLASS :\n");_RESET_
    int classChoice=INIT;
    printf("0- Economy Class         ---> +$%d\n",class[Eco]);
    printf("1- Premium Economy Class ---> +$%d\n",class[PrenEco]);
    printf("2- Business Class        ---> +$%d\n",class[Business]);
    printf("3- First Class           ---> +$%d\n",class[First]);

    while(classChoice>4){
        printf("Choice : ");scanf("%d",&classChoice);
    }
    printf("\n");

    return class[classChoice];

}


int optionMeal(int hack){
    Meal Meal;
    int meal[NUM_FLIGHTS];

    if(!hack){
        meal[NoMeals]=0;
        meal[Basic]=30;
        meal[Pren]=60;
        meal[Gour]=120;
    }
    _DBLUE_ printf("\tMEAL :\n");_RESET_
    int mealChoice=INIT;
    printf("0- No meals        ---> +$%d\n",meal[NoMeals]);
    printf("1- Basic meal      ---> +$%d\n",meal[Basic]);
    printf("2- Prenium meal    ---> +$%d\n",meal[Pren]);
    printf("3- Gourmet meal    ---> +$%d\n",meal[Gour]);

    while(mealChoice>4){
        printf("Choice : ");scanf("%d",&mealChoice);
    }
    printf("\n");

    return meal[mealChoice];
}