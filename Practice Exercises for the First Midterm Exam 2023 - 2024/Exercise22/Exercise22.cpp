#include <stdio.h>
#include <string.h>

struct Product {
    char code[20];
    int price;
    int available;
};

struct Order {
    char name[15];
    Product products[10];
    int quantities[10];
    int n;
};

void printInvoice(Order order) {
    int i, j;
    int total = 0;

    printf("Faktura za %s\n", order.name);

    // Sort products alphabetically by code
    for (i = 0; i < order.n - 1; i++) {
        for (j = i + 1; j < order.n; j++) {
            if (strcmp(order.products[i].code,
                       order.products[j].code) > 0) {

                Product temp = order.products[i];
                order.products[i] = order.products[j];
                order.products[j] = temp;
            }
        }
    }

    // Check if all products are available
    for (i = 0; i < order.n; i++) {
        if (order.quantities[i] > order.products[i].available) {
            printf("Fakturata ne moze da se izgotvi\n");
            return;
        }
    }

    // Print invoice
    for (i = 0; i < order.n; i++) {
        int productTotal = order.products[i].price
                           * order.quantities[i];

        printf("%s %d %d %d\n",
               order.products[i].code,
               order.products[i].price,
               order.quantities[i],
               productTotal);

        order.products[i].available -= order.quantities[i];
        total += productTotal;
    }

    printf("Vkupnata suma na fakturata e %d\n", total);
}

int main() {

    Order order;

    // Enter the name of the person placing the order
    // Enter the number of ordered products

    scanf("%s", order.name);
    scanf("%d", &order.n);

    int i;

    // Enter information for each ordered product
    for (i = 0; i < order.n; ++i) {
        // Enter product code
        // Enter unit price
        // Enter number of available products in the warehouse

        scanf("%s", order.products[i].code);
        scanf("%d", &order.products[i].price);
        scanf("%d", &order.products[i].available);
    }

    // Enter the quantity ordered for each product
    int j;
    for (j = 0; j < order.n; ++j) {
        scanf("%d", &order.quantities[j]);
    }

    // Call the invoice function
    printInvoice(order);

    return 0;
}
