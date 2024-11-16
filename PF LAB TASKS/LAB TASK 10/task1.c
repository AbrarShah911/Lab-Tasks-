#include <stdio.h>


typedef struct Box Box; //A nested box in C for seeing the box will have a weight or a nested box
int CalculateWeight(Box *box);
typedef struct  
{
    int is_weight; //If the is_wight variable is 1 then the box contains a weight value else it contains a nested box 
    union //A union is a data structure like struct but in a union it only holds the memory allocation for the greatest member inside the union and shares that memory with all the different members of the union.
    {
        int weight;
        Box *nested_box;
    }data;
}Item;

struct Box
{
    Item *items;
    int item_count;
};

int main(){

    //setting an example box and an inner box so that I can test the function.
    Box inner_box = {
        (Item[]){
            {.is_weight = 1, .data.weight = 3},
            {.is_weight = 1, .data.weight = 2}
        },
        2
    };

    Box main_box = {
        (Item[]){
            {.is_weight = 1, .data.weight = 5},
            {.is_weight = 0, .data.nested_box = &inner_box},
            {.is_weight = 1, .data.weight = 7}
        },
        3
    };

    int total_weight = CalculateWeight(&main_box);
    printf("Total Weight: %d\n", total_weight);

    return 0;
}

int CalculateWeight(Box *box){

    int totalWeight = 0;

    for(int i = 0; i <box->item_count;i++){
        if(box->items[i].is_weight){
            totalWeight += box->items[i].is_weight;
        }else{
            totalWeight += CalculateWeight(box->items[i].data.nested_box);
        }
    }
    return totalWeight;
}