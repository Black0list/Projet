#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void addReservation();
void ModifyOrDeleteReservation();

void ShowReservation();
void ShowAllReservations(Reservation NEW[]);
void ShowReservationByReference(int id);

void SearchReservation();
int SearchReservationByReference(int id);
void SearchReservationByName(char name[]);
void SearchReservationByDate(int day, int month, int year);

void SortReservation();
void Sort(int type, Reservation NEW[]);

int GetStatusIndex(char status[]);


void Statistics();
void AverageAge();
void SectionsAge();
void TotaleReservationsByStatus();

void InputChar(char input[]);
#endif