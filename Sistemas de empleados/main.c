#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "ArrayEmployees.h"
#include "utn.h"

int main()
{
    int opcion;
    int contadorIDemployee=0;
    int flag= -1;
    eEmployee  arrayEmployee[arrayTam];

    initEmployees(arrayEmployee,arrayTam);

    do{

        utn_getUnsignedInt(" SELECCIONE OPCION A REALIZAR: \n\n1) Dar de Alta un Empleado\n2) Modificar \n3) Dar de Baja un Empleado\n4) Informar \n5) Salir\n","Error, primero cargue datos",1,sizeof(int),1,4,2,&opcion);

        switch(opcion)
        {
            case 1:
                if(!addEmployee(arrayEmployee,arrayTam,&contadorIDemployee))
                    {
                        printf("\n Datos del empleado ingresados\n");
                        flag=0;
                        system("\npause");
                        system("cls");
                    }
                break;
            case 2:
                if(flag==0)
                {
                    employe_modificar(arrayEmployee,arrayTam);
                }
                else
                {
                    printf("\nNo se ha ingresado algun empleado");
                }
            break;
            case 3:
                if(flag==0)
                {
                    removeEmployee(arrayEmployee,arrayTam);
                }
                 else
                {
                    printf("\nNo se ha ingresado algun empleado");
                }
            case 4:
                if(flag==0)
                {
                   informarEmploye(arrayEmployee,arrayTam);
                }
                else
                {
                    printf("\nNo se ha ingresado algun empleado");
                }

            break;
            case 5:
                printf("\n Gracias por utilizar nuestro sistema.");
            break;

             default:
                printf("\nNo ingreso una opcion correcta");
        }
        system("pause");
        system("cls");

    }while(opcion!=5);
    return 0;
}
