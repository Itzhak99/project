//
// Created by amitg on 13/12/2022.
//

#ifndef ASSIGNMENT2_PASSENGERS_H
#define ASSIGNMENT2_PASSENGERS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#define Name_Size 10
#define Plane_Size 20
#define Price 79

struct Passengers{
    char first_name[Name_Size];
    char last_name[Name_Size];
    int id;
    char seat[3];//ABC DEF and number between 1-30
};

struct plane{
    struct Passengers *People[Plane_Size];
    int Occupied;
    int MoneyEarned; //79$ per person
};

void PrintPlane(struct plane *A);
struct Passengers passini();
struct plane planeini();
void AddPassenger(struct plane *A);
int DollartoNIS();
void profit(int num);

#endif //ASSIGNMENT2_PASSENGERS_H
