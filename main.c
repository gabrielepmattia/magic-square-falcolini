/*
 This file is part of MSolver.

 MSolver is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 MSolver is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with MSolver.  If not, see <http://www.gnu.org/licenses/>.
 
 gabry3795 - gabry dot gabry at hotmail.it
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
#include "magic_solver.h"
#include "matrix.h"

int main(int argc, char** argv){
  int i_value = 0;
  int j_value = 0;
  int n_value = 5;
  int f_flag = 0;	// If functional approach is requested
  char *cvalue = NULL;
  int index;
  int c;

  opterr = 0;
  while ((c = getopt (argc, argv, "n:i:j:f::")) != -1)
    switch (c) {
      case 'n':
        n_value = atoi(optarg);
        if (n_value < 5) {
			fprintf(stderr, "Option -n error. Matrix must be at least 5x5.\n", optopt);
			exit(1);
		}
        break;
      case 'i':
        i_value = atoi(optarg);
        if(i_value >= n_value) {
			fprintf (stderr, "Option -i error. Row exceed matrix dimension.\n", optopt);
			exit(1);
		}
        break;
      case 'j':
        j_value = atoi(optarg);
        if(j_value >= n_value) {
			fprintf (stderr, "Option -j error. Column exceed matrix dimension.\n", optopt);
			exit(1);
		}
        break;
      case 'f':
        f_flag = 1;
        break;
      case '?':
        if (optopt == 'i') fprintf (stderr, "Option -i requires an argument.\n", optopt);
        else if (optopt == 'j') fprintf (stderr, "Option -j requires an argument.\n", optopt);
        else if (optopt == 'n') fprintf (stderr, "Option -n requires an argument.\n", optopt);
        else if (isprint(optopt)) fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        else fprintf (stderr, "Unknown option character `\\x%x'.\n", optopt);
        return 1;
      default:
        abort();
      }
  /*  
   if (argc != 3) {
        printf("Syntax: %s -n <matrix dimension> -i <starting ROW> -j <starting COL>\n", argv[0]);
        exit(EXIT_FAILURE);
   }
   */
  /*
  Number** m1 = (Number**) createEmptyMatrix(6);
  findFirstSolutionSideEffect(m1, 6, 5, 3, 1);
  printMatrix(m1, 6);
  printf("\nIs filled? %d\n\n", isFilled(m1, 6));
  */
  
  printf("\n");
  printf("#========================= MAGIC SQUARE solver ========================#\n");
  printf("# The purpose of the game is to choose a cell in a nxn matrix and fill #\n");
  printf("# the matrix with numbers from 1 to n^2 leaving 2 cell in TOP, BOTTOM, #\n");
  printf("# LEFT and RIGHT positions and 1 cell in diagonals.                    #\n");
  printf("#                                                                      #\n");
  printf("# If you specify the option -f the algorithm will be functional with   #\n");
  printf("# no side-effect                                                       #\n");
  printf("#                                                                      #\n");
  printf("#==> Usage example                                                     #\n");
  printf("# ./msolver -n <matrix dimension> -i <start row> -j <start col> [-f]   #\n");
  printf("#  -> if no parameter are specified default is n=5 i=0 j=0             #\n");
  printf("#======================================================================#\n");
  
  printf("\nI'm trying to solve the magic square with a %dx%d matrix starting from\n the cell %d,%d ", n_value, n_value, i_value, j_value);
  if(f_flag){
    printf("using a functional approach.\n");
    Number** m2 = (Number**) createEmptyMatrix(n_value);
    Number** m2_solved = findFirstSolutionFunctional(m2, n_value, i_value, j_value, 1);
    printf("\nSolved matrix\n");
    printMatrix(m2_solved, n_value);
  } else {
    printf("using a side-effect approach.\n");
    Number** m1 = (Number**) createEmptyMatrix(n_value);
    findFirstSolutionSideEffect(m1, n_value, i_value, j_value, 1);
    printf("\nSolved matrix\n");
    printMatrix(m1, n_value);
  }
  /*
  Number** m1 = (Number**) createEmptyMatrix(n_value);
  findAllSolutionSideEffect(m1, n_value, i_value, j_value, 1);
  */
  printf("\n\n");
  
  //printMatrix(m1, n_value);
    
  return 0;
  
}
