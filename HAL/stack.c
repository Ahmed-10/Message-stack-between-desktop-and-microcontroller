/*
 * stack.c
 *
 * Created: 20/01/04 1:59:18 AM
 *  Author: ahmed
 */ 

#include "stack.h"

void Push(StackEntry e, Stack* ps){
	ps->entry[ps->top++] = e;
}

void Pop(StackEntry* pe, Stack* ps){
	*pe = ps->entry[--ps->top];
}

int	StackEmpty(Stack* ps){
	return !(ps->top);
}

int	StackFull(Stack* ps){
	return (ps->top >= MAXSTACK);
}

void CreateStack(Stack *ps){
	ps->top = 0;
}

int	StackSize(Stack* ps){
	return ps->top;
}

void ClearStack(Stack* ps){
	ps->top = 0;
}

void StackTop(StackEntry* pe, Stack* ps){
	*pe = ps->entry[ps->top - 1];
}
