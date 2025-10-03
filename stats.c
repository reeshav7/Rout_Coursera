/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stat.c 
 * @brief Performs basic statistical analysis on the array of data.
 *
 * This program computes minimum, maximum, mean, and median of the test dataset. It also sort and prints the test dataset.
 *
 * @author Reeshav Rout
 * @date 3 October 2025
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

/* Function Declaration of all the required functions used*/

void print_array(unsigned char *arr, unsigned int len);
void print_statistics(unsigned char min, unsigned char max, float mean, float median);
unsigned char find_maximum(unsigned char *arr, unsigned int len);
unsigned char find_minimum(unsigned char *arr, unsigned int len);
float find_mean(unsigned char *arr, unsigned int len);
float find_median(unsigned char *arr, unsigned int len);
void sort_array(unsigned char *arr, unsigned int len);

void main() {
  
  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};
  
  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
  
  /* Printing the original array. */
  printf("Original Array:\n ");
  print_array(test, SIZE);
  
  /* Sorting the array */
  sort_array(test, SIZE);
  
  /* Computing the statistics */
  unsigned char min = find_minimum(test, SIZE);
  unsigned char max = find_maximum(test, SIZE);
  float mean = find_mean(test, SIZE);
  float median = find_median(test, SIZE);
  
  /* Printing the sorted array */
  printf("\nSorted Array in Descending Order: \n");
  print_array(test, SIZE);
  
  /* Print statistics */
  print_statistics(min, max, mean, median);
  
}

/* Function Implementation */

/* Print Array */
void print_array(unsigned char *arr, unsigned int len) 
{
  for (unsigned int i = 0; i < len; i++) 
  {
    printf("%3d ", arr[i]);
    if ((i+1) % 10 == 0) printf("\n");
  }
}


/* Print Statistics */
void print_statistics(unsigned char min, unsigned char max, float mean, float median) 
{
  printf("\nStatistics:\n");
  printf("Minimum: %d\n", min);
  printf("Maximum: %d\n", max);
  printf("Mean   : %.2f\n", mean);
  printf("Median : %.2f\n", median);
}

/* Finding Maximum */
unsigned char find_maximum(unsigned char *arr, unsigned int len) 
{
  unsigned char max = arr[0];
  for (unsigned int i = 1; i < len; i++) 
  {
    if (arr[i] > max) max = arr[i];
  }
  return max;
}

/* Finding Minimum */
unsigned char find_minimum(unsigned char *arr, unsigned int len) 
{
  unsigned char min = arr[0];
  for (unsigned int i = 1; i < len; i++) 
  {
    if (arr[i] < min) min = arr[i];
  }
  return min;
}

/* Finding Mean */
float find_mean(unsigned char *arr, unsigned int len) 
{
  unsigned int sum = 0;
  for (unsigned int i = 0; i < len; i++) 
  {
    sum += arr[i];
  }
  return (float)sum / len;
}

/* Finding Median */
float find_median(unsigned char *arr, unsigned int len) 
{
  if (len % 2 == 0) 
  {
    return (arr[len/2 - 1] + arr[len/2]) / 2.0;
  } 
  else 
  {
    return arr[len/2];
  }
}

void sort_array(unsigned char *arr, unsigned int len) 
{
  for (unsigned int i = 0; i < len-1; i++) 
  {
    for (unsigned int j = i+1; j < len; j++) 
    {
      if (arr[i] < arr[j]) 
      {  // sort in descending order
        unsigned char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}
