/*
    Project: Bank_Database
    Author: Mohamed Maged
*/

#include "Bank_Database.h"
int counter=0;
int temp_id; //to store entered id while adding new client, to check if it is already existed or not
//Function to check if a client id exists or not
int id_check(client* ptr,int id)
{
    int exist = -1;
    if(ptr=='\0')
    {
        exist = 1;
    }
    while(ptr!='\0')
    {
        if(ptr->id == id)
        {
            exist = 2;
            break;
        }
        ptr = ptr->next;
    }
    return exist;
}
// Function to add new client
void add_new_client(client** ptr)
{
    int i = 0;
    client* temp;
    temp = (client*) malloc(sizeof(client));
    printf("Please enter the name of new client: ");
    fflush(stdin);
    gets(temp->name);
    Label: printf("Please enter the cash of the new client: ");
    scanf("%lf",&(temp->cash));
    // You have three tries to enter a positive value to the cash
    if(temp->cash < 0)
    {
        i++;
        if(i<3)
        {
            printf("The cash money should be greater than or equal to zero\n");
            goto Label;
        }
        printf("Try again later!\n");
    }
    L1: printf("please enter id of the new client: ");
    scanf("%i",&temp_id);
    //check if the entered id is already taken
    if(id_check(*ptr,temp_id) == 2)
    {
        printf("this id is already token!\n");
        goto L1;
    }
    //if the entered id is not exist save it in temp->id
    temp->id = temp_id;
    temp->next = *ptr;
    *ptr = temp;
    counter++;
    printf("\n");
}
// Function to edit a client data
void edit_client_information(client* ptr,int id)
{
    if(ptr == NULL)
    {
        printf("There are no clients to edit");
        return;
    }
    while (ptr!='/0')
    {
        // loop to get the desired client id
        if(ptr->id == id)
        {
            printf("Please enter the name of the client: ");
            fflush(stdin);
            gets(ptr->name);
            Label:printf("Please enter the cash of the client: ");
            scanf("%lf",&(ptr->cash));
            // Money should be a positive value or zero
            if(ptr->cash < 0)
            {
                printf("The cash money should be greater than or equal to zero\n");
                goto Label;
            }
            printf("please enter id of the client: ");
            scanf("%i",&(ptr->id));
            break;
        }
        ptr = ptr->next;
    }
    printf("\n");
}
// Function to transfer money between to clients
void transfer_cash(client* ptr,int from_client_id,int to_client_id,double money)
{
    client* temp = ptr;
    //Check if there are no clients in the bank
    if(ptr == '/0')
    {
        printf("There are no clients to transfer the money between them!");
        return;
    }
    //Check if there are only one client in the bank
    if(ptr->next == '\0')
    {
        printf("There are only one client, so the money can not be transfered!");
        return;
    }
    while(ptr != "\0")
    {
        //loop to get the desired source id
        if(ptr->id == from_client_id)
        {
            //If the amount of transfered money > client money, the transformation process can't be done
            if(money > ptr->cash)
            {
                printf("The amount of money you want to transfer is greater than the client money");
                break;
            }
            ptr->cash = ptr->cash - money;
            break;
        }
        ptr = ptr->next;
    }
    //loop to get the desired destination id
    while(temp != '\0')
    {
        if(temp->id == to_client_id)
        {
            temp->cash = temp->cash + money;
            break;
        }
        temp = temp->next;
    }
    printf("\n");
}
// Function to print a client information
void print_client_data(client* ptr, int id)
{
    //Check if there are no clients
    if(ptr == '\0')
    {
        printf("There are to clients to print!");
        return;
    }
    //If there are client loop until the desired id is found then print it's information
    while(ptr != '\0')
    {
        if(ptr->id == id)
        {
            printf("Clint name: %s\n",ptr->name);
            printf("Client id: %i\n",ptr->id);
            printf("client cash: %0.2f\n",ptr->cash);
            break;
        }
        ptr = ptr->next;
    }
    printf("\n");
}
//Function to remove a client data
void remove_client_data(client** head_ptr,client* ptr,int id)
{
    int i = 0;
    client* temp;
    if(ptr == '\0')
    {
        printf("There are no clients to delete!\n");
        return;
    }
    if(ptr->next == '\0')
    {
        *head_ptr = '\0';
        free(ptr);
        counter--;
        return;
    }
    for(int j=0; j<id-1; j++)
    {
        if(ptr->next == '\0')
        {
            printf("There are no clients have the same id!");
            break;
        }
        if(ptr->id == id)
        {
            break;
        }
        ptr = ptr->next;
        i++;
    }
    // check if the client we want to delete is the first client
    if(i == 0)
    {
        *head_ptr = (*head_ptr)->next;
        free(ptr);
        counter--;
        return;
    }
    // This pointer has the address of the node we want to delete
    temp = ptr->next;
    ptr->next = temp->next;
    free(temp);
    counter--;
}
// Function to check balance
void check_balance(client* ptr,int id)
{
    if(ptr=='\0')
    {
        printf("There are no clients!\n");
        return;
    }
    while(ptr!='\0')
    {
        if(ptr->id == id)
        {
            printf("The client balance is: %0.2f\n",ptr->cash);
            break;
        }
        ptr = ptr->next;
    }
    printf("\n");
}
// Function to withdraw money
void withdraw(client* ptr, int id, double money)
{
    // money must be a positive value
    if(money<0)
    {
        printf("Money mush have a positive value!\n");
        return;
    }
    else
    {
        if(ptr=='\0')
        {
            printf("There are no clients!\n");
            return;
        }
        while(ptr!='\0')
        {
            if(ptr->id == id)
            {
                if(ptr->cash < money)
                {
                    printf("Insufficient balance!\n");
                    break;
                }
                ptr->cash = ptr->cash - money;
                printf("the balance of client of id %i now is: %0.2f\n",id,ptr->cash);
            }
            ptr = ptr->next;
        }
    }
    printf("\n");
}
// Function to deposit money
void deposit(client* ptr, int id, double money)
{
    // money must be a positive value
    if(money<0)
    {
        printf("Money mush have a positive value!\n");
        return;
    }
    else
    {
        if(ptr=='\0')
        {
            printf("There are no clients!\n");
            return;
        }
        while(ptr!='\0')
        {
            if(ptr->id == id)
            {
                ptr->cash = ptr->cash + money;
                printf("the balance of client of id %i now is: %0.2f\n",id,ptr->cash);
                break;
            }
            ptr = ptr->next;
        }
    }
    printf("\n");
}
// Function to get number of clients
int clients_no(client* ptr)
{
    if(ptr=='\0')
    {
        printf("There are no clients!\n");
    }
    else
    {
        return counter;
    }
}






