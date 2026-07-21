/*  Exercise 1 – Credit Card Transactions

## Description

The objective of this exercise is to practice working with **structures (struct)**, arrays, loops, and conditional statements in C++.

The program reads **N** transaction records from the standard input. Each transaction contains an identification number, payment amount, commission, and payment type (debit or credit card).

The program prints the identification number and the total amount (payment amount + commission) for every transaction paid with a **credit card**. If no credit card transactions are found, the program prints an appropriate message.

## Topics Covered

- Structures (`struct`)
- Arrays
- Standard Input / Output
- Loops
- Conditional Statements
- Data Processing

# Задача 1 – Трансакции со кредитна картичка

## Опис

Целта на оваа задача е практична примена на **структури (struct)**, низи, циклуси и условни конструкции во програмскиот јазик C++.

Програмата внесува **N** трансакции од стандарден влез. Секоја трансакција содржи идентификациски број, платена сума, провизија и тип на плаќање (дебитна или кредитна картичка).

Потребно е да се испечатат идентификацискиот број и вкупната сума (платена сума + провизија) за сите трансакции кои се извршени со **кредитна картичка**. Доколку нема трансакции платени со кредитна картичка, се печати соодветна порака.

## Теми

- Структури (`struct`)
- Низи
- Стандарден влез и излез
- Циклуси
- Условни конструкции
- Обработка на податоци
*/


#include <iostream>
using namespace std;

struct Transaction{
    int id;
    int sum;
    int commission;
    int type;
};
int main(){
    int N;
    cin>> N;


    Transaction transactions[100];
    bool hasCreditCardTransaction = false;

    for(int i=0; i<N ;i++){
        cin>> transactions[i].id;
        cin>> transactions[i].sum;
        cin>> transactions[i].commission;
        cin>> transactions[i].type;
    }

    for(int i=0; i<N ;i++){
        if(transactions[i].type == 1){
            cout<< transactions[i].id<<" "
            << transactions[i].sum + transactions[i].commission <<endl;

            hasCreditCardTransaction = true;
        }
    }  
    
    if(!hasCreditCardTransaction){
        cout<<"No credit card transaction";
    }
    
    return 0;
}

