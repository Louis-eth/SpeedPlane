#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../include/constants.h"
#include "../include/header.h"

int logInOrSignUp(int *chConnect)
{

    printf("\t\t------>YOU MUST HAVE AN ACCOUNT TO ACCESS THE FLIGHTS<------\n\n");
    printf("[0] Log in\n");
    printf("[1] Sign up\n");
    printf("[2] Exit\n\n");

    while (*chConnect > 3)
    {
        printf("Choice : ");
        scanf("%d", chConnect);
    }
    return *chConnect;
}

void logIn(UserInfos *UserInfos)
{
    FILE *userFileInfos = NULL;
    char possUserName[20] = "";
    char possPassword[20] = "";
    char final[20] = "";

    _DRED_ printf("\t------>LOG IN<------\n\n"); _RESET_

    while (userFileInfos == NULL && UserInfos->hack == 0)
    {
        printf("User name : ");
        scanf("%s", possUserName);

        if (strcmp(possUserName, "hack00") == 0)
        {
            while (strcmp(possPassword, "FreeFlights") != 0)
            {
                printf("Password  : ");
                scanf("%s", possPassword);
            }
            printf("First name: ");
            scanf("%s", UserInfos->firstName);
            printf("Last name : ");
            scanf("%s", UserInfos->lastName);
            printf("Email     : ");
            scanf("%s", UserInfos->email);
            _DGREEN_ printf("-Hack mode activated-\n\n"); _RESET_
            UserInfos->hack = 1;
        }
        else
        {
            sprintf(final,"data/%s",possUserName);
            userFileInfos = fopen(final, "r");
            if (userFileInfos == NULL){
                _DRED_ printf("Wrong UserName\n");_RESET_
            }
        }
    }

    if (!UserInfos->hack)
    {
        fscanf(userFileInfos, "%s %s %s %s %s", UserInfos->firstName, UserInfos->lastName, UserInfos->email, UserInfos->userName, UserInfos->password);
        while (strcmp(UserInfos->password, possPassword) != 0)
        {
            printf("Password  : ");
            scanf("%s", possPassword);
            if (strcmp(UserInfos->password, possPassword) != 0){
                _DRED_ printf("Wrong password\n"); _RESET_
            }
        }
        _DGREEN_ printf("-Successful connection-\n\n");_RESET_
        fclose(userFileInfos);
    }
}

void signUp(UserInfos *UserInfos){
        FILE* userFileInfos = NULL;
        char final[20] = "";

        _DRED_ printf("\t------>SIGN UP<------\n\n"); _RESET_

        do{
            printf("First name: ");scanf("%s",UserInfos->firstName);
            printf("Last name : ");scanf("%s",UserInfos->lastName);
            printf("Email     : ");scanf("%s",UserInfos->email);
            printf("User name : ");scanf("%s",UserInfos->userName);
            printf("Password  : ");scanf("%s",UserInfos->password);

            sprintf(final,"data/%s",UserInfos->userName);
            userFileInfos=fopen(final,"r");
            if(userFileInfos!=NULL){
                _DRED_ printf("Username already taken\n"); _RESET_
            }    
            else{
                _DGREEN_ printf("-Successful registration-\n\n"); _RESET_
            }
            fclose(userFileInfos);
            
        }while(userFileInfos!=NULL);

        userFileInfos=fopen(final,"w");
        if(userFileInfos==NULL){
            fprintf(stderr,"impossible to open the file -> %s <-",UserInfos->userName);
            exit(EXIT_FAILURE);
        }

        fprintf(userFileInfos, "%s ", UserInfos->firstName);
        fprintf(userFileInfos, "%s ", UserInfos->lastName);
        fprintf(userFileInfos, "%s ", UserInfos->email);
        fprintf(userFileInfos, "%s ", UserInfos->userName);
        fprintf(userFileInfos, "%s ", UserInfos->password);

        fclose(userFileInfos);
}