#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "item.h"

//function to add
void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index)
{
	item_list[index].price=price;

	item_list[index].sku=(char *)malloc(sizeof(char) *strlen(sku)+1);
	strcpy(item_list[index].sku, sku);

	item_list[index].category=(char *)malloc(sizeof(char) *strlen(category)+1);
	strcpy(item_list[index].category, category);
	
	item_list[index].name=(char *) malloc(sizeof(char) *strlen(name)+1);
	strcpy(item_list[index].name, name);

}

//function to free allocated memory
void free_items(Item *item_list, int size)
{
	for (int i=0; i<size; i++)
	{
		free(item_list[i].sku);
		free(item_list[i].category);
		free(item_list[i].name);
	}
	free(item_list);
}

//function to calculate the average
double average_price(Item *item_list, int size)
{
	double total=0;
	for(int i=0; i<size;i++)
	{
		total+=item_list[i].price;
	}
	return total/size;
}
//function to print all items
void print_items(Item *item_list, int size)
{int i;
	for(int i=0; i<size; i++){
		printf("#############");
		printf("item name=%s\n", item_list[i].name);
		printf("item sku=%s\n", item_list[i].sku);
		printf("item category=%s\n", item_list[i].category);
		printf("item price=%.2f\n", item_list[i].price);
	}
}
int main(int argc, char *argv[])
{
	int size=5;
//	int i;
	Item *item_list=(Item *) malloc (size*sizeof(Item));

	//add 5 different items
	add_item(item_list, 5.00, "19282", "breakfast", "resses's cereal", 0);
	add_item(item_list, 3.95, "79862", "dairy", "milk", 1);
	add_item(item_list, 2.49, "67575", "snacks", "cookies", 2);
	add_item(item_list, 1.99, "13456", "brunch", "salad", 3);
	add_item(item_list, 4.25, "56789", "dinner", "chicken tikka" ,4);

	//print all items
	print_items(item_list, size);

	//calculate and print average price
	double avg_price=average_price(item_list, size);
	printf("##############\n");
	printf("average price of items=%f\n", avg_price);

	//search for item by SKU
	if(argc>1)
	{
		char *search_sku=argv[1];
		int ct=0;

		//short circuit 
		while(ct<5 && strcmp(item_list[ct].sku, search_sku)!=0)
		{
			ct++;
		}

		if (ct<5)
		{
			printf("##########");
			printf("Item name=%s\n", item_list[ct].name);
			printf("item sku=%s\n", item_list[ct].sku);
			printf("Item category=%s\n", item_list[ct].category);
			printf("item price=%f\n", item_list[ct].price);
			printf("###########");
		}
		else{
			printf("\nItem with sku %s not found.\n", search_sku);
			}
}	//free the memory allocated for items
	free_items(item_list, size);
	return 0;
}


























