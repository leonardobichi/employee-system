#ifndef ARRAYEMPLOYEE_H_INCLUDED
#define ARRAYEMPLOYEE_H_INCLUDED
#define TEXT_SIZE 20
#define arrayTam 2

typedef struct
{
    int id;
    char name[40];
    char lastName[40];
    float salary;
    int sector;
    int isEmpty;
}eEmployee;


int initEmployees(eEmployee* list, int limite);
int addEmployee(eEmployee* list, int limite, int* contadorID);
int findEmptyEmployee(eEmployee* list, int limite, int *position);
int findEmployeeById(eEmployee* list, int limite,int id, int *position);
int employe_modificar(eEmployee array[], int limite);
int removeEmployee(eEmployee* list, int limite);
int printEmployees(eEmployee* list, int limite);
int sortEmployees(eEmployee* list, int limite);
int promediosEmployees(eEmployee* list, int limite);
int informarEmploye(eEmployee list[], int limite);

#endif
