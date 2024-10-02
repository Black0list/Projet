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

int reservationCount = 0;
int referenceCount = 0;
Reservation reservations[MAX];
