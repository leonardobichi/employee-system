#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "ArrayEmployees.h"
#include "utn.h"

int initEmployees(eEmployee* list, int limite)
{
    int retorno= -1;
    int i;
    if(list!= NULL &&limite>0)
    {
        for(i=0;i<limite;i++)
        {
            list[i].isEmpty= 1;
        }
        retorno=0;
    }
    return retorno;
}

int addEmployee(eEmployee* list, int limite, int* contadorID)
{
    int retorno= -1;
    int posicion;


    if(list!=NULL && limite>0 && contadorID!=NULL)
    {
        if(findEmptyEmployee(list,limite,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {

            (*contadorID)++;
            list[posicion].id=*contadorID;
            list[posicion].isEmpty = 0;
            utn_getName("\nIngrese nombre de empleado: ","\nError",1,20,3,list[posicion].name);
            utn_getName("\nIngrese apellido de empleado: ","\nError",1,20,3,list[posicion].lastName);
            utn_getFloat("\nIngrese sueldo del empleado: ","\nError",1,10,1,10,3,&list[posicion].salary);
            utn_getUnsignedInt("\nIngrese sector del empleado: \n1)RRHH\n2)contabilidad\n3)Administracion\n ","\Error opcion invalida",1,sizeof(int),1,3,2,&list[posicion].sector);


            system("cls");
            printf("\n ID: %d\n Nombre: %s\n Apellido: %s\n Sueldo: %.2f\n Sector: %d",list[posicion].id,list[posicion].name,list[posicion].lastName,list[posicion].salary,list[posicion].sector);


            retorno= 0;
        }
    }

    return retorno;
}

int findEmptyEmployee(eEmployee* list, int limite, int *position)
{
    int retorno=-1;
    int i;
    if(list!= NULL && limite>=0 && position!=NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(list[i].isEmpty==1)
            {
                retorno = 0;
                *position = i;
                break;
            }
        }
    }
    return retorno;
}

int employe_modificar(eEmployee array[], int limite)
{
    int retorno=-1;
    int posicion;
    int id;
    char opcion;
    if(array!=NULL && limite>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,limite,1,&id);
        if(findEmployeeById(array,limite,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {
                utn_getChar("\nModificar: \nA-Nombre \nB-Apellido \nS(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
            {
                    case 'A':
                        utn_getName("\nIngrese el nuevo nombre: ","\nError",1,TEXT_SIZE,1,array[posicion].name);
                        break;
                   case 'B':
                        utn_getLastName("\nIngrese apellido: ","\nError, ingrese nuevamente",1,TEXT_SIZE,2,array[posicion].lastName);

                    case 'S':
                         system("cls");
                        system("pause");
                        break;
                    default:
                        printf("\nOpcion no valida\n");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}

int findEmployeeById(eEmployee* list, int limite,int id, int *position)
{
    int retorno=-1;
    int i;
    if(list!= NULL && limite>=0)
    {
        for(i=0;i<limite;i++)
        {
            if(list[i].isEmpty==1)
                continue;
            else if(list[i].id==id)
            {
                retorno=0;
                *position = i;
                break;
            }
        }
    }
    return retorno;
}

int removeEmployee(eEmployee* list, int limite)
{
    int retorno= -1;
    int posicion;
    int id;
    if(list!=NULL && limite>0)
    {
        printEmployees(list, limite);
        utn_getUnsignedInt("\nID del empleado que se quiere dar de baja : ","\nError",1,sizeof(int),1,limite,1,&id);
        if(findEmployeeById(list,limite,id,&posicion)== -1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            list[posicion].isEmpty=1;
            list[posicion].id=0;
            strcpy(list[posicion].name,"");
            strcpy(list[posicion].lastName,"");
            list[posicion].sector=0;
            list[posicion].salary=0;
            retorno=0;

            printf("Empleado eliminado exitosamente.\n");
        }
    }
    system("cls");
    system("pause");
    return retorno;
}

int sortEmployees(eEmployee* list, int limite)
{
    int retorno= -1;
    int i;
    int j;
    int elegir;
    eEmployee auxList;
    eEmployee auxSector;


 do{    //OPCIONES
        utn_getUnsignedInt("\n\n SELECCIONE OPCION A REALIZAR: \n\n1) Ordenar empleados de la A a la Z y sector de menor a mayor \n2)Ordenar empleados de la A a la Z y sector de mayor a menor \n3)Salir ","Error, ingrese una opcion valida",1,sizeof(int),1,3,2,&elegir);


        switch(elegir)
        {
            case 1:

                for(i=0; i < limite - 1; i++)
             {
                    if(list[i].isEmpty == -1)
                    {
                        continue;
                    }
                for(j=i+1; j < limite; j++)
                {
                    if(list[j].isEmpty == -1)
                    {
                            continue;
                    }
                    if(strcmp(list[i].lastName,list[j].lastName) >0)
                    {
                        auxList= list[j];
                        list[j] = list[i];
                        list[i] = auxList;
                    }
                 printf("\n Ordenados por apellido de la A a Z");
                 printEmployees(list,limite);
                }

                   for(j=i+1; j < limite; j++)
                {
                    if(list[j].isEmpty == -1)
                    {
                            continue;
                    }
                    if(list[i].sector>list[j].sector)
                    {
                        auxSector= list[j];
                        list[j] = list[i];
                        list[i] = auxSector;
                    }
                 printf("\n Ordenados por sector de menor a mayor");
                 printEmployees(list,limite);
                }
            }
            break;

            case 2:
                for(i=0; i < limite - 1; i++)
             {
                    if(list[i].isEmpty == -1)
                    {
                        continue;
                    }
                for(j=i+1; j < limite; j++)
                {
                    if(list[j].isEmpty == -1)
                    {
                            continue;
                    }
                    if(strcmp(list[i].lastName,list[j].lastName) <0)
                    {
                        auxList= list[j];
                        list[j] = list[i];
                        list[i] = auxList;
                    }
                 printf("\n Ordenados por apellido de la Z a A");
                 printEmployees(list,limite);
                }

                   for(j=i+1; j < limite; j++)
                {
                    if(list[j].isEmpty == -1)
                    {
                            continue;
                    }
                    if(list[i].sector<list[j].sector)
                    {
                        auxSector= list[j];
                        list[j] = list[i];
                        list[i] = auxSector;
                    }
                 printf("\n Ordenados por sector de mayor a menor");
                 printEmployees(list,limite);
                }
            }
            break;

            default:
                    printf("\nHa salido del ordenamiento\n");

       }
   }while(elegir!=3);
    return retorno;
}

int printEmployees(eEmployee* list, int limite)
{
    int retorno=-1;
    int i;
    if(list!=NULL && limite>=0)
    {
        for(i=0;i<limite;i++)
        {
            if(list[i].isEmpty == 1)
                continue;
            else if(list[i].isEmpty == 0)
            {
                printf("\n ID: %d\n Nombre: %s\n Apellido: %s\n Sueldo: %.2f\n Sector: %d\n",
                   list[i].id,list[i].name,list[i].lastName,list[i].salary, list[i].sector);
            }
        }
        retorno=0;
    }
    return retorno;
}

int promediosEmployees(eEmployee* list, int limite)
{
    float promedioSalario;
    float salarioTotal = 0;
    int contador = 0;
    int superoElPromedio = 0;//
    int i;
    int retorno = -1;

    if(list != NULL && limite >= 0)
    {
        for(i = 0; i < limite; i++)
        {
            if(list[i].isEmpty == 0)
            {
                contador++;
                salarioTotal = salarioTotal + list[i].salary;
            }

        }

        promedioSalario = salarioTotal / (float)contador;
        for(i = 0; i < limite; i++)
        {
            if(list[i].isEmpty == 0 && list[i].salary > promedioSalario)
            {
                superoElPromedio++;
            }
        }
        printf("\nTotal de salarios : %.2f\nPromedio de salarios : %.2f\n", salarioTotal, promedioSalario);
        printf("\nCantidad de empleados que superan el salario promedio : %d ", superoElPromedio);
        retorno = 0;
    }

    return retorno;
}

int informarEmploye(eEmployee list[], int limite)
{
    int opcion;
    int retorno = -1;
    if(list!=NULL && limite>=0)
    {
      do{
        utn_getUnsignedInt("Seleccione opcion: \n1 - Listar empleados \n2 - Promedios salarios \n3 -Salir  \n","\nError", 1, sizeof(int), 1, 3, 3, &opcion);

        switch(opcion)
        {
            case 1:
                if(sortEmployees(list, limite)==0)
                {
                    retorno= 0;
                }

                break;
            case 2:
                if(promediosEmployees(list, limite)==0)
                {
                    retorno = 0;
                }

                break;
            case 3:
                printf("\nHa salido de Informar\n");
                break;
            default:
                printf("\nOpcion no valida");
        }
      }while(opcion!=3);
    }
    return retorno;
}
