# include<stdio.h>
# include<stdlib.h>
# include<math.h>
#include <locale.h>

int main1()
{
  setlocale(LC_ALL, "Russian");
  int n = 0;
  int min = 0;
  int max = 0;
  char mas = 0;
 
 
  printf(" n = ");
  scanf_s("%d", &n);
  if (n <= 0) {
    printf("error n <= 0");
    return 0;
  }

  

  printf(" min = ");
  scanf_s("%d", &min);

  printf(" max = ");
  scanf_s("%d", &max);

  if (min > max) {
    printf("error min > max");
    return 0;
  }

  if (min < -128) {
    printf("error char >> {-128 . . 127}");
    return 0;
  }
  if (max > 127) {
    printf("error char >> {-128 . . 127}");
    return 0;
  }

  FILE *f;
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