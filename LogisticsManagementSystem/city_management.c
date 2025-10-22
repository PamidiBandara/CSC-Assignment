#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "city_management.h"

void initialize_city_system(CitySystem *system){
    system->cityCount = 0;
    printf("City system initialized\n");
}

void add_city(CitySystem*system){
    if (system->cityCount >= MAX_CITIES){
        printf("Error: Maximum number of cities (%d) reached!\n", MAX_CITIES);
        return;
    }

    char cityName[MAX_CITY_NAME_LENGTH];
    printf("Enter city name: ");
    scanf(" %[^\n]", cityName);


    for(int i=0; i<system->cityCount;i++){
        if (strcasecmp(system->cities[i].name, cityName) == 0){
            printf("Error: City '%s' already exists!\n", cityName);
            return;
        }
    }

    strcpy(system->cities[system->cityCount].name, cityName);
    system->cities[system->cityCount].index = system->cityCount;
    system->cityCount++;

    printf("City '%s' added successfully! (Index: %d)\n", cityName,system->cityCount-1);
}

void display_cities(CitySystem *system){
    printf("\nList of Cities\n");
    if (system->cityCount == 0) {
        printf("No cities added yet.\n");
        return;
    }

    printf("%-5s %-20s %s\n", "Index", "City Name", "Status");
    printf("------------------------------\n");
    for (int i=0;i<system->cityCount;i++){
        printf("%-5d %-20s %s\n",
               i,
               system->cities[i].name,
               "Active");
    }
    printf("Total cities: %d\n", system->cityCount);
}

void remove_city(CitySystem *system){
    if (system->cityCount == 0){
        printf("No cities to remove!\n");
        return;
    }

    display_cities(system);
    int index;
    printf("Enter city index to remove: ");
    scanf("%d", &index);

    if (index<0 || index>=system->cityCount){
        printf("Error: Invalid city index!\n");
        return;
    }

    printf("Are you sure you want to remove '%s'? (y/n): ", system->cities[index].name);
    char confirm;
    scanf(" %c", &confirm);

    if (confirm == 'y' || confirm == 'Y') {
        for (int i=index;i<system->cityCount-1;i++){
            strcpy(system->cities[i].name, system->cities[i+1].name);
            system->cities[i].index=i;
        }
        system->cityCount--;
        printf("City removed successfully!\n");
        } else {
        printf("City removal cancelled.\n");
       }
}

void rename_city(CitySystem *system){
    if (system->cityCount == 0) {
        printf("No cities to rename!\n");
        return;
    }

    display_cities(system);
    int index;
    printf("Enter city index to rename: ");
    scanf("%d", &index);

    if (index<0 || index>= system->cityCount){
        printf("Error: Invalid city index!\n");
        return;
    }

    char newName[MAX_CITY_NAME_LENGTH];
    printf("Enter new name for '%s': ", system->cities[index].name);
    scanf(" %[^\n]", newName);


    for (int i=0;i<system->cityCount;i++){
        if (i!= index && strcasecmp(system->cities[i].name, newName) == 0){
            printf("Error: City '%s' already exists!\n", newName);
            return;
        }
    }

    printf("Renaming '%s' to '%s'..\n", system->cities[index].name, newName);
    strcpy(system->cities[index].name, newName);
    printf("City renamed successfully\n");
}

void city_management_menu(CitySystem *system){
    int choice;

    do {
        printf("\n-- City Management Menu --\n");
        printf("1.Add City\n");
        printf("2.Display Cities\n");
        printf("3.Remove City\n");
        printf("4.Rename City\n");
        printf("5.Back to Main Menu\n");
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_city(system);
                break;
            case 2:
                display_cities(system);
               break;
            case 3:
                remove_city(system);
               break;
            case 4:
                rename_city(system);
                break;
            case 5:
                printf("Returning to main meu\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    while(choice!=5);
}
