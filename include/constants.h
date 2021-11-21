#ifndef __CONSTANTS__H__
#define __CONSTANTS__H__

    void Color(int textColor,int backgroundColor);
    #define _BLUE_ Color(3, 0);
    #define _DBLUE_ Color(1, 0);
    #define _RESET_ Color(15, 0);
    #define _DGREEN_ Color(2, 0);
    #define _DRED_ Color(4, 0);
    #define _PURPLE_ Color(13, 0);
    #define _DPURPLE_ Color(5, 0);
    #define _GREY_ Color(8, 0);

    #define NUM_FLIGHTS 5
    #define INIT 10

    //define pour les random, random_seat - price ...


    typedef struct UserInfos
    {
        char firstName[20];
        char lastName[20];
        char userName[20];
        char email[30];
        char password[20];

        int hack;
    } UserInfos;

    typedef struct BoardingPass
    {
        char from[30];
        char to[30];
        
        int hour;
        int min;
        int day;
        int month;

        int price;
        char seat[3];

        //options
        int class;
        int meal;

    }BoardingPass;

    typedef struct GetTime{
        int month;
        int day;
        int hour;
        int min;
    }GetTime;

    
    typedef enum Class{
        Eco,PrenEco,Business,First
    }Class;

    typedef enum Meal{
        NoMeals,Basic,Pren,Gour   
    }Meal;
    
#endif
