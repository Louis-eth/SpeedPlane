#include <stdio.h>
#include <windows.h>

#include "../include/constants.h"
#include "../include/header.h"

void Color(int textColor,int backgroundColor) // fonction d'affichage de couleurs
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,backgroundColor*16+textColor);
    /*0: black
    1: Dark blue
    2: Dark green
    3: Blue
    4: Dark red
    5: Purple
    6: Goose poo green
    7: Light gray
    8: Dark gray
    9: Neon blue
    10: Neon green
    11: Turquoise
    12: Neon red
    13: Purple 2
    14: Yellow
    15: White*/
}
void homeMsg(){
    printf("\n");
        _DBLUE_ printf("\t\t\t   _____ ____  ________________     ____  __    ___    _   ________\n");
        _DBLUE_ printf("\t\t\t  / ___// __ \x5c/ ____/ ____/ __ \x5c   / __ \x5c/ /   /   |  / | / / ____/\n");
        _RESET_ printf("\t\t\t  \x5c__ \x5c/ /_/ / __/ / __/ / / / /  / /_/ / /   / /| | /  |/ / __/   \n");
        _DRED_ printf("\t\t\t ___/ / ____/ /___/ /___/ /_/ /  / ____/ /___/ ___ |/ /|  / /___   \n");
        _DRED_ printf("\t\t\t/____/_/   /_____/_____/_____/  /_/   /_____/_/  |_/_/ |_/_____/   \n");
        _RESET_

    printf("\n");

        printf("\t\t\t\t\t\t       __|__       \n");
        _DBLUE_ printf("\t\t\t\t\t\t--o--o--");
        _RESET_ printf("(_)");
        _DRED_ printf("--o--o--\n");_RESET_
    
    printf("\n");
    _GREY_ printf("\t\t\tWant to get away from it all? book a flight for the same day !\n\n");_RESET_
    printf("\n\n");
}