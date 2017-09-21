#define tam 20
/** \brief definicion de la estructura persona
 */
typedef struct per
{
    char nombre[50];
    int edad;
    int dni;
    int estado;
}epersona;
epersona persona,vectordepersonas[tam],vectordepersonasauxiliar[tam],personaauxiliar;
/** \brief Funcion encargada de mostrar el menu por pantalla y pedir un valor al usuario
 *
 * \param void
 * \return int opc devuelve un valor de tipo entero
 *
 */
int menu(void)
{
    int opcion;
        fflush(stdin);
        system("cls");
        printf("Trabajo Practico 2\n\n");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");
        scanf("%d",&opcion);
        fflush(stdin);
        return opcion;
}
/** \brief Inicializa los vectores de forma logica
 *
 * \param vec[tam] epersona-vector de personas
 * \param vecaux[tam] epersona- vector auxiliar de personas
 * \return void
 *
 */
void inicializarvectores(epersona vectordepersonas[tam],epersona vectordepersonasauxiliar[tam])
{
    int i;
    for(i=0;i<tam;i++)
    {
        vectordepersonas[i].estado=0;
        vectordepersonasauxiliar[i].estado=0;
    }
}
/** \brief Se piden por pantalla al usuario los datos de la nueva persona, antes de eso se verifica si hay lugar en el vector,
se verifica si el dni ya estaba ingresado. Si el vector tiene lugar y el dni no esta repetido, se guarda a la persona en el vector
 *
 * \param vec[tam] epersona- vector de personas
 * \return void si el vector esta lleno, devuelve un mensaje de error, si el dni est repetido devuelve otro mensaje de error.
 *
 */
void cargarpersona(epersona vectordepersonas[tam])
{
    int flag=0,i,j;
    epersona persona;
    for(i=0;i<tam;i++)
    {
        if(vectordepersonas[i].estado==0)
        {
            fflush(stdin);
            printf("Ingresar nombre de persona:  ");
            gets(persona.nombre);
            printf("Ingresar DNI:  ");
            scanf("%d",&persona.dni);
            while((persona.dni<1000000)||(persona.dni>99999999))
            {
                printf("DNI invalido, ingresar de nuevo");
                system("cls");
                printf("Ingresar DNI:  ");
                scanf("%d",&persona.dni);
            }
            printf("Ingresar edad:  ");
            scanf("%d",&persona.edad);
            while((persona.edad<1)||(persona.edad>200))
            {
                printf("Edad invalida, ingresar de nuevo");
                system("cls");
                printf("Ingresar edad:  ");
                scanf("%d",&persona.edad);
            }
            fflush(stdin);
            for(j=0;j<tam;j++)
            {
                if(vectordepersonas[j].dni==persona.dni)
                {
                    printf("DNI repetido, ingreso cancelado\n");
                    system("pause");
                    break;
                }
                else
                {
                    persona.estado=1;
                    vectordepersonas[i]=persona;
                    flag==1;
                    break;
                }
            }
            break;
        }
    }
    if((i==tam && flag==0))
    {
        printf("No hay espacio en el vector para ingresar a una nueva persona\n");
        system("pause");
    }
    fflush(stdin);
}
/** \brief pide por pantalla al usuario el numero de dni de la persona a eliminar, si el dni coincide con alguna persona del
vector, la elimina de manera logica.
 *
 * \param vec[tam] epersona-vector de personas
 * \return void si el dni no coincide con ningun dni dentro del vector, devuelve un mensaje de error.
 *
 */
void eliminarpersona(epersona vectordepersonas[tam])
{
    system("cls");
    int i,acumulador,flag=0,numerodni;
    printf("Ingrese el DNI de la persona a eliminar: ");
    scanf("%d", &numerodni);
    fflush(stdin);
    for(i=0;i<tam;i++)
    {
        if(vectordepersonas[i].dni==numerodni)
        {
            vectordepersonas[i].estado=0;
            flag=1;
            printf("Persona eliminada del vector\n\n");
            system("pause");
            break;
        }
    }
    if((i==tam) && (flag==0))
    {
        printf("El dni ingresado no corresponde a nadie en el vector\n\n");
        system("pause");
    }
    fflush(stdin);
}
/** \brief Recibe 2 vectores, el original y uno auxiliar, se copian todos los valores del vector de personas original que esten
dados de alta logica y los copia al vector auxiliar. En el vector auxiliar se realiza el ordenamiento y finalmente se muestra
por pantalla una lista ordenada.
 *
 * \param vec[tam] epersona-vector de personas
 * \param vecaux[tam] epersona-vector de personas original
 * \return void
 *
 */
void imprimirlistaordenada(epersona vectordepersonas[tam],epersona vectordepersonasauxiliar[tam])
{
    int i,j=0;
    epersona personaauxiliar;
    for(i=0;i<tam;i++)
    {
        vectordepersonasauxiliar[i].estado=0;
    }
    for(i=0;i<tam;i++)
    {
        if(vectordepersonas[i].estado==1)
        {
            while(vectordepersonasauxiliar[j].estado!=0)
            {
                j++;
            }
            vectordepersonasauxiliar[j]=vectordepersonas[i];
        }
    }
    for(i=1;i<tam;i++)
    {
        for(j=0;j<tam-1;j++)
        {
            if(stricmp(vectordepersonasauxiliar[j].nombre,vectordepersonasauxiliar[j+1].nombre)==1)
            {
                personaauxiliar=vectordepersonasauxiliar[j+1];
                vectordepersonasauxiliar[j+1]=vectordepersonasauxiliar[j];
                vectordepersonasauxiliar[j]=personaauxiliar;
            }
        }
    }
    system("cls");
    for(i=0;i<tam;i++)
    {
        if(vectordepersonasauxiliar[i].estado==1)
        {
            printf("Nombre: %s DNI: %d Edad: %d",vectordepersonasauxiliar[i].nombre,vectordepersonasauxiliar[i].dni,vectordepersonasauxiliar[i].edad);
            printf("\n");
        }
    }
    system("pause");
    fflush(stdin);
}
/** \brief Recibe el vector de personas, luego se calcula la cantidad de personas que esten entre las edades solicitadas.
Se calcula el maximo entre las 3 variables de edades. Se realiza un bucle hasta que la variable de mayor valor sea 0, con el
fin de comparar con las demas e ir imprimiedo asteriscos segun corresponda.
 *
 * \param vec[tam] epersona-vector de personas
 * \return void
 *
 */
void imprimirgrafico(epersona vectordepersonas[tam])
{
    int i,menora19=0,entre19y35=0,mayorde35=0,max;
    for(i=0;i<tam;i++)
    {
        if(vectordepersonas[i].estado!=0)
        {
            if(vectordepersonas[i].edad<19)
            {
                menora19++;
            }
            else
            {
                if((vectordepersonas[i].edad>=19) && (vectordepersonas[i].edad<35))
                {
                    entre19y35++;
                }
                else
                {
                    mayorde35++;
                }
            }
        }
    }
    if((menora19>=entre19y35) && (menora19>=mayorde35))
    {
        max=menora19;
    }
    else
    {
        if((entre19y35>=menora19)&&(entre19y35>=mayorde35))
        {
            max=entre19y35;
        }
        else
        {
            max=mayorde35;
        }
    }
    system("cls");
    for(i=max;i>0;i--)
    {
        if((i==menora19)&&(i==entre19y35)&&(i==mayorde35))
        {
            printf(" *     *     *\n");
            menora19--;
            entre19y35--;
            mayorde35--;
        }
        else
        {
            if((i==menora19)&&(i==mayorde35))
            {
                printf(" *           *\n");
                menora19--;
                mayorde35--;
            }
            if((i==entre19y35)&&(i==mayorde35))
            {
                printf("       *     *\n");
                entre19y35--;
                mayorde35--;
            }
            if((i==menora19)&&(i==entre19y35))
            {
                printf(" *      *     \n");
                menora19--;
                entre19y35--;
            }
            else
            {
                if(i==menora19)
                {
                    printf(" *           \n");
                    menora19--;
                }
                else
                {
                    if(i==entre19y35)
                    {
                        printf("       *     \n");
                        entre19y35--;
                    }
                    else
                    {
                        if(i==mayorde35)
                        {
                            printf("             *\n");
                            mayorde35--;
                        }
                    }
                }
            }
        }
    }
    printf("19<  19-35  <35\n");
    system("pause");
    fflush(stdin);
}
