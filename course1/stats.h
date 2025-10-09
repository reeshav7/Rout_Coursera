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
 * Header File which contains all the function declarations.
 * @file stat.h 
 * @brief Header file which contains declaration for the functions used in stat.c
 *
 * Declaration of the functions that computes and display statistics(mean, median, maximum, minimum) and it also has the utility function to print and sort the array.
 *
 * @author Reeshav Rout
 * @date 3 October 2025
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* 
* @brief Prints the elements of the array.
* This function takes the array of unsigned character and its length and prints the array elements. 
* @param arr --> Pointer to the array.
* @param len --> length of the array.
*/
void print_array(unsigned char *arr, unsigned int len);

/**
 * @brief  Prints the statistical results.
 *
 * This function prints the minimum, maximum, mean and median of the test array.
 *
 * @param min --> Minimum value in the array.
 * @param max --> Maximum value in the array.
 * @param mean --> Mean value of the array.
 * @param median --> Median value of the dataset.
 */
 void print_statistics(unsigned char min, unsigned char max, float mean, float median);
 
 /**
 * @brief Finds the maximum value in an array
 *
 * This function takes an array of unsigned characters and returns
 * the largest element.
 *
 * @param arr --> Pointer to the array
 * @param len --> Number of elements in the array
 *
 * @return Maximum element in the array
 */
unsigned char find_maximum(unsigned char *arr, unsigned int length);

/**
 * @brief Finds the minimum value in an array
 *
 * This function takes an array of unsigned characters and returns
 * the smallest element.
 *
 * @param arr --> Pointer to the array
 * @param len --> Number of elements in the array
 *
 * @return Minimum element in the array
 */
unsigned char find_minimum(unsigned char *arr, unsigned int length);

/**
 * @brief Calculates the mean of the array
 *
 * This function sums the elements of the array and divides
 * by the length to compute the mean.
 *
 * @param arr --> Pointer to the array
 * @param length --> Number of elements in the array
 *
 * @return Mean value as a float
 */
float find_mean(unsigned char *arr, unsigned int length);

/**
 * @brief Calculates the median of the array
 *
 * This function assumes the array is already sorted in descending order.
 * For even length arrays, the median is the average of the two middle values.
 *
 * @param arr --> Pointer to the array
 * @param length --> Number of elements in the array
 *
 * @return Median value as a float
 */
float find_median(unsigned char *arr, unsigned int length);

/**
 * @brief Sorts the array in descending order
 *
 * This function rearranges the elements of the array from largest
 * to smallest.
 *
 * @param arr --> Pointer to the array
 * @param length --> Number of elements in the array
 */
void sort_array(unsigned char *arr, unsigned int length);
 


#endif /* __STATS_H__ */
