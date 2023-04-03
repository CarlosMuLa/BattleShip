#include <stdio.h>
#include "tablero.h"
int rayar(int a[8][8])
{
  int contadora = 0;
  int contadorb = 0;
  int inicioc = 0;
  int iniciol = 0;
  int direccion = 0;
  printf("¿Como quieres poner el barco: 1. Vertical o 2. Horizontal? \n");
  scanf("%d", &direccion);
  fflush(stdout);
  if (direccion != 1 && direccion !=2)//por si el usuario puso mal el input
  {
    while (direccion != 1 && direccion != 2)
      {
        printf("El dato que introduciste es incorrecto, vuelve a ingresarlo. \n");
        scanf("%d", &direccion);
        fflush(stdout);
      }
  }
  while (direccion == 1) // si selecciono 1, los barcos se colocan de manera horizontal
  {
    if(contadora== 3)
    {
      printf("Ya colocaste todos los barcos. \n");
      direccion = 0;
      break;
    }
    else{
    printf("Aviso: el barco se colocara de la casilla indicada hacia abajo \n");
    for(int i = 0; contadora<3; i++)
      {
        contadora = contadora+1;
        printf("Escribe el renglon del barco %d: \n",contadora);
        scanf("%d", &iniciol);
        fflush(stdout);
        printf("Escribe el columna del barco %d: \n",contadora);
        scanf("%d", &inicioc);
        fflush(stdout);
        if (iniciol+1 > 7 ||iniciol+2 > 7 ||iniciol > 7 ||inicioc+1 > 7 ||inicioc+2 > 7 ||inicioc > 7 || a[iniciol][inicioc] != 0 || a[iniciol+1][inicioc] != 0|| a[iniciol+2][inicioc] != 0)
        {
          while (iniciol+1 > 7 ||iniciol+2 > 7 ||iniciol > 7 ||inicioc+1 > 7 ||inicioc+2 > 7 ||inicioc > 7 || a[iniciol][inicioc] != 0 || a[iniciol+1][inicioc] != 0|| a[iniciol+2][inicioc] != 0) // checa que no se salga de tablero, o ya este ocupada
            {
              printf("El dato que introduciste se va a salir del tablero o esta ocupado, porfavor ingresalo de nuevo \n");
              printf("Escribe el renglon del barco %d: \n",contadora);
              scanf("%d", &iniciol);
              fflush(stdout);
              printf("Escribe el columna del barco %d: \n",contadora);
              scanf("%d", &inicioc);
              fflush(stdout);
              break;
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
          break;
        }
        printf("Quieres seguir poniendo tus barcos de manera Vertical? 1.Si 2. No: \n");
        scanf("%d",&direccion);
        if (direccion == 2)
          {
            break;
          }
        else if (direccion != 1)
        {
          while (direccion != 1)
        {
        printf("El dato que introduciste es incorrecto, vuelve a ingresarlo. \n");
        scanf("%d", &direccion);
        fflush(stdout);
        }
      }
    
  }
}
}
  }
//---------------------------Primera vez que se entra al codigo, para decidir si se van a poner horizontal o vertical-----------------------------
    while (direccion == 2)
  {
    if(contadora== 3)
    {
      printf("Ya colocaste todos los barcos. \n");
      break;
    }
    else 
    {
    printf("Aviso: el barco se colocara de la casilla indicada hacia la derecha \n");
    for(int i = 0; contadora<3; i++)
      {
        contadora = contadora+1;
        printf("Escribe el renglon del barco %d: \n",contadora);
        scanf("%d", &iniciol);
        fflush(stdout);
        printf("Escribe la columna del barco %d: \n",contadora);
        scanf("%d", &inicioc);
        fflush(stdout);
        if (iniciol+1 > 7 ||iniciol+2 > 7 ||iniciol > 7 || iniciol<= 0 || a[iniciol][inicioc] != 0 || a[iniciol][inicioc+1] != 0 || a[iniciol][inicioc+2] != 0)
        {
          while (iniciol+1 > 7 ||iniciol+2 > 7 ||iniciol > 7 || iniciol<= 0 || a[iniciol][inicioc] != 0 || a[iniciol][inicioc+1] != 0 || a[iniciol][inicioc+2] != 0)
            {
              printf("El dato que introduciste se va a salir del tablero o ya esta ocupado, porfavor ingresalo de nuevo \n");
              printf("Escribe el renglon del barco %d: \n",contadora);
              scanf("%d", &iniciol);
              fflush(stdout);
              printf("Escribe el columna del barco %d: \n",contadora);
              scanf("%d", &inicioc);
              break;
            }
          for (int barco = 0; barco < 3; barco ++)
          {
            a[iniciol][inicioc+barco]= 20+barco;
          }
        tablero(a);
        }
        //locura
        else if(iniciol+1 < 7 ||iniciol+2 < 7 ||iniciol < 7 || iniciol > 0 || a[iniciol][inicioc] == 0 || a[iniciol][inicioc+1] == 0 || a[iniciol][inicioc+2] == 0)
        {
        for (int barco = 0; barco < 3; barco ++)
          {
            a[iniciol][inicioc+barco]= 20+barco;
          }
        tablero(a);
        if(contadora == 3)
        {
          tablero(a);
          break;
        }
        printf("Quieres seguir poniendo tus barcos de manera horizontal? 1.Si 2. No: \n");
        scanf("%d",&direccion);// como un break seleccionando que queria poner de manera horizontal los barcos ya no me llevaba hasta la parte de arriba del codigo lo puse aqui, no es lo mejor pero me funciono
        if (direccion == 2)
          {
               printf("Aviso: el barco se colocara de la casilla indicada hacia abajo \n");
    for(int i = 0; contadora<3; i++)
      {
        contadora=contadora+1;
        printf("Escribe el renglon del barco %d: \n",contadora);
        scanf("%d", &iniciol);
        printf("Escribe la columna del barco %d: \n",contadora);
        scanf("%d", &inicioc);
        if (iniciol+1 > 7 ||iniciol+2 > 7 ||iniciol > 7 ||inicioc+1 > 7 ||inicioc+2 > 7 ||inicioc > 7  || a[iniciol][inicioc] != 0 || a[iniciol+1][inicioc]!= 0 || a[iniciol+2][inicioc]!= 0 )
        {
          while (iniciol+1 > 7 ||iniciol+2 > 7 ||iniciol > 7 ||inicioc+1 > 7 ||inicioc+2 > 7 ||inicioc > 7  || a[iniciol][inicioc] != 0 || a[iniciol][inicioc+1]!= 0 || a[iniciol][inicioc+2]!= 0)
            {
              printf("El dato que introduciste se va a salir del tablero o ya esta ocupado, porfavor ingresalo de nuevo \n");
              printf("Escribe el renglon del barco %d: \n",contadora);
              scanf("%d", &iniciol);
              printf("Escribe el renglon del barco %d: \n",contadora);
              scanf("%d", &inicioc);
              break;
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
          printf("Ya colocaste todos los barcos. \n");
          direccion= 0;
          break;
        }
        else{
        printf("Quieres seguir poniendo tus barcos de manera horizontal? 1.Si 2. No: \n");
        scanf("%d",&direccion);
        if(direccion== 1)
        {
          direccion = 2;
          break;
        }
        else if (direccion == 2)
        {
          direccion = 1;
          break;
        }
        else if (direccion!=2)
        {
          while (direccion != 2)
        {
        printf("El dato que introduciste es incorrecto, vuelve a ingresarlo. \n");
        scanf("%d", &direccion);
        fflush(stdout);
        }
        }
      }
    }
  }
      }
}
}
}
}