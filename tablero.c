#include <stdio.h>
int tablero(int a[8][8])
{
  //esta funcion solo imprime el tablero
  int x = 1;
  int t = 1;
  int indiceletra = 65;
  if (t == 1)
  {
      for (int c = 0; c <8; c++)
        {
          for(int l = 0; l < 8; l++)
           {
              if (c == 0 && l == 0)
              {
                printf(" ");
             }
             else if(l == 0)
             {
               printf("%c ",indiceletra);
               indiceletra = indiceletra + 1;
             }
             else if (c == 0)
             {
                printf(" %d ", x);
                x = x+1;
             }
              else if (a[c][l]== 0)
              {
                printf("%s ","\U0001F30A");// esto es el unicode para el emoji de olas de mar, simulando los logares vacios.
             }
             else if(a[c][l]== 10)
             {
               printf(" ^ ");
             }
             else if(a[c][l]== 11)
             {
               printf("|| ");
             }
             else if(a[c][l]== 12)
             {
               printf(" v ");
             }
              else if(a[c][l]== 20)
             {
               printf(" < ");
             }
             else if(a[c][l]== 21)
             {
               printf(" = ");
             }
             else if(a[c][l]== 22)
             {
               printf(" > ");
             }
             else if (a[c][l]== 30)
             {
               printf("%s","\U0001F4A5");
             }
             }
          printf("\n");
            }
         
        }
    
    else if (t == 2)
    {
           for (int c = 0; c <8; c++)
        {
          for(int l = 0; l < 8; l++)
           {
              if (c == 0 && l == 0)
              {
                printf(" ");
             }
             else if(l == 0)
             {
               printf("%c ",indiceletra);
               indiceletra = indiceletra + 1;
             }
             else if (c == 0)
             {
                printf(" %d ", x);
                x = x+1;
             }
              else if (a[c][l]== 0)
              {
                printf("%s ","\U0001F30A");// esto es el unicode para el emoji de olas de mar, simulando los logares vacios. 
              }
            }
          }
        }
      }