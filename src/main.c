#include <stdlib.h>
#include <stdio.h>
//#include <windows.h>

#include "../include/constants.h"
#include "../include/header.h"

int main()
{
    system("python3 src/check_module.py");
    homeMsg();

    int chConnect = INIT;
    struct UserInfos UserInfos = {"", "", "", "", "", 0};

    logInOrSignUp(&chConnect);
    if (chConnect == 0)
        logIn(&UserInfos);

    if (chConnect == 1)
        signUp(&UserInfos);

    if (chConnect == 2)
        exitProg();


    char *flights[25] = {"Los Angeles", "New York", "Paris", "Tokyo", "Canberra", "Berlin", "Marseille", "Barcelone",
                         "Lisbonne", "Medellin", "Buenos Aires", "Moscou", "Auckland", "Alger", "Nassau", "Bruxelles", 
                         "Pekin", "Rio", "Madrid", "Athenes", "Budapest", "Dublin", "London", "Rome", "Monaco"};

    int *f = random_flights();//*f est un tableau de 5 chiffres. 

    BoardingPass BoardingPass={"","",0,0,0,0,0,0,0,0}; 
    BoardingPass = set_destination(flights,f,UserInfos.hack);
    
    BoardingPass.class=optionClass(UserInfos.hack);
    BoardingPass.meal=optionMeal(UserInfos.hack);

    payment(UserInfos,BoardingPass);

    printf("Writing the Boarding pass...\n");
    writeBoardingPass(UserInfos,BoardingPass);//create csv file.
    system("python3 src/createBoardingPass.py");//create the qrcode and the card.
    printf("Well done ! Your flight has been booked !\n");

    exitProg();
    return EXIT_SUCCESS;
}
