#include <stdio.h>
#include <string.h>
#include "city_management.h"


void display_main_menu();
void city_management();
void distance_management();
void vehicle_management();
void delivery_request();
void reports();

CitySystem citySystem;

int main(){
    int choice;

    initialize_city_system(&citySystem);
    printf("Welcome to Logistics Management System\n");
    printf("System initialized successfully!\n");

    do {
        display_main_menu();
        scanf("%d", &choice);

        switch(choice){
            case 1:
                city_management_menu(&citySystem);
                break;
            case 2:
                distance_management();
                break;
            case 3:
                vehicle_management();
                break;
            case 4:
                delivery_request();
                break;
            case 5:
                reports();
                break;
            case 6:
                printf("Thank you\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 6);

    return 0;
}

void display_main_menu() {
    printf("\n========================================\n");
    printf("        MAIN MENU\n");
    printf("========================================\n");
    printf("1. City Management\n");
    printf("2. Distance Management\n");
    printf("3. Vehicle Management\n");
    printf("4. Delivery Request\n");
    printf("5. Reports\n");
    printf("6. Exit\n");
    printf("========================================\n");
    printf("Choose an option (1-6): ");
}

void distance_management(){
    printf("\n-- Distance Management --\n");
    printf("This feature will be implemented in Phase 2\n");
}

void vehicle_management(){
    printf("\n-- Vehicle Management --\n");
    printf("This feature will be implemented in Phase 3\n");
}

void delivery_request(){
    printf("\n-- Delivery Request --\n");
    printf("This feature will be implemented in Phase 4\n");
}
void reports(){
    printf("\n-- Reports --\n");
    printf("This feature will be implemented in Phase 6\n");
}
