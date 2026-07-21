/*  # Exercise 3 – Shopping Cart Analysis

## Description

The objective of this exercise is to practice working with **structures**, arrays, nested loops, and functions in C/C++.

Two structures are defined:

- **Item**, which stores information about a product, including its name and price.
- **ShoppingCart**, which stores the shopping cart ID, the list of products, and the total number of products in the cart.

The program reads multiple shopping carts from the standard input. It calculates the average price of the cheapest product from each shopping cart and determines the most expensive product among all shopping carts.



# Задача 3 – Анализа на кошнички за купување

## Опис

Целта на оваа задача е практична примена на **структури**, низи, вгнездени циклуси и функции во програмскиот јазик C/C++.

Дефинирани се две структури:

- **Item**, која ги чува податоците за еден производ, односно неговото име и цена.
- **ShoppingCart**, која ги чува идентификацискиот број на кошничката, сите производи што се наоѓаат во неа и нивниот вкупен број.

Програмата внесува повеќе кошнички од стандарден влез. Потоа ја пресметува просечната цена на најевтиниот производ од секоја кошничка и го пронаоѓа најскапиот производ од сите кошнички.

 */

#include <iostream>
using namespace std;


// Storing product information
struct Item{
    char name[100];
    int price;
};

// Storing shopping cart information
struct ShoppingCart{
    int id;
    Item items[50];
    int numOfItems;
};

// Prints the average price of the cheapest item from each shopping cart
void printAveragePriceOfLowestItems(ShoppingCart carts[], int numOfCarts){

    double sum = 0;
    for(int i=0; i<numOfCarts; i++){

        int lowestPrice = carts[i].items[0].price;
        for(int j=1; j<carts[i].numOfItems; j++){
            if(carts[i].items[j].price < lowestPrice){
                lowestPrice = carts[i].items[j].price;
            }
        }
        sum += lowestPrice;
    }

    cout<<"Average: "<< fixed;
    cout.precision(2);
    cout<< sum / numOfCarts <<endl;
}

//Prints the most expensive product and its shopping cart ID
void printHighestPricedItem(ShoppingCart carts[], int numOfCarts){
    int highestPrice = -1;
    int cartIndex = -1;
    int itemIndex = -1;

    for(int i=0; i<numOfCarts; i++){
        for(int j=0; j<carts[i].numOfItems; j++){
            if(carts[i].items[j].price > highestPrice){

                highestPrice = carts[i].items[j].price;
                cartIndex = i;
                itemIndex = j;
            }
        }
    }

    cout<<"Shopping cart id: "
    << carts[cartIndex].id<<endl;

    cout<<"Product: "
    <<carts[cartIndex].items[itemIndex].name<<endl;
}
int main(){

    int numOfCarts;
    cin>>numOfCarts;

    ShoppingCart carts[10];

    for(int i=0; i<numOfCarts; i++){
        cin>> carts[i].id;
        cin>> carts[i].numOfItems;

        cin.ignore();

        for(int j=0; j<carts[i].numOfItems; j++){
            cin.getline(carts[i].items[j].name, 100);

            cin>> carts[i].items[j].price;
            cin.ignore();
        }
    }

    printAveragePriceOfLowestItems(carts, numOfCarts);
    printHighestPricedItem(carts, numOfCarts);

    return 0;
}
