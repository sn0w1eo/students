#include "stdio.h"
#include "stdlib.h"
#include "String.h"

typedef unsigned char string;

int busy;

enum boolean{
	true=0,
	false
};

enum sort {
	asc = 0,
	desc
};

typedef struct {
	 int size;
	 double weight;
	 string*  name;
	 size_t price;
	 
}product;

/*Memory*/

product* initMemory(product* base);
product* reallocMemory(product* base);
void freeMemory(product* base);


/*set*/

void setName(product* , string* name);
void setPrice(product* , int* price);
void setWeight(product* , double weight);
void setSize(product*, int size);

/*get*/

string getName(product* base);
int    getPrice(product* base);
double getWeignt(product* base);
product* getAdree(product* base);
int getSize(product strg);


product* addProduct(product* base, string* name,int price, double weight);

/*Sort*/

void sortByName(product*, int);
void sortByPrice(product* base, int in_order);
void sortByWeight(product* base, int in_order);
int namesrt_a(const void* a, const void* b);
int namesrt_d(const void* a, const void* b);
int pricesrt_a(const void* a, const void* b);
int pricesrt_b(const void* a, const void* b);
int weightssrt_a(const void* a, const void* b);

/*Other*/
void show(product* base);
int srhFree(product* base);


int main() {
	product* base = initMemory(5);
	//setWeight(base, 25.4);
	base = addProduct(base, "Cement", 6, 50.3);
	base = addProduct(base, "Flour", 10, 25.4);
	base = addProduct(base, "Crushed stone", 4, 100.15);
	
	printf("Original:\n");
	show(base);

	printf("\nSort by name (asc):\n");
	sortByName(base, asc);
	show(base);

	printf("\nSort by price (desc):\n");
	sortByPrice(base, desc);
	show(base);

	printf("\nSort by weight(asc):\n");
	sortByWeight(base, asc);

	show(base);

	printf("\n");
	freeMemory(base);
	
}

/*Memory*/
product* initMemory(size_t size) {
	
	product* base = NULL;
	if (base == NULL) {
		base = (product*)calloc(size, sizeof(product));
		base->size = size;
		if (base == NULL) {
			return base;
		}
	}
	setSize(base,size);
	return base;
}

product* reallocMemory(product* base) {
	int size = getSize(*base) * 2;
	setSize(base, size);
	base = realloc(base, size * sizeof(base));;
	for (int i = size / 2; i < size; i++) {
		setName(&base[i].name, NULL);
		setPrice(&base[i].price, NULL);
		setSize(&base[i].size, size);
	}
	return base;
}

void freeMemory(product* base) {
	for (int i = 0; i < busy; i++) {
		if (base[i].name != NULL) {
			free(base[i].name);
		}
	}
	free(base);
}


/*Sets*/

void setName(product* base, string* name) {
	base->name = _strdup(name);	
}

void setSize(product* base, int size) {
	base->size = size;
}

void setPrice(product* base, int price) {
	base->price = price;
}

void setWeight(product* base, double weight) {
	base->weight = weight;
}


/*Gets*/

string getName(product base) {
	return base.name;
}

int    getPrice(product base) {
	return base.price;
}

int getSize(product base) {
	return base.size;
}

double getWeight(product base) {
	return base.weight;
}

product* getAdress(product* base) {
	int size =base->size;
	int i = 0;
	for (; i < size; i++) {
		if (getName(base[i]) == NULL) {
			break;
		}
	}
	return &base[i];
}

/*add*/

int srhFree(product* base) {
	int size = base->size;
	for (int i = 0; i < size; i++) {
		if (base[i].name == NULL && base[i].price == NULL) {
			return true;
		}
	}
	return false;
}

product* addProduct(product* base, string* name, int price, double weight) {
	int size = base[0].size;
	product* new = NULL;
	switch (srhFree(base))
	{
	case true:
		new = getAdress(base);
		break;
	case false:
		base = reallocMemory(base);
		new = getAdress(base);
		break;
	}
	setName(new, name);
	setPrice(new, price);
	setWeight(new, weight);
	setSize(new, size);
	busy++;
	
	
	return base;
}

/*Sort*/
int namesrt_a(const void* a, const void* b) {
	const product* ptr1 = a;
	const product* ptr2 = b;
	
	return strcmp(ptr1->name, ptr2->name);

}

int namesrt_d(const void* a, const void* b) {
	const product* ptr1 = a;
	const product* ptr2 = b;
	return strcmp( ptr2->name,ptr1->name);
}

int pricesrt_a(const void* a, const void* b) {
	const product* ptr1 = a;
	const product* ptr2 = b;
	return ptr1->price - ptr2->price;
}

int pricesrt_d(const void* a, const void* b) {
	const product* ptr1 = a;
	const product* ptr2 = b;
	return  ptr2->price - ptr1->price;
}

int weightssrt_a(const void* a, const void* b) {
	const product* ptr1 = a;
	const product* ptr2 = b;
	return ptr1->weight - ptr2->weight;
}


void sortByPrice(product* base, int in_order) {
	if (in_order == asc) {
		qsort(base, busy, sizeof(product), pricesrt_a);
	}
	else if (in_order == desc) {
		qsort(base, busy, sizeof(product), pricesrt_d);
	}
}

void sortByName(product* base, int in_order) {
	
	if (in_order == asc) {
		qsort(base, busy, sizeof(product), namesrt_a);
	}
	else if (in_order == desc) {
		qsort(base, busy, sizeof(product), namesrt_d);
	}
}

void sortByWeight(product* base, int in_order) {
	if (in_order == asc) {
		qsort(base, busy, sizeof(product), weightssrt_a);
	}
	else if (in_order == desc) {
		qsort(base, busy, sizeof(product), pricesrt_d);
	}
}



/*Other*/
void show(product* base) {
	
	for (int i = 0; i < busy; i++) {
		if (base[i].name != NULL) {
			printf("Name: %20s      Price: %5d $     Weight:%.2f kg\n", base[i].name, base[i].price, base[i].weight);
		}
		else {
			break;
		}
	}
}