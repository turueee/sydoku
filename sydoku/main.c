#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void create_sudoky_matrix(int** sudoky_matrix)
{
  int counter,counter1,counter2,number_for_matrix,logic,counter11,counter22;
  for (counter1 = 0; counter1 < 9; counter1++)
  {
    for (counter2 = 0; counter2 < 9; counter2++)
      sudoky_matrix[counter1][counter2] = 0;
  }

  for (counter1 = 0; counter1 < 9; counter1++)
  {
    for (counter2 = 0; counter2 < 9; counter2++)
    {
      logic = 0;
      number_for_matrix = rand() % 9+1;
      check:
      for (counter = 0; counter < 9; counter++)
      {
        if (number_for_matrix == sudoky_matrix[counter1][counter] || number_for_matrix == sudoky_matrix[counter][counter2])
          logic = 1;
      }
      for (counter11 = 0; counter11 < 3; counter11++)
      {
        for (counter22 = 0; counter22 < 3; counter22++)
        {
          if (sudoky_matrix[counter1 / 3 * 3 + counter11][counter2 / 3 * 3 + counter22] == number_for_matrix)
            logic = 1;
        }
      }
      if (logic == 0)
      {
        sudoky_matrix[counter1][counter2] = number_for_matrix;
        printf("* ");
      }
      else
        goto check;
    }
  }
}

void free_int_matrix(int columns, int** matrix)
{
  for (int counter = 0; counter < columns; counter++)
    free(matrix[counter]);
  free(matrix);
}

void print_for_int_matrix(int columns, int strings, int** matrix)
{
  int counter1, counter2;
  for (int counter1 = 0; counter1 < columns; counter1++)
  {
    if (counter1 == 0)
      printf("/\t");
    else if (counter1 + 1 == columns)
      printf("\\\t");
    else
      printf("|\t");
    for (int counter2 = 0; counter2 < strings; counter2++)
    {
      printf("%d\t", (matrix)[counter1][counter2]);
    }
    if (counter1 == 0)
      printf("\\\t\n");
    else if (counter1 + 1 == columns)
      printf("/\t\n");
    else
      printf("|\t\n");
  }
}


void create_matrix(int order, int*** matrix)
{
  int counter2, counter1;
  (*matrix) = (int**)malloc(sizeof(int*) * order);
  for (counter1 = 0; counter1 < order; counter1++)
    (*matrix)[counter1] = (int*)malloc(sizeof(int) * order);
  for (counter1 = 0; counter1 < order; counter1++)
  {
    for (counter2 = 0; counter2 < order; counter2++)
      (*matrix)[counter1][counter2] = 0;
  }
}

int main()
{
  int** sudoky_matrix;
  srand(time(0));
  create_matrix(9, &sudoky_matrix);
  create_sudoky_matrix(sudoky_matrix);
  print_for_int_matrix(9, 9, sudoky_matrix);
  free_int_matrix(9, sudoky_matrix);
}
