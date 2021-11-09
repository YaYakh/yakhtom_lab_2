# include<stdio.h>
#include<stdlib.h>
#include <locale.h>
#include <time.h>

void bubblesort(char* a, int n)
{
  int i, q;
  char t;
  for (i = n - 1; i > 0; i--)
  {
    for (q = 0; q < i; q++)
    {
      if (a[q] > a[q + 1])
      {
        t = a[q + 1];
        a[q + 1] = a[q];
        a[q] = t;
      }
    }
  }
}


void fastsort(char* a, int n) {
  int i = 0;
  int j = n - 1;
  int m = a[n / 2];

  do {
    while (a[i] < m) {
      i++;
    }
    while (a[j] > m) {
      j--;
    }

    if (i <= j) {
      int t = a[i];
      a[i] = a[j];
      a[j] = t;

      i++;
      j--;
    }
  } while (i <= j);

  if (j > 0) {
    fastsort(&a[0], j + 1);
  }
  if (i < n) {
    fastsort(&a[i], n - i);
  }
}


void pastesort(char* a, int n)
{
  int t;
  int j;
  for (int i = 1; i < n; i++)
  {
    t = a[i];
    j = i - 1;
    while (j >= 0 && a[j] > t)
    {
      a[j + 1] = a[j];
      a[j] = t;
      j--;
    }
  }
}


int main()
{
  main1();
  setlocale(LC_ALL, "");
  char nnf[20];
  char nc[8];
  int intf = 0;

  FILE* nf;
  nf = fopen("n.txt", "r");

  if (nf != NULL)
  {
    fscanf(nf, "%d", &intf);
  }

  FILE* f;
  f = fopen("txt.txt", "r");

  char* mas;
  mas = (char*)malloc(intf * sizeof(char));

  char* mas2;
  mas2 = (char*)malloc(intf * sizeof(char));

  if (f != NULL)
  {
    for (int i = 0; i < intf; i++)
      fscanf(f, "%c", &mas[i]);
    for (int i = 0; i < intf; i++)
      mas2[i] = mas[i];
  }

  printf("\n\n\n");

  int ch = 0;
  long double t1 = 0;
  long double t2 = 0;
  while (ch != 1)
  {
    printf(" введите 1 чтобы выйти\n введите 2 чтобы использовать пузырьковую сортировку\n введите 3 чтобы использовать быструю сортировку\n введите 4 чтобы использовать сортировку вставкой\n введите 5 чтобы вывести массив\n введите 6 чтобы сбросить массив к начальному значению\n");
    scanf_s("%d", &ch);
    printf("\n\n");

    switch (ch)
    {
    case 2:
      t1 = clock();
      bubblesort(mas, intf);
      t2 = clock();
      printf("Время выполнения = %.0lf мс\n\n", ((t2 - t1) / CLOCKS_PER_SEC) * 1000);
      break;
    case 3:
      t1 = clock();
      fastsort(mas, intf);
      t2 = clock();
      printf("Время выполнения = %.0lf мс\n\n", ((t2 - t1) / CLOCKS_PER_SEC) * 1000);
      break;
    case 4:
      t1 = clock();
      pastesort(mas, intf);
      t2 = clock();
      printf("Время выполнения = %.0lf мс\n\n", ((t2 - t1) / CLOCKS_PER_SEC) * 1000);
      break;
    case 5:
      for (int i = 0; i < intf; i++)
        printf("%c\n", mas[i]);
      printf("\n\n");
      break;
    case 6:
      for (int i = 0; i < intf; i++)
        mas[i] = mas2[i];
      printf("массив успешно сброшен\n\n");
      break;


    }

  }

  /*for (int i = 0; i < intf; i++)
  {
    printf("%d\n", mas[i]);
  }*/

  fclose(f);
  fclose(nf);
  return 0;
}