#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
struct compu {
    int velocidad; // Velocidad de procesamiento en GHz (valor entre 1 y 3)
    int anio; // Año de fabricación (valor entre 2015 y 2024)
    int cantidad_nucleos; // Cantidad de núcleos (valor entre 1 y 8)
    char *tipo_cpu; // Tipo de procesador (apuntador a cadena de caracteres)
   }typedef compu;


   void listarPCs( compu* pcs, int cantidad);
   void mostrarMasVieja(struct compu* pcs, int cantidad);
   void mostrarMasVeloz(struct compu* pcs, int cantidad);




   int main(){
    compu* computadoras;
    srand(time(NULL));
    char tipos[6][10] = {"Intel","AMD","Athlon","Core","Pentium"};
    computadoras = (compu *)malloc(5 * sizeof(compu));
    for (int i = 0; i < 5; i++)
    {
        computadoras[i].velocidad = 1 + rand()%3;
        computadoras[i].anio = rand()% (2024 - 2015 +1) + 2015;
        computadoras[i].cantidad_nucleos = 1 + rand()%8;
        computadoras[i].tipo_cpu = tipos[rand()%6];
    }
    listarPCs(computadoras,5);
    printf("\n\n\n");
    mostrarMasVieja(computadoras,5);
    printf("\n\n\n");
    mostrarMasVeloz(computadoras,5);
    return 0;
   }


void listarPCs( compu* pcs, int cantidad){
    for (int i = 0; i < cantidad; i++)
    {
        printf("Computadora: %d\n",i+1);
        printf("\tVelocidad: %d GHz\n",pcs[i].velocidad);
        printf("\tAnio de fabricacion: %d \n",pcs[i].anio);
        printf("\tCantidad de nucleos:  %d \n",pcs[i].cantidad_nucleos);
        printf("\t Modelo:");
        puts(pcs[i].tipo_cpu);
        printf("\n");
    }
    
}




void mostrarMasVieja(struct compu* pcs, int cantidad){
    int m=2025,indice;
    for (int i = 0; i < cantidad; i++)
    {
        if (pcs[i].anio < m)
        {
            indice = i;
            m = pcs[i].anio;
        }
    }
    printf("Computadora mas vieja: %d\n",indice+1);
    printf("\tVelocidad: %d GHz\n",pcs[indice].velocidad);
    printf("\tAnio de fabricacion: %d \n",pcs[indice].anio);
    printf("\tCantidad de nucleos:  %d \n",pcs[indice].cantidad_nucleos);
    printf("\t Modelo:");
    puts(pcs[indice].tipo_cpu);
}




void mostrarMasVeloz(struct compu* pcs, int cantidad){
    int M=0,indice;
    indice = (int *)malloc(sizeof(int));
    for (int i = 0; i < cantidad; i++)
    {
        if (pcs[i].velocidad > M)
        {
            M = pcs[i].velocidad;
            indice = i;
        }
    }
    printf("Computadora mas veloz: %d\n",indice+1);
    printf("\tVelocidad: %d GHz\n",pcs[indice].velocidad);
    printf("\tAnio de fabricacion: %d \n",pcs[indice].anio);
    printf("\tCantidad de nucleos:  %d \n",pcs[indice].cantidad_nucleos);
    printf("\t Modelo:");
    puts(pcs[indice].tipo_cpu);
    
}