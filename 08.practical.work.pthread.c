#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#define BUFFER_SIZE 10

typedef struct {
	char type;  // 0=fried chicken, 1=French fries
	int amount;  // pieces or weight
	char unit;  // 0=piece, 1=gram
} item;

item buffer[BUFFER_SIZE];
int first = 0;
int last = 0;

void produce(item *i) {
	while ((first + 1) % BUFFER_SIZE == last) {
    // do nothing -- no free buffer item
 	}
   	memcpy(&buffer[first], i, sizeof(item));//copy block data form  a source code 
	first = (first + 1) % BUFFER_SIZE;
}

item *consume() {
	item *i = malloc(sizeof(item));
 	while (first == last) {
	// do nothing -- nothing to consume
	}
	memcpy(i, &buffer[last], sizeof(item));
	last = (last + 1) % BUFFER_SIZE;
return i;
}

item *initItem(char type, int amount, char unit) {
	item *i = malloc(sizeof(item));
	i->amount;
	i->type;
	i->unit;
	return i;
}

logvalue(){
	printf(" first is %d, last is %d\n",first,last );
}

void *threadProducer(void *param) {
	produce(initItem('1',10,'1'));
	produce(initItem('1',8,'1'));
	produce(initItem('1',6,'1'));

}

void *threadConsumer(void *param) {
	consume(initItem('0',3,'0'));
	consume(initItem('0',2,'0'));

}

int main(){
	pthread_t tid1,tid2;
	pthread_create(&tid1,NULL,threadProducer,NULL);
	pthread_create(&tid2,NULL,threadConsumer,NULL);
    
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);

    logvalue();

  return 0; 
}