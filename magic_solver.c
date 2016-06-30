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

#include "define.h"
#include "magic_solver.h"
#include "matrix.h"
#include <stdio.h>

#define DEBUG 0

/**
 * Check if matrix is filled so that a solution is found
 */
int isFilled(Number** m, int n){
  if(m == NULL) return 0;
  int i,j;
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      if(m[i][j] == 0) return 0;
    }
  }
  return 1;
}

/**
 * Pass this function a clear matrix filled with zero and it will return the pointer
 * at the same matrix but solved, so you can also ignore the return value because 
 * side-effect is done here.
 * 
 * @param m Clear matrix filled with zeros
 * @param mm The size of the squared matrix
 * @param i Starting row
 * @param j Starting col
 * @param n Starting number
 * @return Pointer to the same matrix but filled and solved
 */
void findFirstSolutionSideEffect(Number** m, int mm, int i, int j, int n){
  // Set the number in position i, j
  m[i][j] = n; 
  
    // Try to fill the TOP
    if((i - 3) >= 0 && m[i - 3][j] == 0){
      // Fill the top cell with number if that fill the matrix solution is found else
      // remove that number
      findFirstSolutionSideEffect(m, mm, i - 3, j, n + 1);
    }
    
    // Try to fill the TOP-RIGHT
    if((i - 2) >= 0 && (j + 2) < mm && m[i - 2][j + 2] == 0){
      findFirstSolutionSideEffect(m, mm, i - 2, j + 2, n + 1);
    }
    
    // Try to fill the RIGHT
    if((j + 3) < mm && m[i][j + 3] == 0){
      findFirstSolutionSideEffect(m, mm, i, j + 3, n + 1);
    }
    
    // Try to fill the BOTTOM-RIGHT
    if((i + 2) < mm && (j + 2) < mm && m[i + 2][j + 2] == 0){
      findFirstSolutionSideEffect(m, mm, i + 2, j + 2, n +1);
    }
    
    // Try to fill the BOTTOM
    if((i + 3) < mm && m[i + 3][j] == 0){
      findFirstSolutionSideEffect(m, mm, i + 3, j, n + 1);
    }
    
    // Try to fill the BOTTOM-LEFT
    if((i + 2) < mm && (j - 2) >= 0 && m[i + 2][j - 2] == 0){
      findFirstSolutionSideEffect(m, mm, i + 2, j - 2, n + 1);
    }
    
    // Try to fill the LEFT
    if((j - 3) >= 0 && m[i][j - 3] == 0){
      findFirstSolutionSideEffect(m, mm, i, j - 3, n + 1);      
    }
    
    // Try to fill the TOP-LEFT
    if((i - 2) >= 0 && (j - 2) >= 0 && m[i - 2][j - 2] == 0){
      findFirstSolutionSideEffect(m, mm, i - 2, j - 2, n + 1);
    }
    
    // If no try is available just remove the number
    if(!isFilled(m, mm)) m[i][j] = 0;
}

/**
 * Pass this function a clear matrix filled with zero and it will return a new matrix
 * that has been solved starting from the position i, j
 * 
 * @param m Clear matrix filled with zeros
 * @param mm The size of the squared matrix
 * @param i Starting row
 * @param j Starting col
 * @param n Starting number
 * @return Pointer to the same matrix but filled and solved
 */
Number** findFirstSolutionFunctional(Number** m, int mm, int i, int j, int n){
  m = cloneMatrix(m, mm);
  
  // Set the number in position i, j
  m[i][j] = n; 
    
  if(isFilled(m, mm)) return m;
  
    // Try to fill the TOP
    if((i - 3) >= 0 && m[i - 3][j] == 0){
      // Fill the top cell with number if that fill the matrix solution is found else
      // remove that number
      Number** m_tried = findFirstSolutionFunctional(m, mm, i - 3, j, n + 1);
      if(isFilled(m_tried, mm)) return m_tried;
    }
    
    // Try to fill the TOP-RIGHT
    if((i - 2) >= 0 && (j + 2) < mm && m[i - 2][j + 2] == 0){
      Number** m_tried = findFirstSolutionFunctional(m, mm, i - 2, j + 2, n + 1);
      if(isFilled(m_tried, mm)) return m_tried;
    }
    
    // Try to fill the RIGHT
    if((j + 3) < mm && m[i][j + 3] == 0){
      Number** m_tried = findFirstSolutionFunctional(m, mm, i, j + 3, n + 1);
      if(isFilled(m_tried, mm)) return m_tried;
    }
    
    // Try to fill the BOTTOM-RIGHT
    if((i + 2) < mm && (j + 2) < mm && m[i + 2][j + 2] == 0){
      Number** m_tried = findFirstSolutionFunctional(m, mm, i + 2, j + 2, n +1);
      if(isFilled(m_tried, mm)) return m_tried;
    }
    
    // Try to fill the BOTTOM
    if((i + 3) < mm && m[i + 3][j] == 0){
      Number** m_tried = findFirstSolutionFunctional(m, mm, i + 3, j, n + 1);
      if(isFilled(m_tried, mm)) return m_tried;
    }
    
    // Try to fill the BOTTOM-LEFT
    if((i + 2) < mm && (j - 2) >= 0 && m[i + 2][j - 2] == 0){
      Number** m_tried = findFirstSolutionFunctional(m, mm, i + 2, j - 2, n + 1);
      if(isFilled(m_tried, mm)) return m_tried;
    }
    
    // Try to fill the LEFT
    if((j - 3) >= 0 && m[i][j - 3] == 0){
      Number** m_tried = findFirstSolutionFunctional(m, mm, i, j - 3, n + 1);   
      if(isFilled(m_tried, mm)) return m_tried;
    }
    
    // Try to fill the TOP-LEFT
    if((i - 2) >= 0 && (j - 2) >= 0 && m[i - 2][j - 2] == 0){
      Number** m_tried = findFirstSolutionFunctional(m, mm, i - 2, j - 2, n + 1);
    }
    
    // If no try is available free memory
    if(!isFilled(m, mm)){
      free(m);
      return NULL;      
    }
}

void findAllSolutionSideEffect(Number** m, int mm, int i, int j, int n){
  // Set the number in position i, j
  m[i][j] = n; 
  
    // Try to fill the TOP
    if((i - 3) >= 0 && m[i - 3][j] == 0){
      // Fill the top cell with number
      findFirstSolutionSideEffect(m, mm, i - 3, j, n + 1);
    }
    
    // Try to fill the TOP-RIGHT
    if((i - 2) >= 0 && (j + 2) < mm && m[i - 2][j + 2] == 0){
      findFirstSolutionSideEffect(m, mm, i - 2, j + 2, n + 1);
    }
    
    // Try to fill the RIGHT
    if((j + 3) < mm && m[i][j + 3] == 0){
      findFirstSolutionSideEffect(m, mm, i, j + 3, n + 1);
      printf("AFTER-RIGHT\n");
    }
    
    // Try to fill the BOTTOM-RIGHT
    if((i + 2) < mm && (j + 2) < mm && m[i + 2][j + 2] == 0){
      findFirstSolutionSideEffect(m, mm, i + 2, j + 2, n +1);
      printf("BOTTOM-RIGHT\n");
    }
    
    // Try to fill the BOTTOM
    if((i + 3) < mm && m[i + 3][j] == 0){
      findFirstSolutionSideEffect(m, mm, i + 3, j, n + 1);
      printf("BOTTOM\n");
    }
    
    // Try to fill the BOTTOM-LEFT
    if((i + 2) < mm && (j - 2) >= 0 && m[i + 2][j - 2] == 0){
      findFirstSolutionSideEffect(m, mm, i + 2, j - 2, n + 1);
    }
    
    // Try to fill the LEFT
    if((j - 3) >= 0 && m[i][j - 3] == 0){
      findFirstSolutionSideEffect(m, mm, i, j - 3, n + 1);      
    }
    
    // Try to fill the TOP-LEFT
    if((i - 2) >= 0 && (j - 2) >= 0 && m[i - 2][j - 2] == 0){
      findFirstSolutionSideEffect(m, mm, i - 2, j - 2, n + 1);
    }
    
    // If no try is available just remove the number
    if(!isFilled(m, mm)) m[i][j] = 0;
    if(isFilled(m, mm)) {
      printMatrix(m,mm);
      m[i][j] = 0;
    }
}
