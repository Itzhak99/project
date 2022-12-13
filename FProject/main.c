//
// Created by Barak
//

#include "headers/functions.h"
#include "headers/airport_manager.h"
#include "headers/airline.h"
#include "Passengers.h"

void freeAll(AirportManager* airportManager, Airline* airline) {
    freeAirportManager(airportManager);
    freeAirline(airline);
}

void printMenu() {
    printf("\n1. Add Flight to airline\n"
           "2. Add Airport to AirportManager\n"
           "3. Print Airline data\n"
           "4. Print AirportManager data\n"
           "5. Print all flights by airports\n"
           "6. Passengers Management\n"
           "7. Quit\n\n"
           "Enter your choose:");
}

int getChoose() {
    int choose = 0;
    while (choose > 7 || choose < 1) {
        printMenu();
        scanf("%d", &choose);
    }
    return choose;
}

void printPassMenu() {
    printf("1. Print Passengers\n"
           "2. Add Passengers\n");
}

int PassengersChoose()
{
    int choose = 0;
    while (choose > 2 || choose < 1) {
        printPassMenu();
        scanf("%d", &choose);
    }
    return choose;
}


void run(AirportManager* airportManager, Airline* airline,struct plane *A) {
    int choose = getChoose();
    int PC;
    while (choose != 7) {
        flush();
        switch (choose) {
            case 1:
                addFlight(airportManager, airline);
                break;
            case 2:
                addAirport(airportManager);
                break;
            case 3:
                printAirline(airportManager, airline);
                break;
            case 4:
                printAirportManager(airportManager);
                break;
            case 5:
                printAllFlightsInLine(airportManager, airline);
                break;
            case 6:
            {
                PC = PassengersChoose();
                switch(PC)
                {
                    case 1:
                    {
                        PrintPlane(&A);
                        break;
                    }
                    case 2:
                    {
                        AddPassenger(&A);
                        break;
                    }
                    default:
                    {
                        printf("\nSayonara bitches.");
                        break;
                    }
                }
            }
        }
        choose = getChoose();
    }
    printf(EXIT);
}

int main() {

    struct plane A = planeini();

    // init Airport Manager
    AirportManager airportManager;
    initAirportManager(&airportManager);

    // add airports
    int airport_num;
    printf(ENTER_NUMBER_OF_AIRPORTS);
    scanf("%d", &airport_num);
    flush();

    for (int i = 0; i < airport_num; i++)
        addAirport(&airportManager);

    // init Airline
    Airline airline;
    initAirline(&airline);

    // menu
    run(&airportManager, &airline,&A);

    // exit
    freeAll(&airportManager, &airline);

    return 0;
}
