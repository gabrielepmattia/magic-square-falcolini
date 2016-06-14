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
#include <stdlib.h>
#include <stdio.h>

Number** createEmptyMatrix(int n);
Number** cloneMatrix(Number** m, int n);
void freeMatrix(Number** m, int n);
void printMatrix(Number** m, int n);
