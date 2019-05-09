#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#define BUFFER_SIZE 10

typedef struct {
    char type; // 0=fried chicken, 1=French fries
    int amount; // pieces or weight
    char unit; // 0=piece, 1=gram
} item;

item buffer[BUFFER_SIZE];
int first = 0;
int last = 0 ;

void produce(item *i) {
    while ((first + 1) % BUFFER_SIZE == last) {
        // do nothing -- no free buffer item
    }
    memcpy(&buffer[first], i, sizeof(item));
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
	i->amount=amount;
	i->type=type;
	i->unit=unit;
	return i;
}



int main() {
    // Item declaration
    item *i1=initItem('1',4,'1');
    item *i2=initItem('0',2,'0');
    
    // print item list 
    printf("Item 1 Type = %c   Amount = %d    Unit = %c\n", i1->type, i1->amount, i1->unit);
    printf("\nItem 2 Type = %c   Amount = %d    Unit = %c\n", i2->type, i2->amount, i2->unit);


    printf("\nInitial value: first = %d\tlast = %d\n", first, last);

    produce(&i1); // produce item 1
    printf("\nAfter producing item 1:  first = %d    last = %d\n", first, last);

    produce(&i2); // produce item 2
    printf("\nAfter producing item 2:  first = %d    last = %d\n", first, last);

    item *i3 = consume(); // consume an item
    printf("\nAfter consuming an item: first = %d    last = %d\n", first, last);
}
