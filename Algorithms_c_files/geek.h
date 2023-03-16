#ifndef GEEK_H_INCLUDED
#define GEEK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdarg.h>

#define T char
#define true 1 == 1
#define false 1 != 1
typedef int boolean;

typedef struct OneLinkNode {
    int dat;
    struct OneLinkNode *next;
} OneLinkNode;

typedef struct {
    OneLinkNode *head;
    int size;
} OneLinkList;

typedef struct TwoLinkNode {
    int dat;
    struct TwoLinkNode *next;
    struct TwoLinkNode *prev;
} TwoLinkNode;

typedef struct {
    struct TwoLinkNode *head;
    struct TwoLinkNode *tail;
    int size;
} TwoLinkList;

/*
 * Function, that swaps values of two integer variables
 *
 * Parameters:
 * a, b - pointer to a single integer variable
 */
void swapInt(int *a, int *b);
void swapDbl(double *a, double *b);

/*
 * Function, that prints any one-dimension integer array
 * of a given size with a given offset
 *
 * Parameters:
 * array - pointer to an integer array
 * size - number of first N printed items in a given array, where N = size
 * offset - number of symbols that should be taken by a value between commas,
 *          and filled with whitespaces, if given value contains less characters.
 */
void printIntArray(int* array, int size, int offset);
void printDblArray(double* array, int size, int crop);

/*
 * Function, that fills any one-dimension integer array
 * of a given size with random numbers (generated by stdlib#rand)
 *
 * Parameters:
 * array - pointer to an integer array
 * size - number of first N filled items in a given array, where N = size
 * border - limit (modulus) for a randomly generated value excluding itself
 *      (ex. 100 will give numbers 0-99)
 */
void fillIntRandom(int* array, int size, int border);
void clearIntArray(int* arr, const int size);

/*
 * Function that gets a value from a dynamically initialized int** array
 *
 * Return:
 * int value
 *
 * Parameters:
 * array - int** pointer to an array
 * row, col - size of printed array as if array[row][col]
 */
int get2dInt(int** array, int row, int col);

/*
 * Function that sets a value from a dynamically initialized int** array
 *
 * Parameters:
 * array - int** pointer to an array
 * row, col - size of printed array as if array[row][col]
 * value - value to be written to an array cell
 */
void set2dInt(int** array, int row, int col, int value);

/*
 * Function, that initializes a dynamic
 * two-dimensional int** array of a given size
 *
 * Return:
 * int** pointer
 *
 * Parameters:
 * array - int** pointer to an array that is going to be initialized
 * row, col - size parameters as if array[row][col]
 */
int** init2dIntArray(int** array, int row, int col);

/*
 * Function, that prints any two-dimension integer pointer array
 * of a given size with a given offset
 *
 * Parameters:
 * array - int** pointer to an array
 * row, col - size of printed array as if array[row][col]
 * offset - number of symbols that should be taken by a value between commas,
 *          and filled with whitespaces, if given value contains less characters.
 */
void print2dIntArray(int** array, int row, int col, int offset);

/*
 * Function, that fills any two-dimension integer pointer array
 * of a given size with a multiplication table
 *
 * Parameters:
 * array - int** pointer to an array
 * row, col - size of printed array as if array[row][col]
 */
void fill2dIntArray(int** array, int row, int col);
void setLineValues(int** matrix, int cols, int row, ...);

/*
 * Function, that sorts an integer array
 * of a given size with an insertion sort (fastest of simple)
 *
 * Parameters:
 * array - int* pointer to an array
 * size - size of a sorted array
 */
void sortIntInserts(int* array, int size);

void initOneLinkList(OneLinkList *lst);
void printOneLinkIntNode(OneLinkNode *n);
void printOneLinkIntList(OneLinkList *lst);
void printOneLinkCharNode(OneLinkNode *n);
void printOneLinkCharList(OneLinkList *stack);
boolean pushOneLinkStack(OneLinkList *stack, T value);
T popOneLinkStack(OneLinkList *stack);

void initTwoLinkList(TwoLinkList *lst);
void printTwoLinkIntNode(TwoLinkNode *n);
void printTwoLinkIntList(TwoLinkList *lst);
void printTwoLinkCharNode(TwoLinkNode *n);
void printTwoLinkCharList(TwoLinkList *lst);
boolean TwoLinkEnqueue(TwoLinkList *queue, T value);
T TwoLinkDequeue(TwoLinkList *queue);

void printCyclicIntList(OneLinkList *lst);

//BinTreeIntNode* treeInsert(BinTreeIntNode *t, int data);
//void printBinTree(BinTreeIntNode *root);
//boolean treeNodeDelete(BinTreeIntNode *root, int key);


#endif // GEEK_H_INCLUDED
