#ifndef __HEADER__H__
#define __HEADER__H__

    #include "../include/constants.h"
    
    //void Color(int textColor,int backgroundColor);
    void homeMsg();
    
    void exitProg();

    int logInOrSignUp(int *chConnect);
    void logIn(UserInfos *UserInfos);
    void signUp(UserInfos *UserInfos);

    int rdtsc();
    int *random_flights();
    void *random_price();
    void random_seat(BoardingPass *BoardingPass);
    void *random_minute();
    void *random_hour(int h);

    BoardingPass set_destination(char *flights[],int *f,int hack);

    int optionClass(int hack);
    int optionMeal(int hack);

    void payment(UserInfos UserInfos,BoardingPass BoardingPass);

    void writeBoardingPass(UserInfos UserInfos,BoardingPass BoardingPass);

#endif