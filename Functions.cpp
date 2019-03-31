#include "global.h"
#include <iostream>

using namespace std;

void QfCreate( FQueue* q )
{
	q->pHead = q->pTail = NULL;
}

int QFEmpty( FQueue* q )
{
	return !( q->pHead );
}

void QFEnqueue( FQueue* q, int pInfo )
{
	qfifoItem* v = ( qfifoItem* )malloc( sizeof( qfifoItem ) );

	if ( v )   
	{
		v->nKey = pInfo;
		v->pNext = NULL; 
		
		if ( q->pTail ) q->pTail->pNext = v;
		else q->pHead = v;
		q->pTail = v;
	}
	else
	{
		perror( "ERROR: FIFO overflow!!\n" );
	}
}


int QFDequeue( FQueue* q )
{
	if ( q->pHead )
	{
		int deitem = q->pHead->nKey;
		qfifoItem* v = q->pHead;		//wskaznik pomocniczy
		q->pHead = q->pHead->pNext;

		if ( !( q->pHead ) ) q->pTail = NULL;
		
		free( v );

		return deitem;
	}
	else
	{
		perror( "ERROR: FIFO underflow!!\n" );
	}
}

//void QFClear( FQueue* q )
//{
//	while ( !QFEmpty( q ) )
//	{
//		
//	}
//}

void QFRemove( FQueue* q )
{
	while ( !QFEmpty( q ) )
	{
		QFDequeue( q );
	}
	q = NULL;
}

void QFPrint( FQueue* q )
{
	if ( !QFEmpty( q ))
	{
		qfifoItem* v = q->pHead;
		printf( "Kolejka sklada sie z nastepujacych elementow: \n" );
		while ( v )
		{
			printf( "%d ", v->nKey );
			v = v->pNext;
		}
		printf( "\n" );
	}
	else 
	{
		printf( "Kolejka jest pusta. \n" );
	}
}
