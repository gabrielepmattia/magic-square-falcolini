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
 
 gabry3795 - gabry dot gabry at hotmail.com
*/

#include "define.h"
#include "matrix.h"

Number** createEmptyMatrix(int n){
  Number i,j;
  Number** rows = (Number**) malloc(n*sizeof(Number*));
  for(i = 0; i < n; i++){
    rows[i] = (Number*) malloc(n*sizeof(Number));
    for(j = 0; j < n; j++){
      rows[i][j] = 0;      
    }
  }
  return rows;
}

Number** cloneMatrix(Number** m, int n){
  Number** cloned = createEmptyMatrix(n);
  int i,j;
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      cloned[i][j] = m[i][j]; 
    }
  }
 return cloned;
}

void freeMatrix(Number** m, int n){
  int i;
  for(i = 0; i < n; i++){
    free(m[i]);
  }
  free(m);
}

void printMatrix(Number** m, int n){
  int i,j;
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      printf("%3d", m[i][j]);
    }
    printf("\n");
  }    
}
