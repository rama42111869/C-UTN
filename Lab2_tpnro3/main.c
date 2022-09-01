#include <stdio.h>
#include <stdlib.h>
void muestraArchivoInvertido2(FILE * arch);
int main()
{
    int n,a,b;
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    int arr2[10]={1,1,1,1,1,1,1,1,1,1};
    char archivo1[]={"elementos.bin"};
    char archivo2[]={"caracter.bin"};
    char archivo3[]={"caracter2.bin"};
    printf("elija uno de los 12 ejercicios\n");
    fflush(stdin);
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        printf("ingrese un nro para calcular su factorial:\t");
        fflush(stdin);
        scanf("%d",&a);
        b=factorial(a);
        printf("El factorial de: ");
        printf("%d",a);
        printf(" es %d ",b);
        break;
    case 2:
        printf("ingrese un nro para calcular su potencia:\t");
        fflush(stdin);
        scanf("%d",&a);
        b=potencia(a);
        printf("La potencia de: ");
        printf("%d",a);
        printf(" es %d ",b);
        break;
    case 3:
        mostrar(arr,0,10);
        break;
    case 4:
        mostrarinvertido(arr,10,0);
        break;
    case 5:
        mostrar(arr,0,10);
        b=capicua(arr,0,10);
        printf("Respuesta: 0 si es capicua, 1 si no es capicua\n");
        printf("\nRespuesta: %d",b);
        break;
    case 6:
        printf("\n");
        mostrarinvertido(arr,10,0);
        printf("\n");
        b=sumarecursiva(arr,10,0);
        printf("la suma de los elementos del arreglo es %d \n",b);
        break;
    case 7:
        b=buscamenorrecursivo(arr,10,0);
        printf("El menor es: %d \n",b);
        break;
    case 8:
        ///Cargar_Archivo(archivo1);
        break;
    case 9:
        MostrarInvertido(archivo1);
        break;
    case 10:
        Mostrar_Archivo(archivo1);
        MostrarInvertido(archivo1);
        printf("\n");
        break;
    case 11:
        Cargar_Archivo2(archivo3);
        Mostrar_Archivo2(archivo3);
        muestraArchivoInvertido(archivo3);
        break;
    case 12:
        b=buscaelementorecursivo(arr,10,0,6);
        printf("1 si se encuentra en el arreglo, 0 si no es asi %d\t",b);
        break;
    }
    return 0;
}


///1)Funcion con retorno para calcular el factorial de un número en forma recursiva.
int factorial(int x)
{
    int rta;
    if(x==0)
        rta=1;
    else
        rta=x*factorial(x-1);
    return rta;
}

///2)Funcion con retorno para calcular la potencia de un número en forma recursiva. .
int potencia(int x)
       {
    int rta;
    if(x==0)
        rta=1;
    else
        rta=x*x;
    return rta;
}


///3)Funcion para mostrar un arreglo de forma recursiva
void mostrar(int arr[],int i,int dim)
{
    if(i==dim-1)
    printf("[%d]",arr[i]);
    else
    {
    printf("[%d]",arr[i]);
    mostrar(arr,i+1,dim);
    }
}

///4)Funcion para mostrar un arreglo de forma recursiva e invertida
void mostrarinvertido(int arr[],int dim,int i)
{
    if(i==dim-1)
    printf("[%d]",arr[dim-1]);
    else
    {
    printf("[%d]",arr[dim-1]);
    mostrarinvertido(arr,dim-1,i);
    }
}


///5)Funcion para determinar si un arreglo es capicua de forma recursiva
int capicua(int a[], int i, int u){
    int rta=1;
    if(i=!-1){
        rta=0;
    }
    else
    {
        rta=capicua(a,i+1,u-1);
    }
    return rta;
}

///6)Funcion para sumar los elementos de un arreglo de forma recursiva
int sumarecursiva(int arr[],int val,int i)
{
    int rta;
    if(i==val)
    {
        rta=0;
    }
    else
    {
        rta=arr[i]+sumarecursiva(arr,val,i+1);
    }
    return rta;
}

///7)Funcion para buscar el menor
int buscamenorrecursivo(int arr[],int val,int i)
{
    int menor=arr[i];
    if(i<val-1)
    {
        buscamenorrecursivo(arr,val,i+1);
    }
    return menor;
}


///Funcion auxiliar para cargar un archivo
void Cargar_Archivo(char Nombre[])
{
    FILE * archi=NULL;
    int Numeros=0;
    char control='s';
    archi=fopen(Nombre, "wb");
    if(archi != NULL)
    {
        while (control!='n')
        {
            printf("Ingrese un numero: \t");
            scanf("%d",&Numeros);
            fwrite(&Numeros,sizeof(int),1,archi);
            printf("Desea ingresar otro numero?");
            fflush(stdin);
            scanf("%c",&control);
        }
        fclose(archi);
    }
}
///Funcion auxiliar para mostrar un archivo
void Mostrar_Archivo(char Nombre[])
{
    FILE * archi=NULL;
    int Numeros=0;
    archi=fopen(Nombre,"rb");
    if(archi != NULL)
    {
        printf("\nContenido del archivo: \n");
        while (fread(&Numeros,sizeof(int),1,archi)>0)
        {
            printf(" %d", Numeros);
        }
        fclose(archi);
    }
}

///9)Funcion para invertir los elementos del archivo
void muestraArchivoInvertido(FILE * arch)
{
    int numero;
    if(fread(&numero, sizeof(int), 1, arch)>0)
    {
        muestraArchivoInvertido(arch);
        printf("%d", numero);
    }

}
///10)Funcion principial para mostrar los elementos del archivo invertido
void MostrarInvertido(char nombre[])
{
    FILE *arch=NULL;
    arch=fopen(nombre, "rb");
    if(arch!=NULL)
    {
        printf("\n\nContenido del archivo invertido: ");
        muestraArchivoInvertido(arch);
        fclose(arch);
    }
    else
    {
        printf("\nError\n");
    }
}

///11) Funcion para ingresar valores a una variable de tipo char (por teclado) y mostrarlo en el orden inverso
/// (hasta ingresar un ‘*’) de forma recursiva.
void Cargar_Archivo2(char Nombre[])
{
    FILE * archi=NULL;
    char control2='s';
    char control[30];
    archi=fopen(Nombre, "wb");
    if(archi != NULL)
    {
        while (control2!='*')
        {
            printf("Ingrese un caracter: \t");
            scanf("%s",&control);
            fwrite(&control,sizeof(char),1,archi);
            printf("Desea ingresar otro caracter?");
            fflush(stdin);
            scanf("%c",&control2);
        }
        fclose(archi);
    }
}
///Funcion auxiliar para mostrar un archivo
void Mostrar_Archivo2(char Nombre[])
{
    FILE * archi=NULL;
    char control[30];
    archi=fopen(Nombre,"rb");
    if(archi != NULL)
    {
        printf("\nContenido del archivo: \n");
        while (fread(&control,sizeof(char),1,archi)>0)
        {
            printf(" %s", control);
        }
        fclose(archi);
    }
}

///Funcion para invertir los elementos del archivo
void muestraArchivoInvertido2(FILE * arch)
{
    char control[30];
    if(fread(&control, sizeof(char), 1, arch)>0)
    {
        muestraArchivoInvertido2(arch);
        printf("%s", control);
    }

}

///12)Funcion para determinar si un arreglo contiene dicho elemento
int buscaelementorecursivo(int arr[],int val,int i,int elemento)
{
    int flag=0;
    int menor=arr[i];
    while(i<val-1 && flag==0)
    {
        if(elemento==arr[i])
        {
            flag=1;
        }
        else
        {
            i++;
            buscaelementorecursivo(arr,val,i+1,elemento);
        }

    }
    return flag;
}
