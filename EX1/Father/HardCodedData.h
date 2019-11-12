#pragma once
#ifndef HARD_CODE_H
#define HARD_CODE_H
// Defines ---------------------------------------------------------------------

#define DEBUG 
#define MAX_INPUT_LINE_LEN 256
#define VALID_NUM_ARGUMENTS 2
#define _CRT_SECURE_NO_WARNINGS

// #define NULL_TERMINATED \0

// Macros -------------------------------------------------------------------
#ifdef DEBUG  
#define DEBUG_PRINT printf
#else
#define DEBUG_PRINT
#endif


// Constants -------------------------------------------------------------------
static const int STATUS_CODE_SUCCESS = 0;
static const int STATUS_CODE_FAILURE = -1;
static const int STATUS_CODE_STACK_FAILURE = -2;


// Typedef -------------------------------------------------------------------

typedef enum { FALSE, TRUE } boolean;
typedef enum { ERROR = 0, OPERATOR, VALUE, EOLN } tokenType;

typedef unsigned int uint;

#endif