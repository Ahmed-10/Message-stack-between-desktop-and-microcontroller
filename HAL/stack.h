/*
 * stack.h
 *
 * Created: 20/01/04 1:59:30 AM
 *  Author: ahmed
 */ 


#ifndef STACK_H_
#define STACK_H_

#include "avr/io.h"

#define StackEntry	uint8_t
#define MAXSTACK	3
typedef struct stack{
	uint8_t top;
	StackEntry entry[MAXSTACK];
} Stack;

void Push(StackEntry e, Stack* ps);
void Pop(StackEntry* pe, Stack* ps);
int	StackEmpty(Stack* ps);
int	StackFull(Stack* ps);
void CreateStack(Stack *ps);
int	StackSize(Stack* ps);
void ClearStack(Stack* ps);
void StackTop(StackEntry* pe, Stack* ps);


#endif /* STACK_H_ */