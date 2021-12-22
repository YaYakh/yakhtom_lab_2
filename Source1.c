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
  FILE* nf;
  nf = fopen("n.txt", "w");

  if (nf != NULL)
    fprintf(nf, "%d\n", n);


  if (f != NULL) {
    for (int i = 0; i < n; i++)
    {
      mas = min + rand() % (max - min);
      fprintf(f, "%c", mas);
    }
  }
  fclose(f);
  fclose(nf);

  return 0;
}