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
 * @file main.c
 * @brief This file is to be used for the final assessment.
 *
 * Simple main() function that can switch which course deliverable we wish to call.
 *
 * @author Reeshav Rout
 * @date 09 October 2025
 *
 */

#include "../include/common/course1.h"

int main(void){

  #ifdef COURSE1
    course1();
  #endif
}
