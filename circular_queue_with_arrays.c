#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int head,tail,size,count;
	//for int array on the heap to store values
    int* value;
  
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k) 
{
    MyCircularQueue* q = (MyCircularQueue*) malloc(sizeof(MyCircularQueue));
    q->size = k;
    q->value = (int*)malloc(sizeof(int)*q->size);
    q->head=-1;
    q->tail=-1;
    q->count=0;
    
    return q;
    
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {

    if(obj->count == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    
    if(obj->count == obj->size)
    {
        return true;
    }
    else
    {
        return false;
    }

}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    
    if(myCircularQueueIsFull(obj))
    {
        return false;
    }
	
    if(myCircularQueueIsEmpty(obj))
    {
        obj->head=0;
    }
	
    obj->tail = (obj->tail +1) % obj->size;
    obj->value[obj->tail] = value;
    obj->count++;
    
    return true;

}

bool myCircularQueueDeQueue(MyCircularQueue* obj){

    if(myCircularQueueIsEmpty(obj))
    {
        return false;
    }
	
	//if only one element left in the queue set head and tail to -1
    if(obj->head==obj->tail)
    {
        obj->head =-1;
        obj->tail =-1;
        obj->count--;
    }
    else
    {
        obj->head = (obj->head +1) % obj->size;
        obj->count--;   
    }
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) 
{
    
    if(myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    return obj->value[obj->head];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    
    if(myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    return obj->value[obj->tail];
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->value);
}

void main()
{
	MyCircularQueue* obj = myCircularQueueCreate(3);
	
	bool param_1 = myCircularQueueEnQueue(obj, 1);
	if(param_1)
	{
		printf("True\n");
	}
	else
	{
	    printf("False\n");
	}
	
	bool param_2 = myCircularQueueEnQueue(obj, 2);
	if(param_2)
	{
		printf("True\n");
	}
	else
	{
	    printf("False\n");
	}
	
	bool param_3 = myCircularQueueEnQueue(obj, 3);
	if(param_3)
	{
		printf("True\n");
	}
	else
	{
	    printf("False\n");
	}
	
	bool param_4 = myCircularQueueEnQueue(obj, 4);
	if(param_4)
	{
		printf("True\n");
	}
	else
	{
	    printf("False\n");
	}
	
	int param_5 = myCircularQueueRear(obj);
	printf("Rear value : %d\n", param_5);
 
	bool param_6 = myCircularQueueDeQueue(obj);
	if(param_6)
	{
		printf("True\n");
	}
	else
	{
	    printf("False\n");
	}
	
	int param_7 = myCircularQueueFront(obj);
	
	printf("Front value : %d\n", param_7);
	
	int param_8 = myCircularQueueRear(obj);
	printf("Rear value : %d\n", param_8);
 
	bool param_9 = myCircularQueueIsEmpty(obj);
	if(param_9)
	{
		printf("Queue is Empty\n");
	}
 
	bool param_10 = myCircularQueueIsFull(obj);
	if(param_10)
	{
		printf("Queue is Full\n");
	}
	
	myCircularQueueFree(obj);
}
