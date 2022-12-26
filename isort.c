/*
 *  Software Systems Course Assignment 3
 *  Copyright (C) 2022  Roy Simanovich

 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.

 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.

 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <stdio.h>

/* Sets the array size. */
#define ARR_SIZE 50

void shift_element(int* arr, int i);

void insertion_sort(int* arr, int len);

int main() {
    int arr[ARR_SIZE] = { 0 };

    for (int i = 0; i < ARR_SIZE; ++i)
        scanf("%d", &(*(arr+i)));

    insertion_sort(arr, ARR_SIZE);

    for (int i = 0; i < ARR_SIZE; ++i)
        printf("%d%c", *(arr+i), ((i == (ARR_SIZE - 1)) ? '\n':','));

    return 0;
}

/*
 * Function:  shift_element
 * --------------------
 * Shifts i elements of an array one cell to the right
 *
 *  arr: starting pointer address of the first cell we want to move.
 *
 *  i: number of elements to move.
 */
void shift_element(int* arr, int i) {
    for (int item = i; item > 0; --item)
        *(arr + item) = *(arr + item - 1);
}

/*
 * Function:  insertion_sort
 * --------------------
 * Makes an insertion sort to an array.
 *
 *  arr: starting pointer address of the array.
 *
 *  len: the array's size.
 */
void insertion_sort(int* arr, int len) {
    for (int i = 1; i < len; ++i)
    {
        int key = *(arr + i), j = (i - 1);

        while (j >= 0 && *(arr + j) > key)
            --j;

        shift_element((arr + j), (i - j));

        *(arr + j + 1) = key;
    }
}
