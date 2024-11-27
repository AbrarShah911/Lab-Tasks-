#include <stdio.h>
#include <string.h>


typedef struct Invoice {
    char partNumber[20];  
    char partDescription[50]; 
    int quantity;          
    float pricePerItem;    
} Invoice;


float calculateInvoiceAmount(Invoice invoice) {

    if (invoice.quantity <= 0) {
        invoice.quantity = 0;
    }
    if (invoice.pricePerItem <= 0) {
        invoice.pricePerItem = 0;
    }
    
    return invoice.quantity * invoice.pricePerItem;
}


int main() {
 
    Invoice invoice2; 


    printf("Enter part number: ");
    scanf("%s", invoice2.partNumber);

    printf("Enter part description: ");
    getchar();  
    fgets(invoice2.partDescription, 50, stdin);
    invoice2.partDescription[strcspn(invoice2.partDescription, "\n")] = 0; 

    printf("Enter quantity: ");
    scanf("%d", &invoice2.quantity);

    printf("Enter price per item: ");
    scanf("%f", &invoice2.pricePerItem);

    printf("Invoice 2 Details:\n");
    printf("Part Number: %s\n", invoice2.partNumber);
    printf("Description: %s\n", invoice2.partDescription);
    printf("Quantity: %d\n", invoice2.quantity);
    printf("Price per item: $%.2f\n", invoice2.pricePerItem);
    printf("Total Invoice Amount: $%.2f\n", calculateInvoiceAmount(invoice2));

    return 0;
}
