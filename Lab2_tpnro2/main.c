#include <stdio.h>
#include <stdlib.h>
#define TAM 30

typedef struct
{
    char nombre[30];
    char genero;
    int edad;
} persona;

///1b)Funcion para contar por generos
int cuentaGenero(persona p[], int vP, char g);
///1b)Funciones para trabajar con malloc
int pasaGeneroMalloc2(persona p[], int vPersona, persona **g, char genero);
persona* pasaGeneroMalloc(persona p[], int vPersona, persona *g, int *vGenero, char genero);

///3 y 4)Pilas
typedef struct
{
    int valores[100];
    int posTope;
} Pila;

void apilar(Pila * p, int valor);
int desapilar(Pila * p);
int tope(Pila * p);
int pilavacia(Pila * p);
void mostrar(Pila * p);
void leer (Pila * p);
void inicPila(Pila * p);


///funcion del ejercicio 7
void EliminarElemento(int arr[TAM], int *cantidad, int elem);


typedef struct
{
    int matricula;
    char nombre[30];
} Alumno;
typedef struct
{
    int codigo;
    char nombreMat[20];
} Materia ;
typedef struct
{
    int matricula;
    int codigo;
    int nota;
} Nota;

///8c1)Funcion para validar la existencia de la materia
int validarmateria(Materia m[],int codigo,int dim,char materia);

int main()
{
    int n,a,b,c,e;
    char control;
    persona p[100];
    persona d;

    int vPersona=0;
    persona genero[30];
    int vGenero=0;
    persona *g=NULL;
    int vG=0;

    Pila x,y,z;

    int arr[10]= {1,2,3,4,5,6,7,8,9,10};
    int cantidad=9;
    Alumno alus[20]; // para almacenar los datos de los 20 alumnos.
    Materia mats[5]; // para almacenar los códigos y nombres de las 5 materias.
    Nota notas[100]; // para almacenar todas las notas de los alumnos.
    Materia m;
    printf("Elija uno de los 8 ejercicios\n");
    fflush(stdin);
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        printf("ingrese la cantidad de personas que desea ingresar\n");
        fflush(stdin);
        scanf("%d",&b);
        c=cargarestructura(p,b);
        printf("ingrese el genero que desea contar\n");
        fflush(stdin);
        scanf("%c",&control);
        a=cuentaGenero(p,b,control);
        printf("\ncantidad de personas con ese genero");
        printf("\t%d\n",a);
        e= pasaGeneroMalloc2(p, vPersona, &g, control);
        mostrarArr(p,b);
        break;
    case 2:
        printf("ingrese la cantidad de personas que desea ingresar\n");
        fflush(stdin);
        scanf("%d",&b);
        a=cargarestructura(p,b);
        mostrarestructura(p,b);
        system("pause");
        ordenaseleccionn(p,b);
        mostrarestructura(p,b);
        break;
    case 3:
        inicPila(&x);
        leer(&x);
        mostrar(&x);
        system("pause");
        apilar(&x,7);
        mostrar(&x);
        system("pause");
        desapilar(&x);
        mostrar(&x);
        break;
    case 4:
        printf("Pila 1\n");
        inicPila(&x);
        inicPila(&y);
        inicPila(&z);
        apilar(&x,1);
        apilar(&x,2);
        apilar(&x,3);
        apilar(&y,4);
        apilar(&y,5);
        apilar(&y,6);
        mostrar(&x);
        mostrar(&y);
        system("\npause\n");
        pasardepilaapila(x,y,&z);
        mostrar(&z);
        break;
    case 5:
        printf("ingrese la cantidad de personas que desea ingresar\n");
        fflush(stdin);
        scanf("%d",&b);
        a=cargarestructura(p,b);
        insertaRegistroOrdenado(p,b,d);
        break;
    case 6:
        printf("ingrese la cantidad de personas que desea ingresar\n");
        fflush(stdin);
        scanf("%d",&b);
        a=cargarestructura(p,b);
        mostrarestructura(p,b);
        system("pause");
        ordenainsercion(p,b);
        mostrarestructura(p,b);
        break;
    case 7:
        mostrararreglo(arr,10);
        printf("ingrese el elemento que quiere eliminar\n");
        fflush(stdin);
        scanf("%d",&b);
        EliminarElemento(arr,&cantidad,b);
        system("pause");
        mostrararreglo(arr,10);
        break;
    case 8:
        printf("\n\ningrese la cantidad de materias que desea agregar\n");
        fflush(stdin);
        scanf("%d",&b);
        cargarmaterias(mats,b);
        agregarunalumno(alus,1);
        printf("\n\ningrese el codigo de la materia\n");
        fflush(stdin);
        scanf("%d",&c);
        printf("\n\ningrese el nombre de la materia\n");
        fflush(stdin);
        scanf("%s",&m.nombreMat);
//        e=validarmateria(mats,c,b,m);
        agregarnota(e,mats,b);
        break;
    }
    return 0;
}

///1a)Funcion para cargar estructuras
int cargarestructura(persona arr[30],int dim)
{
    int val=0;
    for(int i=0; i<dim; i++)
    {
        printf("ingrese un nombre: \t");
        fflush(stdin);
        scanf("%s",&arr[i].nombre);
        printf("ingrese el genero M(hombre)/F(mujer): \t");
        fflush(stdin);
        scanf("%c",&arr[i].genero);
        printf("ingrese la edad: \t");
        fflush(stdin);
        scanf("%d",&arr[i].edad);
        val++;
    }
    return val;
}

///1b)Contar por genero
int cuentaGenero(persona p[], int vP, char g)
{
    int cont=0;
    for(int i=0; i<vP; i++ )
    {
        if(p[i].genero == g)
        {
            cont++;
        }
    }
    return cont;
}
///1c1)Funcion auxiliar para pasar personas de un arreglo a otro usando malloc y punteros
persona* pasaGeneroMalloc(persona p[], int vPersona, persona *g, int *vGenero, char genero)
{
    *vGenero = cuentaGenero(p, vPersona, genero);
    g = malloc(sizeof(persona)*(*vGenero));

    int i=0;
    int j=0;
    while(i < vPersona)
    {
        if(p[i].genero == genero)
        {
            g[j] = p[i];
            j++;
        }
        i++;
    }

    return g;
}
///1c2)Funcion principal para pasar personas de un arreglo a otro usando malloc y punteros
int pasaGeneroMalloc2(persona p[], int vPersona, persona **g, char genero)
{
    int vGenero = cuentaGenero(p, vPersona, genero);
    (*g) = (persona*) malloc(sizeof(persona) * vGenero);
    int i=0;
    int j=0;
    while(i < vPersona)
    {
        if(p[i].genero == genero)
        {
            (*g)[j] = p[i];
            j++;
        }
        i++;
    }
    return vGenero;
}
///Funcion para mostrar un arreglo de personas de un genero determinado
void mostrarArr(persona a[], int validos)
{
    char gene[10];
    int i = 0;
    while(i<validos)
    {
        muestrapersona(a[i]);
        i++;
    }
}
///Funcion para mostrar un genero determinado
void muestrapersona(persona a)
{
    char gene[10];
    if(a.genero == 'M')
    {
        strcpy(gene, "Hombre");
    }
    else
    {
        strcpy(gene, "Mujer");
    }

    puts("\n--------------------------------\n");
    printf("\nNOMBRE.......: %s", a.nombre);
    printf("\nGENERO.......: %s", gene);
    printf("\nEDAD.........: %d", a.edad);
    puts("\n--------------------------------\n");
}



///Funcion para mostrar un arreglo de persona completo
void mostrarestructura(persona arr[],int val)
{
    int i=0;
    while(i<val)
    {
        puts("--------------------------------------------------");
        printf("\nEdad: %d\t",arr[i].edad);
        printf("\nNombre: %s\t",arr[i].nombre);
        printf("\nGenero: %c\t",arr[i].genero);
        i++;
        puts("--------------------------------------------------");
    }
}


///2a) Ordenamiento por seleccion en estructuras: Busqueda del menor
int buscarmenor(persona arr[],int pos,int val)
{
    int i=pos+1;
    int posmenor=pos;
    int menor=arr[pos].edad;
    while(i<val)
    {
        if(menor>arr[i].edad)
        {
            menor=arr[i].edad;
            posmenor=i;
        }
        i++;
    }
    return posmenor;
}

///2b: Ordenamiento por seleccion
void ordenaseleccionn(persona arr[],int val)
{
    persona aux;
    int posmenor;
    int i=0;
    while(i<val)
    {
        posmenor=buscarmenor(arr,i,val);
        aux=arr[posmenor];
        arr[posmenor]=arr[i];
        arr[i]=aux;
        i++;
    }
}

///3a)Inicializacion de la pila
void inicPila(Pila *p)
{
    int *aux;
    aux=(int *)malloc(50*sizeof(int));
    *p->valores=aux;
    p->posTope=0;
}
///3b)Apilacion de la pila
void apilar(Pila *p,int valor)
{
    int index = (*p).posTope;
    (*p).valores[index]=valor;
    (*p).posTope = (*p).posTope + 1;
}
///3c)Desapilacion de la pila
int desapilar(Pila *p)
{
    int z = p->valores[p->posTope -1];
    p->posTope--;
    return z;
}
///3d)Tope de la pila
int tope(Pila *p)
{
    return p->valores[p->posTope - 1];
}
///3e)Comprueba si la pila esta vacia
int pilavacia(Pila *p)
{
    return (p->posTope == 0) ? 1 : 0;
}
///3f)Agregar un valor entero a la pila
void leer(Pila *p)
{
    int aux = 0;
    if (p->posTope < 50)
    {
        printf("Ingrese un valor entero: ");
        fflush(stdin);
        scanf("%d", &aux);
        apilar(p,aux);
    }
    else
        printf("Error: la pila esta llena");
}
///3g)Funcion para mostrar el contenido de la pila
void mostrar(Pila *p)
{
    int i;
    printf("\nBase .............................................. Tope\n\n");
    for(i=0; i < p->posTope; i++)
        printf("| %d ", p->valores[i]);
    printf("\n\nBase .............................................. Tope\n\n");
}

///4a)funcion para buscar el mayor elemento en una pila
int buscarmenorpila(Pila *dada)
{
    Pila aux;
    int menor;
    inicPila(&aux);
    menor=desapilar(dada);
    while(!pilavacia(dada))
    {
        if(menor>tope(dada))
        {
            apilar(&aux,menor);
            menor=desapilar(dada);
        }
        else
        {
            apilar(&aux,desapilar(dada));
        }
    }
    while(!pilavacia(&aux))
    {
        apilar(dada,desapilar(&aux));
    }
    return menor;
}

///4b)Funcion para pasar los elementos de 2 pilas distintas a una 3er pila y que queden ordenados
void pasardepilaapila(Pila origen1,Pila origen2,Pila *destino)
{
    while(!pilavacia(&origen1))
    {
        apilar(destino,buscarmenorpila(&origen1));
    }
    while(!pilavacia(&origen2))
    {
        apilar(destino,buscarmenorpila(&origen2));
    }
}

///5) Función insertar en orden en un arreglo
void insertaRegistroOrdenado(persona A[], int val, persona N)
{
    int i=val;
    while(i>=0 && A[i].edad>N.edad)
    {
        A[i+1]=A[i];
        i--;
    }
    A[i+1]=N;
}


///6) Algoritmo de ordenamiento por inserción
void ordenainsercion(persona arr[], int val)
{
    int u=0;
    while(u<val-1)
    {
        insertaRegistroOrdenado(arr,u,arr[u+1]);
        u++;
    }
}

///7)Funcion para eliminar un elemento de un arreglo
void EliminarElemento(int arr[TAM], int *cantidad, int elem)
{
    int i;
    for(i=elem; i<*cantidad-1; i++)
    {
        arr[i]= arr[i+1];
    }
    *cantidad-=1;
}

///funcion para mostrar un arreglo
void mostrararreglo(int arr[],int dim)
{
    for(int i=0; i<dim; i++)
    {
        printf("[%d]",arr[i]);
    }
}


///8a)Funcion para cargar materias
int cargarmaterias(Materia arr[30],int dim)
{
    int val=0;
    for(int i=0; i<dim; i++)
    {
        printf("ingrese el nombre de la materia: \t");
        fflush(stdin);
        scanf("%s",&arr[i].nombreMat);
        printf("ingrese el codigo de la materia: \t");
        fflush(stdin);
        scanf("%d",&arr[i].codigo);
        val++;
    }
    return val;
}
///8b)Funcion para agregar un Alumno
int agregarunalumno(Alumno a[],int dim)
{
    int val=0;
    for(int i=0; i<dim; i++)
    {
        printf("ingrese el nombre del alumno: \t");
        fflush(stdin);
        scanf("%s",&a[i].nombre);
        printf("ingrese la matricula del alumno: \t");
        fflush(stdin);
        scanf("%d",&a[i].matricula);
        val++;
    }
    return val;
}

///8c1)Funcion para validar la existencia de la materia
int validarmateria(Materia m[],int codigo,int dim,char materia)
{
    int flag=0;
    int i=0;
    while(i<dim && flag==0)
    {
        if(codigo==m[i].codigo && materia==m[i].nombreMat)
        {
            flag=1;
        }
        i++;
    }
    return flag;
}

///8c2)Funcion para agregar las notas
void agregarnota(int x,Materia a[],int dim)
{
    for(int i=0; i<dim; i++)
    {
        Nota a;
        if(x==0)
        {
            printf("ingrese la nota: \t");
            fflush(stdin);
            scanf("%d",&a[i].nota);
            printf("ingrese la matricula: \t");
            fflush(stdin);
            scanf("%d",&a[i].matricula);
            printf("ingrese el codigo: \t");
            fflush(stdin);
            scanf("%d",&a[i].codigo);
        }
        else
        {
            printf("\nError, no se puede agregar la nota\n");
        }

    }
}

///8d)Funcion para mostrar al Alumno
void mostraralumno(Alumno arr[],int dim,Materia arr2[],Nota arr3[])
{
    for(int i=0; i<dim; i++)
    {
        printf("%s",arr[i].nombre);
        printf("%d",arr[i].matricula);
        printf("%s",arr2[i].nombreMat);
        printf("%d",arr2[i].codigo);
        printf("%d",arr3[i].nota);
    }
}
