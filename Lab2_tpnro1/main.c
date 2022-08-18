#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    int n,a,b,c,d,e;
    int arr[10]= {0,1,2,3,4,5,6,7,8,9};
    int arr2[10];
    char arr3[10];
    int arr4[10]= {11,12,13,14,15,16,17,18,19,20};
    char arr5[10]= {'a','b','c','d','e','f','g','h','i','j'};
    char arr6[][30]= {"Gonzalez","Solis","Parrilla","Paredes","Basso","Marques","Lopez","Santana","Bullock","Hammer"};
    int edades[10]= {18,28,19,20,21,23,22,24,25,26};
    int mat[12][31];
    printf("Elija 1 de los ejercicios\n");
    fflush(stdin);
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        printf("ingrese la cantidad que piensa ingresar\n");
        fflush(stdin);
        scanf("%d",&a);
        inic(arr2,a);
        b=cargararr(arr2,a);
        c=sumarr(arr2,a);
        printf("suma de los elementos %d\n",c);
        d=contarrr(arr2,a);
        printf("cantidad de elementos %d\n",d);
        e=prom(c,d);
        printf("promedio de los elementos %d\n",e);
        break;
    case 2:
        printf("ingrese la cantidad deseada\n");
        fflush(stdin);
        scanf("%d",&a);
        b=cargararrch(arr3,a);
        inversion(arr3,a);
        mostrarchar(arr3,a);
        break;
    case 3:
        mostrararr(arr,10);
        printf("\n");
        decimal(arr,10);
        break;
    case 4:
        mostrararr(arr,10);
        printf("\n");
        c=retornamaximo(arr,0,10);
        printf("maximo elemento %d\n",c);
        break;
    case 5:
        b=matriz(mat);
        printf("\n\nCalendario\n\n");
        mostrarmatriz(mat);
        printf("ingrese el nro de mes\n");
        fflush(stdin);
        scanf("%d",&a);
        printf("ingrese el nro de dia\n");
        fflush(stdin);
        scanf("%d",&d);
        c=buscarelemento(mat,a,d);
        printf("\n");
        if(c==0)
        {
            printf("sin precipitaciones\n");
        }
        cargarprecipitaciones(arr2,c);
        mostrararr(arr2,c);
        break;
    case 6:
        mostrararrch(arr5,10);
        printf("\n");
        b=capicua(arr5,10);
        printf("\n0)capicua\n1)no capicua\n");
        printf("%d\n",b);
        break;
    case 7:
        printf("ingrese un nro\n");
        fflush(stdin);
        scanf("%d",&b);
        printf("ingrese otro nro\n");
        fflush(stdin);
        scanf("%d",&c);
        printf("\ncambiando valores...\n");
        system("\npause\n");
        cambiar(b,c);
        break;
    case 8:
        absorber(arr4,arr,arr2,10,10);
        mostrararr(arr2,20);
        system("\npause");
        printf("\n");
        ordenainsercion(arr2,20);
        mostrararr(arr2,20);
        break;
    case 9:
       e= buscarmayoredad(arr6,edades,0,10);
       printf("La persona de mayor edad se encuentra en la posicion %d",e);
        break;
    case 10:
        arrs(arr,10,c,a,b);
        break;
    }
    return 0;
}

///1a)inicializar el arreglo desde menos -1
void inic(int arr[],int dim)
{
    for(int i=0; i<dim; i++)
    {
        arr[i]=-1;
    }
}

///1b)cargar arreglo
int cargararr(int arr[],int dim)
{
    int num,val=0,i=0;
    while(i<dim)
    {
        printf("ingrese un nro entero\t");
        fflush(stdin);
        scanf("%d",&num);
        arr[i]=num;
        i++;
        val++;
    }
    return val;
}

///1c)sumar arreglo
int sumarr(int arr[],int dim)
{
    int suma=0;
    for(int i=0; i<dim; i++)
    {
        suma+=arr[i];
    }
    return suma;
}

///1d)contarelementos
int contarrr(int arr[],int validos)
{
    int i=0;
    while(i<validos)
    {
        i++;
    }
    return i;
}

///1e)calcular promedio
int prom(int a,int b)
{
    int prom=a/b;
    return prom;
}

///2a)cargar arreglo con caracteres
int cargararrch(char arr[],int dim)
{
    char caracter,val=0,i=0;
    while(i<dim)
    {
        printf("ingrese un caracter\t");
        fflush(stdin);
        scanf("%c",&caracter);
        arr[i]=caracter;
        i++;
        val++;
    }
    return val;
}

///2b)invertir elementos del arreglo
void inversion(char arr[], int val)
{
    int i=0;
    int aux;
    int ultimo=val-1;
    while(i<ultimo)
    {
        aux=arr[ultimo];
        arr[ultimo]=arr[i];
        arr[i]=aux;
        i++;
        ultimo--;
    }
}

///2c)mostrar arreglo de caracteres
void mostrarchar(char arr[],int dim)
{
    for(int i=0; i<dim; i++)
    {
        printf("[%c]\t",arr[i]);
    }
}

///3)Decimales
void decimal(int arr[],int dim)
{
    for(int i=0; i<dim; i++)
    {
        printf("%d",arr[i]);
    }
}
///Funcion para mostrar el arreglo
void mostrararr(int arr[],int val)
{
    for(int i=0; i<val; i++)
    {
        printf("[%d]",arr[i]);
    }
}

///4)retorne la posición del valor máximo de un arreglo de números enteros.
int retornamaximo(int arr[],int pos,int val)
{
    int menor=arr[pos];
    int posmenor=pos;
    int index=pos+1;
    while(index<val)
    {
        if(menor<arr[index])
        {
            menor=arr[index];
            posmenor=index;
        }
        index++;
    }
    return menor;
}

///5a)Cargar matriz
int matriz(int mat[12][31])
{
    int val=0,a=1;
    for(int i=0; i<12; i++)
    {
        if(i==0 || i==2 || i==4 || i==6 || i==7 || i==9 || i==11)
        {
            for(int j=0; j<31; j++)
            {
                mat[i][j]=j+1;
                val++;
            }
        }
        else if(i==1)
        {
            for(int j=0; j<29; j++)
            {
                mat[i][j]=j+1;
                val++;
            }
        }
        else if(i==3 || i==5 || i==8 || i==10)
        {
            for(int j=0; j<30; j++)
            {
                mat[i][j]=j+1;
                val++;
            }
        }
    }
    return val;
}

///funcion para mostrar la matriz
void mostrarmatriz(int mat[12][31])
{
    for(int i=0; i<12; i++)
    {
        printf("nro de mes %d\n",i+1);
        for(int j=0; j<31; j++)
        {
            printf("[%d]\t",mat[i][j]);
        }
        printf("\n");
    }
}
///5b)Función para retornar el día de máxima precipitación para un mes determinado
int buscarelemento(int mat[][31],int val1,int val2)
{
    int i=0,j=0;
    int flag=0;
    while(i<val1 && j<31 && flag==0)
    {
        if(val2==mat[i][j])
        {
            flag=1;
        printf("Dia con precipitacion maxima: %d",mat[i][j]);
        }
        else
        {
            i++;
            j++;
        }
    }
    return flag;
}

///5c)Función para cargar en un arreglo de 12 posiciones el resultado de aplicar la funcion anterior.
int cargarprecipitaciones(int mat[],int dato)
{
    int val=0,i=0;
    while(i<12)
    {
        mat[i]=dato;
        i++;
        val++;
    }
    return val;
}

///6)Determinar si un arreglo es capicuo o palindromo
int capicua(char arr[],int val)
{
    int i=0;
    int ul=val-1;
    int flag=1;
    while(i<ul && flag==1)
    {
        if(arr[ul]!=arr[i]){
            flag=0;
        }
            i++;
            ul--;
    }
    return flag;
}


///7)Intercambio de variables
void cambiar(int a,int b,int c)
{
    printf("\nvalor de A %d\t",a);
    printf("\nvalor de B %d\t",b);
    int aux=a;
    a=b;
    b=aux;
    printf("\nnuevo valor de A %d\t",a);
    printf("\nuevo valor de B %d\t",b);
}

///8)Combinacion de arreglos
void absorber(int arr[],int arr2[],int arr3[],int val1,int val2)
{
    int j=0;
    for(int i=0; i<val1; i++)
    {
        arr3[j]=arr[i];
        j++;
    }
    for(int k=0; k<val2; k++)
    {
        arr3[j]=arr2[k];
        j++;
    }
}
///Ordenamiento por insercion
void insertar(int arr[],int u, int dato)
{
    int i=u;
    while(i>=0 && dato<arr[i])
    {
        arr[i+1]=arr[i];
        i--;
    }
    arr[i+1]=dato;
}
void ordenainsercion(int arr[],int c)
{
    int u=0;
    while(u<c-1)
    {
        insertar(arr,u,arr[u+1]);
        u++;
    }
}

///9)arreglos paralelos
///   char arr6[][30]= {"Gonzalez","Solis","Parrilla","Paredes","Basso","Marques","Lopez","Santana","Bullock","Hammer"};
///   int edades[10]= {18,28,19,20,21,23,22,24,25,26};
int buscarmayoredad(char apellido[][30],int edad[],int pos,int dim)
{
    int mayor=edad[pos];
    int posmayor=pos;
    int index=pos+1;
    while(index<dim)
    {
        if(mayor<edad[index])
        {
            mayor=edad[index];
            posmayor=index;
        }
        index++;
    }
    return posmayor;
}

///10)Pasaje de parámetros por referencia
void arrs(int arr[],int dim)
{
    int a,b,c,d;
    for(int i=0; i<dim; i++)
    {
        printf("[%d]",arr[i]);
    }
    a=retornaminimo(arr,0,dim);
    b=retornamaximo(arr,0,dim);
    c=sumarr(arr,dim);
    d=prom(c,dim);
    printf("%\nRetornar minimo %d\n",a);
    printf("\nRetornar maximo %d\n",b);
    printf("\nPromedio %d\n",d);
}

///funcion para retornar el minimo
int retornaminimo(int arr[],int pos,int val)
{
    int minimo=arr[pos];
    int posminimo=pos;
    int index=pos+1;
    while(index<val)
    {
        if(minimo>arr[index])
        {
            minimo=arr[index];
            posminimo=index;
        }
        index++;
    }
    return minimo;
}

///funcion para mostrar un arreglo de palabras
void mostrararrch(char arr[],int val)
{
    for(int i=0; i<val; i++)
    {
        printf("[%c]",arr[i]);
    }
}
