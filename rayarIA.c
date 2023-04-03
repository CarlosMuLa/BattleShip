#include <stdio.h>
#include <stdlib.h>
#include "tablero.h"
#include <time.h>
//esto es basicamente lo mismo que  la funcion de rayar normal, solo que adaptada para la IA
int aleatorio(int a[8][8]) 
{
  srand(time(0));
  int contadora = 0;
  int contadorb = 0;
  int inicioc = 0;
  int iniciol = 0;
  int direccion = 0;
  for(int i = 0; i < 3; i++)
    {
      direccion = rand()%2+1;
  //int lower = 0, upper = 65535;
  //int al = rand() % upper + lower;
  if (direccion == 1)
  {
    for(int i = 0; contadora<3; i++)
      {
        contadora = contadora+1;
        inicioc = rand() % 7+1;
        iniciol = rand()% 7+1;
        
        if (iniciol+1 >= 7 ||iniciol+2 >= 7 ||iniciol >= 7 ||inicioc+1 >= 7 ||inicioc+2 >= 7 ||inicioc >= 7  || a[iniciol][inicioc] != 0 || a[iniciol+1][inicioc]!= 0 || a[iniciol+2][inicioc]!= 0 || a[iniciol][inicioc+1]!= 0 || a[iniciol][inicioc+2]!= 0 ||iniciol+3 > 7 ||inicioc+3 > 7)
        {
          while (iniciol+1 >= 7 &&iniciol+2 >= 7 &&iniciol >= 7 ||inicioc+1 >= 7 ||inicioc+2 >= 7 ||inicioc >= 7  || a[iniciol][inicioc] != 0 || a[iniciol+1][inicioc]!= 0 || a[iniciol+2][inicioc]!= 0 || a[iniciol][inicioc+1]!= 0 || a[iniciol][inicioc+2]!= 0 ||iniciol+3 > 7 ||inicioc+3 > 7)
            {
              inicioc = rand() % 7+1;
              iniciol = rand()% 7+1;
          }
          for (int barco = 0; barco < 3; barco ++)
          {
            a[iniciol+barco][inicioc]= 10+barco;
          }
        tablero(a);
        }
        else
      {
        for (int barco = 0; barco < 3; barco ++)
          {
            a[iniciol+barco][inicioc]= 10+barco;
          }
        tablero(a);
        if(contadora== 3)
        {
          direccion = 0;
        }
        else{
        int direccion = rand()%2+1;
        }
  }
}
}
  }
//---------------------------Primera vez que se entra al codigo, para decidir si se van a poner horizontal o vertical-----------------------------
    if (direccion == 2)
  {
    if(contadora== 3)
    {
      direccion =0;
    }
    for(int i = 0; contadora<3; i++)
      {
        contadora = contadora+1;
        inicioc = rand() % 7+1;
        iniciol = rand()% 7+1;
        if (iniciol+1 >= 7 &&iniciol+2 >= 7 &&iniciol >= 7 ||inicioc+1 >= 7 ||inicioc+2 >= 7 ||inicioc >= 7  || a[iniciol][inicioc] != 0 || a[iniciol+1][inicioc]!= 0 || a[iniciol+2][inicioc]!= 0 || a[iniciol][inicioc+1]!= 0 || a[iniciol][inicioc+2]!= 0 ||iniciol+3 > 7 ||inicioc+3 > 7)
        {
          while(iniciol+1 >= 7 &&iniciol+2 >= 7 &&iniciol >= 7 ||inicioc+1 >= 7 ||inicioc+2 >= 7 ||inicioc >= 7  || a[iniciol][inicioc] != 0 || a[iniciol+1][inicioc]!= 0 || a[iniciol+2][inicioc]!= 0 || a[iniciol][inicioc+1]!= 0 || a[iniciol][inicioc+2]!= 0 ||iniciol+3 > 7 ||inicioc+3 > 7)
            {
              inicioc = rand() % 7+1;
              iniciol = rand()% 7+1;
            }
          for (int barco = 0; barco < 3; barco ++)
          {
            a[iniciol][inicioc+barco]= 20+barco;
          }
        tablero(a);
        }
        //locura
        for (int barco = 0; barco < 3; barco ++)
          {
            a[iniciol][inicioc+barco]= 20+barco;
          }
        tablero(a);
        if(contadora == 3)
        {
          tablero(a);
          direccion = 0;
        }
        direccion = rand()%2+1;
        if (direccion == 1)
          {
    for(int i = 0; contadora<3; i++)
      {
        contadora=contadora+1;
        inicioc = rand() % 7+1;
        iniciol = rand()% 7+1;
        if (iniciol+1 >= 7 &&iniciol+2 >= 7 &&iniciol >= 7 ||inicioc+1 >= 7 ||inicioc+2 >= 7 ||inicioc >= 7  || a[iniciol][inicioc] != 0 || a[iniciol+1][inicioc]!= 0 || a[iniciol+2][inicioc]!= 0 || a[iniciol][inicioc+1]!= 0 || a[iniciol][inicioc+2]!= 0 ||iniciol+3 > 7 ||inicioc+3 > 7 )
        {
          while (iniciol+1 >= 7 ||iniciol+2 >= 7 ||iniciol >= 7 ||inicioc+1 >= 7 ||inicioc+2 >= 7 ||inicioc >= 7  || a[iniciol][inicioc] != 0 || a[iniciol+1][inicioc]!= 0 || a[iniciol+2][inicioc]!= 0 || a[iniciol][inicioc+1]!= 0 || a[iniciol][inicioc+2]!= 0 ||iniciol+3 > 7 ||inicioc+3 > 7)
            {
              inicioc = rand() % 7+1;
              iniciol = rand()% 7+1;
        }
          for (int barco = 0; barco < 3; barco ++)
          {
            a[iniciol][inicioc+barco]= 20+barco;
          }
        tablero(a);
        }
        for (int barco = 0; barco < 3; barco ++)
          {
            a[iniciol+barco][inicioc]= 10+barco;
          }
        tablero(a);
        if(contadora== 3)
        {
          direccion= 0;
          break;
        }
        
    }
  }
      }
}
}

