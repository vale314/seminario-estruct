#include <stdio.h>
#include <string.h>

#define TAM 300

typedef struct _inventario {
    char nombre[30], autor[35];
    char area[30], editorial[20];
    float precio;
    int anyo, cantidad;
    unsigned int id_libro;
}Inventario;

int capturar(Inventario inv[], int cont);
int eliminar(Inventario inv[], int c);
int buscar(Inventario inv[], int c, char n[], char a[]);
void mostrar(Inventario inv[], int c);
void modificar(Inventario inv[], int i);

main()
{
    Inventario inv[TAM];
    int cont = 0, index;
    char op;
    do{
        printf("\n\t\tPROGRAMA LIBRERIA\n\n");
        printf("MENU DE OPCIONES:\n"
                "1.- CAPTURAR\n"
                "2.- ELIMINAR\n"
                "3.- MOSTRAR\n"
                "4.- BUSCAR\n"
                "5.- MODIFICAR\n"
                "6.- SALIR\n"
                "ELIGE UNA OPCION:  ");
        scanf("%c",&op);
        switch(op)
        {
           case '1':if(cont >= TAM-1 )
                        printf("\n\nLA ESTRUCTURA ESTA LLENA,"
                               "IMPOSIBLE CAPTURAR...");
                    else
                        cont = capturar(inv,cont);
            break;
            case '2':printf("ESCRIBE EL NOMBRE DEL LIBRO:  ");
                fflush(stdin);
                gets(libro)
                printf("ESCRIBE EL NOMBRE DEL AUTOR:  ");
                fflush(stdin);
                gets(autor)
                if( index > 0)
                    cont = eliminar(inv, cont, index);
                else
                    printf("NO SE ENCUENTRA EL LIBRO:  ";)
            break;
            case '3':
            break;
            case '4':
            break;
            case '5':
            break;
            case '6':
            break;
        }
    }while(op != 6);
}

int capturar(Inventario inv[], int cont){
    inv[cont].id_libro = cont + 1;
    printf("ESCRIBE EL NOMBRE DEL LIBRO  ");
    gets(inv[cont].nombre);
    printf("ESCRIBE EL NOMBRE DEL AUTOR  ");
    gets(inv[cont].autor);
    printf("AREA O SUBAREA DEL LIBRO  ");
    gets(inv[cont].area);
    printf("EDITORIAL  ");
    gets(inv[cont].editorial);
    printf("CANTIDAD DE LIBROS  ");
    scanf("%d",&inv[cont].cantidad);
    printf("PRECIO  ");
    scanf("%f",&inv[cont].precio);
    printf("AÑO DE PUBLICACION  ");
    scanf("%d",&inv[cont].anyo);
    cont ++;
    return cont;
}
int eliminar(Inventario inv[], int c, int index){
    int i;
    for ( i = index; i < c; i++)
        inv[i] = inv[i+1];
    c --;

}
int buscar(Inventario inv[], int c, char n[], char a[]){}
void mostrar(Inventario inv[], int c){
}
void modificar(Inventario inv[], int i){}
