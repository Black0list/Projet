#include <stdio.h>

#define MAX 100

typedef struct {
    int reference;
    char name[MAX];
    char prenom[MAX];
    char phone[MAX];
    int age;
    char status[MAX];
    char date[MAX];
} Reservation;

int reservationCount = 10;
int referenceCount = 10;
Reservation reservations[MAX] = {
                                {1,"khalid","khalid","076487213",20,"valide","12/12/2024"},
                                {2,"Omar","lem","076487213",11,"reporte","12/1/2024"},
                                {3,"aziz","amzmiz","076487213",22,"valide","12/11/2024"},
                                {4,"khalid","lemagni","076487213",18,"traite","12/4/2025"},
                                {5,"abdo","hadoui","076487213",12,"annule","12/20/2024"},
                                {6,"hajar","intissar","076487213",36,"reporte","1/10/2024"},
                                {7,"kamal","legramme","076487213",56,"reporte","29/11/2024"},
                                {8,"aya","malki","076487213",47,"traite","1/3/2025"},
                                {9,"fatima","ouaziz","076487213",18,"valide","23/11/2024"},
                                {10,"khawla","ennair","076487213",33,"annule","20/6/2025"},
                                };
