#include <stdio.h>
#include <stdlib.h>
#include "tablero.h"
int array1[] = {};
int array2[] = {};
typedef struct Renglones1 //creando la estructura
{
int disparo; //dato que se va a guardar en la estructura
struct Renglones1 *next;
}Renglones1; //inizializa por asi decirlo que voy a llamar "Renglones1" a la estructura


typedef struct Columna1
{
int disparo;
struct Columna1 *next;
}Columna1;


typedef struct Renglon2
{
int disparo;
struct Renglon2 *next;
}Renglon2;


typedef struct Columna2
{
int disparo;
struct Columna2 *next;
}Columna2;


int disparosr1(Renglones1 **head,int disparo); // **head es un puntero como al inicio de la estructura, al primer elemento
int disparosc1(Columna1 **head, int disparo);
int disparosr2(Renglon2   **head, int disparo);
int disparosc2(Columna2 **head, int disparo);
void print_listc1(Columna1 *head);
void print_listr1(Renglones1 *head);
void print_listc2(Columna2 *head);
void print_listr2(Renglon2 *head);
int recorrer1(Renglones1 *head, Columna1 *head1, int a, int b, int index);
int recorrer2(Renglon2 *head, Columna2 *head1, int a, int b, int index);
int explosivo(int a[8][8],int b[8][8]);
int explosivosIA(int a[8][8], int b[8][8]);
int recorrerIA(Renglones1 *head, Columna1 *head1, int a, int b, int index);

int explosivo(int a[8][8], int b[8][8])
{
  int ganador = 0;
  Renglones1 *headr1 = NULL;
  Columna1 *headc1 = NULL;
  Renglon2 *headr2 = NULL;
  Columna2 *headc2 = NULL;
  int turno = 1;
  int puntos1 = 0;
  int puntos2 = 0;
  int contador1 = 1;
  int contador2= 1;
  while (ganador == 0)
    {
  if (turno == 1)
    {
      printf("Es el turno del jugador 1 \n");
      int discol = 0;
      int disren = 0;
      printf("Escribe el renglon a donde vas a disparar \n");
      scanf("%d",&disren);
      fflush(stdout);
      printf("Escribe la columna a donde vas a disparar \n");
      scanf("%d",&discol);
      fflush(stdout);
      if (discol>=7 || disren<= 0 || disren>=7 || discol <= 0)
        {
          while (discol>=7 || disren<= 0 || disren>=7 || discol <= 0)
            {
              printf("El dato que introduciste se va a salir del tablero, porfavor ingresalo de nuevo \n");
              printf("Escribe el renglon del disparo \n");
              scanf("%d", &disren);
              fflush(stdout);
              printf("Escribe la columna del disparo \n");
              scanf("%d", &discol);
              break;
            }
          }
      recorrer1(headr1,headc1,disren,discol,contador1);
      if (b[disren][discol] != 0)
      {
        puntos1 = puntos1 +1;
        printf("Golpeaste un barco llevas %d puntos \n", puntos1);
      }
      b[disren][discol]=30;
      tablero(b);
      if (puntos1 == 9)
      {
        printf("Has ganado\n");
        ganador = 1;
        break;
      }
      disparosr1(&headr1, disren);
      print_listr1(headr1);
      disparosc1(&headc1, discol);
      print_listc1(headc1);
      contador1=contador1+1;
      turno = 2;
        }
  if (turno == 2)
    {
      printf("Es el turno del jugador 2 \n");
      int discol = 0;
      int disren = 0;
      printf("Escribe el renglon a donde vas a disparar \n");
      scanf("%d",&disren);
      fflush(stdout);
      printf("Escribe el columna a donde vas a disparar \n");
      scanf("%d",&discol);
      fflush(stdout);
      if (discol>=7 || disren<= 0 || disren>=7 || discol <= 0)
        {
          while (discol>=7 || disren<= 0 || disren>=7 || discol <= 0)
            {
              printf("El dato que introduciste se va a salir del tablero, porfavor ingresalo de nuevo \n");
              printf("Escribe el renglon del disparo \n");
              scanf("%d", &disren);
              fflush(stdout);
              printf("Escribe la columna del disparo \n");
              scanf("%d", &discol);
              break;
            }
          }
      recorrer2(headr2, headc2, disren, discol, contador2);
      if (a[disren][discol] != 0)
      {
        puntos2 = puntos2 +1;
        printf("Golpeaste un barco llevas %d puntos \n", puntos2);
        
      }
      a[disren][discol]=30;
      tablero(a);
      if (puntos2 == 9)
      {
        printf("Has ganado \n");
        ganador = 1;
        break;
      }
      contador2=contador2+1;
      disparosr2(&headr2, disren);
      print_listr2(headr2);
      disparosc2(&headc2, discol);
      print_listc2(headc2);
      turno = 1;
        }
      }
}
int explosivosIA(int a[8][8], int b[8][8])
{
  int ganador = 0;
  Renglones1 *headr1 = NULL; // indicando que la cabeza del nodo esta vacia
  Columna1 *headc1 = NULL;
  Renglon2 *headr2 = NULL;
  Columna2 *headc2 = NULL;
  int turno = 1;
  int puntos1 = 0;
  int puntos2 = 0;
  int contador1 = 1;
  int contador2= 1;
  while (ganador == 0)
    {
      printf("Void;");
  if (turno == 1)
    {
      printf("Es el turno del la IA \n");
      int discol = 0;
      int disren = 0;
      discol = rand() % 7+1;
      disren = rand()% 7+1;
      if (discol>=7 || disren<= 0 || disren>=7 || discol <= 0)
        {
          while (discol>=7 || disren<= 0 || disren>=7 || discol <= 0)
            {
              discol = rand() % 7+1;
              disren = rand()% 7+1;
            }
          }
      recorrerIA(headr1,headc1,disren,discol,contador1);
      if (b[disren][discol] != 0)
      {
        puntos1 = puntos1 +1;
        printf("La IA golpeo un barco, lleva %d puntos. \n", puntos1);
      }
      b[disren][discol]=30;
      tablero(b);
      if (puntos1 == 9)
      {
        printf("La torpe IA te gano");
        ganador = 1;
      }
      disparosr1(&headr1, disren);
      print_listr1(headr1);
      disparosc1(&headc1, discol);
      print_listc1(headc1);
      contador1=contador1+1;
      turno = 2;
        }
  if (turno == 2)
    {
      printf("Es tu turno \n");
      int discol = 0;
      int disren = 0;
      printf("Escribe el renglon a donde vas a disparar \n");
      scanf("%d",&disren);
      fflush(stdout);
      printf("Escribe el columna a donde vas a disparar \n");
      scanf("%d",&discol);
      fflush(stdout);
      if (discol>=7 || disren<= 0 || disren>=7 || discol <= 0)
        {
          while (discol>=7 || disren<= 0 || disren>=7 || discol <= 0)
            {
              printf("El dato que introduciste se va a salir del tablero, porfavor ingresalo de nuevo \n");
              printf("Escribe el renglon del disparo \n");
              scanf("%d", &disren);
              fflush(stdout);
              printf("Escribe la columna del disparo \n");
              scanf("%d", &discol);
            }
          }
      recorrer2(headr2, headc2, disren, discol, contador2);
      if (a[disren][discol] != 0)
      {
        puntos2 = puntos2 +1;
        printf("Golpeaste un barco llevas %d puntos \n", puntos2);
        
      }
      a[disren][discol]=30;
      tablero(a);
      if (puntos2 == 9)
      {
        printf("Has ganado \n");
        ganador = 1;
      }
      contador2=contador2+1;
      disparosr2(&headr2, disren);
      print_listr2(headr2);
      disparosc2(&headc2, discol);
      print_listc2(headc2);
      turno = 1;
        }
      printf("Void \n");
      }
}
int disparosr1(Renglones1 **head, int disparo)
{
  Renglones1 *renglon1 = (Renglones1*)malloc(sizeof(Renglones1)); // creo la variable columna con un pointer a la estructura de Renglones del jugador 1, se crea con el tamaño de la estructura, para eso es la funcion malloc. Basicamente, crea un nuevo nodo el la lista
  renglon1 -> disparo=disparo; // -> se utiliza para cuando queremos entrar a un elemento en la lista mediante el pointer de ese elemento y no como tal al de la estructura  es equivalente a (*ptr).disparo
  renglon1->next = NULL; // para que el siguiente elemento este vacio
  if (*head == NULL)
  {
    *head =renglon1;
    // si la lista esta vacia, convierte el elemento en la cabeza
  }
//recorre la lista hasta el ultimo nodo
  Renglones1 *ultimo = *head;
    while (ultimo->next != NULL) 
      {
        ultimo = ultimo->next;
      }
ultimo -> next=renglon1; 
}
int disparosc1 (Columna1 **head,int disparo) //se repite para las casillas del jugador 1
{
  Columna1 *columnas1= (Columna1*)malloc(sizeof(Columna1));
  columnas1 -> disparo = disparo;
  columnas1 -> next = NULL;
  if (*head == NULL)
  {
    *head = columnas1;
  }
  Columna1* ultimo = *head;
  while (ultimo -> next != NULL)
    {
      ultimo = ultimo -> next;
    }
  ultimo -> next = columnas1;
    }
 int disparosr2 (Renglon2 **head,int disparo) //se repite pero ahora para guardar los renglones del jugador 2
{
  Renglon2 *renglon2= (Renglon2*)malloc(sizeof(Renglon2));
  renglon2 -> disparo = disparo;
  renglon2 -> next = NULL;
  if (*head == NULL)
  {
    *head = renglon2;
  }
  Renglon2* ultimo = *head;
  while (ultimo -> next != NULL)
    {
      ultimo = ultimo -> next;
    }
  ultimo -> next = renglon2;
    }
int disparosc2 (Columna2 **head,int disparo)//se repite pero ahora para guardar los columnas del jugador 2
{
  Columna2 *columnas2= (Columna2*)malloc(sizeof(Columna2));
  columnas2 -> disparo = disparo;
  columnas2 -> next = NULL;
  if (*head == NULL)
  {
    *head = columnas2;
  }
  Columna2* ultimo = *head;
  while (ultimo -> next != NULL)
    {
      ultimo = ultimo -> next;
    }
  ultimo -> next = columnas2;
    }
void print_listc1(Columna1 *head) {
  printf("Llevas estos disparos en las columnas: \n"); // imprime la lista de las columnas del primer jugador
    Columna1 *current = head;
    while (current != NULL) {
        printf(" %d,", current->disparo);
        current = current->next;
        break;
    }
  printf("\n");
}
void print_listr1(Renglones1 *head) {
  // imprime la lista de las renglon del primer jugador
  printf("Llevas estos disparos en los renglones: \n");
    Renglones1 *current = head;
    while (current != NULL) {
        printf(" %d,", current->disparo);
        current = current->next;
      break;
    }
  printf("\n");
}
void print_listc2(Columna2 *head) {
  // imprime la lista de las columnas del segundo jugador
  printf("Llevas estos disparos en las columnas: \n");
    Columna2 *current = head;
    while (current != NULL) {
        printf(" %d,", current->disparo);
        current = current->next;
      break;
    }
  printf("\n");
}
void print_listr2(Renglon2 *head) {
  // imprime la lista de renglones del segundo jugador
    Renglon2 *current = head;
  printf("Llevas estos disparos en los renglones: \n");
    while (current != NULL) {
        printf(" %d,", current->disparo);
        current = current->next;
      break;
    }
  printf("\n");
}
int recorrer1(Renglones1 *head, Columna1 *head1, int a, int b, int index)
{
  Renglones1* currentr = head;
  Columna1* currentc = head1;
  for (int i = 0; i < index; i++)
    {
      if (currentr == NULL || currentc == NULL) 
      {
        break;
    }
    currentr = currentr->next;
    currentc = currentc->next;
  if (currentr->disparo == a && currentc ->disparo == b) 
  {
    while (currentr->disparo == a && currentc ->disparo == b) 
      {
        printf("Ya disparaste a esa ubicacion vuelve a intentarlo \n");
        printf("Escribe el renglon al que vas a disparar \n");
        scanf("%d", &a);
        fflush(stdout);
        printf("Escribe la columna al que vas a disparar \n");
        scanf("%d",&b);
        fflush(stdout);
      }
  } 
}
}
int recorrer2(Renglon2 *head, Columna2 *head1, int a, int b, int index)
{
  //esta es una funcion para checar, que no se hayan repetido, recibe el nodo, los inputs, de los renglones y columnas y , cuantas veces se ha disparado para un ciclo for mas adelante
  Renglon2* currentr = head;
  Columna2* currentc = head1;
  for (int i = 0; i < index; i++)
    {
      if (currentr == NULL || currentc == NULL) {
        break;
        // esto nada mas checa que las 2 listas tengan la misma cantidad de elementos, que siempre va a ser asi
    }
    currentr = currentr->next; //esto recorre la lista, el current se convierte en el siguiente
    currentc = currentc->next;
  if (currentr->disparo == a && currentc ->disparo == b) 
  {
    while (currentr->disparo == a && currentc ->disparo == b) 
      {
        printf("Ya disparaste a esa ubicacion vuelve a intentarlo \n");
        printf("Escribe el renglon al que vas a disparar \n");
        scanf("%d", &a);
        fflush(stdout);
        printf("Escribe la columna al que vas a disparar");
        scanf("%d",&b);
        fflush(stdout);
      // y aqui si ya disparo al mismo lugar, le vuelve a pedir los inputs
      }
  }
}
}
int recorrerIA(Renglones1 *head, Columna1 *head1, int a, int b, int index)
{
  Renglones1* currentr = head;
  Columna1* currentc = head1;
  for (int i = 0; i < index; i++)
    {
      if (currentr == NULL || currentc == NULL) 
      {
      break; 
    }
    currentr = currentr->next;
    currentc = currentc->next;
  if (currentr->disparo == a && currentc ->disparo == b) 
  {
    while (currentr->disparo == a && currentc ->disparo == b) 
      {
        a = rand() % 7+1;
        b = rand()% 7+1;
        // lo mismo adaptado a la IA
      }
  } 
}
}