#define _CRT_SECURE_NO_WARNINGS
# include<stdio.h>
# include<stdlib.h>
# include<math.h>
#include <locale.h>

void main1(int n, int min, int max)
{
  setlocale(LC_ALL, "Russian");
  char mas = 0;

  FILE* f;
  f = fopen("txt.txt", "w");
  


  if (f != NULL) {
    for (int i = 0; i < n; i++)
    {
      mas = min + rand() % (max - min);
      fprintf(f, "%c", mas);
    }
  }
  fclose(f);
  

  return 0;
}