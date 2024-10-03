#include <stdio.h>

#define MAX 100

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    int reference;
    char name[MAX];
    char prenom[MAX];
    char phone[MAX];
    int age;
    char status[MAX];
    Date date;
} Reservation;

int reservationCount = 10;
int referenceCount = 10;
Reservation reservations[MAX] = {
                                {1,"khalid","khalid","076487213",20,"valide",{11,12,2004}},
                                {2,"Omar","lem","076487213",11,"reporte",{11,12,2002}},
                                {3,"aziz","amzmiz","076487213",22,"valide",{11,12,2024}},
                                {4,"khaldi","lemagni","076487213",18,"traite",{11,12,2024}},
                                {5,"abdo","hadoui","076487213",12,"annule",{11,12,2024}},
                                {6,"hajar","intissar","076487213",36,"reporte",{11,12,2024}},
                                {7,"kamal","legramme","076487213",56,"reporte",{11,12,2024}},
                                {8,"aya","malki","076487213",47,"traite",{11,12,2024}},
                                {9,"fatima","ouaziz","076487213",18,"valide",{11,12,2024}},
                                {10,"khawla","ennair","076487213",33,"annule",{11,12,2024}},
                                };