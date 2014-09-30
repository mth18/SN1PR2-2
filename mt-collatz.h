/*
	mt-collatz.h
	by David Hunt & Mark Humes
*/

#ifndef MT_COLLATZ_H
#define MT_COLLATZ_H

typedef struct val
{
	int * number; 		//the current number
	int szHist;			//the size of the histogram
	int * histogram;	//the actual histogram
}val;

int isEven(int num);

int isOdd(int num);

int collatz(int num, int runs);

int evenNumFunction(int num);

int oddNumFunction(int num);

void startRun(int num, int threads);

void * collatzThread(void * values);

void creatingThreads(int num, int threadNums, val * values);

void slow(int n);

val * creatingVal(int numb);

void * destroyVal(val * values);

#endif