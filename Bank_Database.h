#ifndef BANK_DATABASE_H_INCLUDED
#define BANK_DATABASE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct Bank_client
{
    char name[50];
    int id;
    double cash;
    struct Bank_client* next;
}client;
int id_check(client* ptr,int id);
void add_new_client(client** ptr);
void edit_client_information(client* ptr,int id);
void transfer_cash(client* ptr,int from_client_id,int to_client_id,double money);
void print_client_data(client* ptr, int id);
void remove_client_data(client** head_ptr,client* ptr,int id);
void check_balance(client* ptr,int id);
void withdraw(client* ptr, int id, double money);
void deposit(client* ptr, int id, double money);

#endif // BANK_DATABASE_H_INCLUDED
