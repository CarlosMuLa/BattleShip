#include <stdio.h>
#include "tablero.h"
#include "rayar.h"
#include "rayarIA.h"
#include "junior.h"

int main(void) {
  int opcion = 0;
  int tablero1[8][8]= {0};
  int tablero2[8][8]= {0};
  int turno = 1;
  int hayganador=0;
  
 //Menu principal del juego
  printf("\tBienvenido a BattleChip!!");
  printf("\nElige tu opción");
  printf("\n1.- Jugador vs Jugador ");
  printf("\n2.- Jugador vs AI");
  printf("\n3.- Salir");
  printf("\n Opción:");
  scanf("%i",&opcion);

  switch(opcion)
  {
    case 1:
      rayar(tablero1);
      printf("Ahora es el turno del Jugador 2 \n");
      rayar(tablero2);
      printf("OKAY AHORA ES EL MOMENTO DE LA VERDAD, ES EL MOMENTO DE DESTRUIR A TU ENEMIGO ¡¡¡¡ATACA!!!! \n");
      explosivo(tablero1,tablero2);
      break;
    case 2:
      rayar(tablero1);
      printf("Ahora la IA va a colicar sus barcos. \n");
      aleatorio(tablero2);
      printf("OKAY AHORA ES EL MOMENTO DE LA VERDAD, ES EL MOMENTO DE DESTRUIR A TU ENEMIGO ¡¡¡¡ATACA!!!! \n");
      explosivosIA(tablero2, tablero1);
    case 3:
      break;
    
  }

  
  return 0;
}