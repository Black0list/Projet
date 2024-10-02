#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void addReservation();
void ModifyOrDeleteReservation();

void ShowReservation();
void ShowAllReservations();
void ShowReservationByReference(int id);

void SearchReservation();
int SearchReservationByReference(int id);
void SearchReservationByName();
void SearchReservationByDate();

void SortReservation();
void SortByName();
void SortByDate();

void SortByStatus();
int GetStatusIndex(char status[]);

#endif