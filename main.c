#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
// -- Function Prototypes --

typedef struct Persona{
    char nombre[20];
    char telefono[9];
    char dni[20];
} Persona;

typedef struct Vino {   
    int   codigo;           
    char  nombre[20];
    char  marca[20];
    char  fecha_fabricacion[20];
    char  fecha_ingreso[20];
    int   tipo_vino; // 1: Tinto, 2: Blanco, 3: malbec
    float precio_bruto; //Precio sin impuesto
    float precio_venta; //Precio con impuesto (15%)
    Persona proveedor;
}Vino; 

typedef struct AlmacenVinos{
    Vino vinos[MAX];
    int cantidad_vinos;
} AlmacenVinos;

// -- Function Prototypes --
// get cantidad de vinos
int getCantidadVinos(AlmacenVinos almacen){
    return almacen.cantidad_vinos;
}
// Mostrar caracteristicas de un vino
void mostrarVino(Vino vino){
    printf("Codigo: %d\n", vino.codigo);
    printf("Nombre: %s\n", vino.nombre);
    printf("Marca:  %s\n", vino.marca);
    printf("Fecha de fabricacion: %s\n", vino.fecha_fabricacion);
    printf("Fecha de ingreso: %s\n", vino.fecha_ingreso);
    switch (vino.tipo_vino)
    {
        case 1:
            printf("Tipo de vino: Tinto\n");
            break;
        case 2:
            printf("Tipo de vino: Blanco\n");
            break;
        case 3:
            printf("Tipo de vino: Malbec\n");
            break;    
    }
    printf("Precio bruto: %.2f\n", vino.precio_bruto);
    printf("Precio de venta: %.2f\n", vino.precio_venta);
    printf("--Provedor\n" );
    printf("---Nombre:   %s\n", vino.proveedor.nombre);
    printf("---Telefono: %s\n", vino.proveedor.telefono);
    printf("---DNI: %s\n", vino.proveedor.dni);
}
// Mostrar todos los vinos del almacen
void mostrarVinosAlmacen(AlmacenVinos almacen){
    int i;
    for(i=0; i<almacen.cantidad_vinos; i++){
        printf( "----Vino numero %d\n", i+1);
        mostrarVino(almacen.vinos[i]);
    }
}


// -- Main --
int main () {

    AlmacenVinos AVinos;
    AVinos.cantidad_vinos=0;
    printf("--- Bienvenido al sistema de almacen de vinos ---\n");

    // Menu principal
    int opcion = 0;
    while (opcion != 10) {
        printf("1. Agregar producto\n");
        printf("2. Eliminar producto\n");
        printf("3. Buscar por provedor\n");
        printf("4. Busqueda por nombre por vino\n");
        printf("5. Modificar precio del producto\n");
        printf("6. Modificar fecha de ingreso de un vino \n");
        printf("7. Imprimir productos\n");
        printf("8. Imprimir telefono de un proveedor \n");
        printf("9. Total de productos\n");
        printf("10. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("-> Agregar producto\n");
                Vino new_vino;
                printf("Ingrese el codigo: ");
                scanf("%d", &new_vino.codigo);
                printf("Ingrese el nombre: ");
                scanf("%s", new_vino.nombre);
                printf("Ingrese la marca: ");
                scanf("%s", new_vino.marca);
                printf("Ingrese la fecha de fabricacion: (dia/mes/ano):  ");
                scanf("%s", new_vino.fecha_fabricacion);
                printf("Ingrese la fecha de ingreso: (mes/anio) ");
                scanf("%s", new_vino.fecha_ingreso);
                int tipo_vino = 0;
                while (tipo_vino < 1 || tipo_vino > 3) {
                    printf("Ingrese el tipo de vino \n[1]Tinto [2]Blanco [3]Malbec:  ");
                    scanf("%d", &tipo_vino);
                }
                new_vino.tipo_vino = tipo_vino;
                printf("Ingrese el precio bruto: ");
                scanf("%f", &new_vino.precio_bruto);
                new_vino.precio_venta = new_vino.precio_bruto * 1.15;
                Persona new_provedor;
                printf("Ingrese el nombre del proveedor: ");
                scanf("%s", new_provedor.nombre);
                printf("Ingrese el telefono del proveedor: ");
                scanf("%s", new_provedor.telefono);
                printf("Ingrese el dni del proveedor: ");
                scanf("%s", new_provedor.dni);
                new_vino.proveedor = new_provedor;
                AVinos.vinos[AVinos.cantidad_vinos] = new_vino;
                AVinos.cantidad_vinos++;
                printf( "Vino agregado correctamente\n\n");
                getch(); 

                break;
            case 2:
                printf("-- Eliminar producto\n");
                printf( "Ultimo vino eliminado correctamente (cod: %d)\n\n", AVinos.vinos[AVinos.cantidad_vinos].codigo);
                AVinos.cantidad_vinos--;
                getch(); 
                break;
            case 3:{
                printf("--Buscar vino por provedor\n");
                char nombre_proveedor[20];
                printf( "Ingrese el nombre del proveedor: ");
                scanf("%s", nombre_proveedor);
                int i;
                printf( "===== Vinos del proveedor %s:\n", nombre_proveedor);
                for(i=0; i<AVinos.cantidad_vinos; i++){
                    if(strcmp(AVinos.vinos[i].proveedor.nombre, nombre_proveedor) == 0){
                        mostrarVino(AVinos.vinos[i]);
                    }
                }
                getch(); 

                break;
                }
            case 4:
                printf("-- Busqueda por nombre de vino\n");
                char nombre_vino[20];
                printf( "Ingrese el nombre del vino: ");
                scanf("%s", nombre_vino);
                int j;
                printf( "===== Vinos con el nombre %s:\n", nombre_vino);
                for(j=0; j<AVinos.cantidad_vinos; j++){
                    if(strcmp(AVinos.vinos[j].nombre, nombre_vino) == 0){
                        mostrarVino(AVinos.vinos[j]);
                    }
                }
                getch();
                break;
            case 5:
                printf("-- Modificar precio del producto\n");
                int codigo_vino = 0;
                printf( "Ingrese el codigo del vino: ");
                scanf("%d", &codigo_vino);
                int k;
                for(k=0; k<AVinos.cantidad_vinos; k++){
                    if(AVinos.vinos[k].codigo == codigo_vino){
                        printf( "Ingrese el nuevo precio: ");
                        scanf("%f", &AVinos.vinos[k].precio_bruto);
                        AVinos.vinos[k].precio_venta = AVinos.vinos[k].precio_bruto * 1.15;
                        printf( "Precio modificado correctamente\n\n");
                    }
                }
                getch();
                break;
            case 6:
                printf("-- Modificar fecha de ingreso de un vino\n");
                int codigo_vino2 = 0;
                printf( "Ingrese el codigo del vino: ");
                scanf("%d", &codigo_vino2);
                int l;
                for(l=0; l<AVinos.cantidad_vinos; l++){
                    if(AVinos.vinos[l].codigo == codigo_vino2){
                        printf( "Ingrese la nueva fecha de ingreso: ");
                        scanf("%s", AVinos.vinos[l].fecha_ingreso);
                        printf( "Fecha de ingreso modificada correctamente\n\n");
                    }
                }
                getch();
                break;
            case 7:{
                printf("-- Imprimir productos\n");
                //  genera un archivo.txt con la información del producto(código)
                FILE *archivo;
                archivo = fopen("imprimir_productos.txt", "w");
                int m;
                for(m=0; m<AVinos.cantidad_vinos; m++){
                    fprintf(archivo, "Codigo: %d", AVinos.vinos[m].codigo);
                    fprintf(archivo, "Nombre: %s", AVinos.vinos[m].nombre);
                    fprintf(archivo, "Marca: %s", AVinos.vinos[m].marca);
                    fprintf(archivo, "Fecha de fabricacion: %s", AVinos.vinos[m].fecha_fabricacion);
                    fprintf(archivo, "Fecha de ingreso: %s", AVinos.vinos[m].fecha_ingreso);
                    fprintf(archivo, "Tipo de vino: %d", AVinos.vinos[m].tipo_vino);
                    fprintf(archivo, "Precio bruto: %.2f", AVinos.vinos[m].precio_bruto);
                    fprintf(archivo, "Precio de venta: %.2f", AVinos.vinos[m].precio_venta);
                    fprintf(archivo, "Proveedor: %s", AVinos.vinos[m].proveedor.nombre);
                    fprintf(archivo, "Telefono: %s", AVinos.vinos[m].proveedor.telefono);
                    fprintf(archivo, "DNI: %s", AVinos.vinos[m].proveedor.dni);
                }
                fclose(archivo);
                mostrarVinosAlmacen(AVinos);
                printf( "Archivo generado correctamente\n\n");
                printf( "Inserte alguna tecla para continuar . . . \n\n" );
                getch(); 
                break;
                }
            case 8:
                printf("-- Imprimir telefono de un proveedor\n");
                // genera un archivo.txt con los datos de un proveedor
                char nombre_proveedor2[20];
                printf( "Ingrese el nombre del proveedor: ");
                scanf("%s", nombre_proveedor2);
                int m;
                for(m=0; m<AVinos.cantidad_vinos; m++){
                    if(strcmp(AVinos.vinos[m].proveedor.nombre, nombre_proveedor2) == 0){
                        FILE *fichero;
                        fichero = fopen("proveedor.txt", "w");
                        fprintf(fichero, "Nombre: %s\n", AVinos.vinos[m].proveedor.nombre);
                        fprintf(fichero, "Telefono: %s\n", AVinos.vinos[m].proveedor.telefono);
                        fprintf(fichero, "DNI: %s\n", AVinos.vinos[m].proveedor.dni);
                        fclose(fichero);
                        printf( "Archivo generado correctamente\n\n");
                    }
                }
                getch();
                break;
            case 9:
                printf("-- Total de productos\n");
                // genera un archivo.txt con la info de todos los vinos y al final muestra la suma total de todos sus precios de venta al publico
                FILE *fichero;
                fichero = fopen("vinos.txt", "w");
                int n;
                float total = 0;
                for(n=0; n<AVinos.cantidad_vinos; n++){
                    fprintf(fichero, "Codigo: %d\n", AVinos.vinos[n].codigo);
                    fprintf(fichero, "Nombre: %s\n", AVinos.vinos[n].nombre);
                    fprintf(fichero, "Precio bruto: %.2f\n", AVinos.vinos[n].precio_bruto);
                    fprintf(fichero, "Precio venta: %.2f\n", AVinos.vinos[n].precio_venta);
                    fprintf(fichero, "Fecha ingreso: %s\n", AVinos.vinos[n].fecha_ingreso);
                    fprintf(fichero, "Proveedor: %s\n", AVinos.vinos[n].proveedor.nombre);
                    fprintf(fichero, "Telefono: %s\n", AVinos.vinos[n].proveedor.telefono);
                    fprintf(fichero, "DNI: %s\n", AVinos.vinos[n].proveedor.dni);
                    fprintf(fichero, "--------------------------------\n");
                    total += AVinos.vinos[n].precio_venta;
                }
                fprintf(fichero, "Total: %.2f\n", total);
                fclose(fichero);
                printf( "Archivo generado correctamente\n\n");
                getch();
                break;
            case 10:
                printf("-- Salir\n");
                break;
            default:
                printf("Opcion invalida\n");
                break;
        }
    }

    return 0;
}