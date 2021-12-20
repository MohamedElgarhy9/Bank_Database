#include "Bank_Database.h"
int main()
{
    char choice;
    int id;
    int id_trans_from;
    int id_trans_to;
    double trans_money;
    //We save the output of id_check function in one of these variables
    int checked_id1;
    int checked_id2;
    client* head = '\0';
    while(1)
    {
        printf("Please select one of this choices:\n");
        printf("\t1-Add new client <to select this option press 1>\n");
        printf("\t2-Edit client data <to select this option press 2>\n");
        printf("\t3-Transfer money <to select this option press 3>\n");
        printf("\t4-Print client data <to select this option press 4>\n");
        printf("\t5-Remove client data <to select this option press 5>\n");
        printf("\t6-Check balance of a client <to select this option press 6>\n");
        printf("\t7-Withdraw money <to select this option press 7>\n");
        printf("\t8-Deposit money <to select his option press 8>\n");
        printf("\t9-exit <to select this option press 9>\n");
        printf("Enter your choice: ");
        scanf("%c",&choice);
        //Switching on the "choice" to select which function will be excuted
        switch(choice)
        {
        case '1':
            add_new_client(&head);
            break;
        case '2':
            label1: printf("please enter the id of the client you want to edit its data: ");
            scanf("%i",&id);
            checked_id1 = id_check(head,id);
            //Check if the inserted id is valid or not
            if(checked_id1 == -1)
            {
                printf("This id does not exist!\n");
                goto label1;
            }
            //If id is existed
            edit_client_information(head,id);
            break;
        case '3':
            label2: printf("please enter the id of the client you want to transfer money from: ");
            scanf("%i",&id_trans_from);
            checked_id1 = id_check(head,id_trans_from);
            //Check if the inserted id is valid or not
            if(checked_id1 == -1)
            {
                printf("This id does not exist!\n");
                goto label2;
            }
            label3: printf("please enter the id o the client you want to transfer money to: ");
            scanf("%i",&id_trans_to);
            checked_id2 = id_check(head,id_trans_to);
            //Check if the inserted id is valid or not
            if(checked_id2 == -1)
            {
                printf("This id does not exist!\n");
                goto label3;
            }
            label4: printf("please enter the amount of money you want to transfer: ");
            scanf("%lf",&trans_money);
            if(trans_money <= 0)
            {
                printf("transfered money should be positive and greater than zero!\n");
                goto label4;
            }
            /*
                If id of the client we want to transfer money from is valid,
                the id of the client we want to transfer money to is valid,
                also the money we want to transfer is greater than zero,
                then we will transfer money
            */
            transfer_cash(head,id_trans_from,id_trans_to,trans_money);
            break;
        case '4':
            label5: printf("please enter the id of the client you want to print its data: ");
            scanf("%i",&id);
            checked_id1 = id_check(head,id);
            //Check if the inserted id is valid or not
            if(checked_id1 == -1)
            {
                printf("This id does not exist!\n");
                goto label5;
            }
            //If the id is existed
            print_client_data(head,id);
            break;
        case '5':
            label6: printf("Enter the id of the client you want to remove its data: ");
            scanf("%i",&id);
            checked_id1 = id_check(head,id);
            //Check if the inserted id is valid or not
            if(checked_id1 == -1)
            {
                printf("This id does not exist!\n");
                goto label6;
            }
            //If the id is existed
            remove_client_data(&head,head,id);
            break;
        case '6':
            label7: printf("Please enter id of the client you want to check its balance: ");
            scanf("%i",id);
            checked_id1 = id_check(head,id);
            //Check if the inserted id is valid or not
            if(checked_id1 == -1)
            {
                printf("This id does not exist!\n");
                goto label7;
            }
            //If the id is existed
            check_balance(head,id);
            break;
        case '7':
            label8: printf("please enter the id of the client you want to withdraw money from: ");
            scanf("%i",&id);
            checked_id1 = id_check(head,id);
            //Check if the inserted id is valid or not
            if(checked_id1 == -1)
            {
                printf("This id does not exist!\n");
                goto label8;
            }
            label9: printf("please enter the amount of money you want to transfer: ");
            scanf("%lf",&trans_money);
            //check if inserted amount of money if positive and greater than zero or not
            if(trans_money <= 0)
            {
                printf("transfered money should be positive and greater than zero!\n");
                goto label9;
            }
            //If the id is existed and the amount of money is positive
            withdraw(head,id,trans_money);
            break;
        case '8':
            label10: printf("please enter the id of the client you want to deposit money to: ");
            scanf("%i",&id);
            checked_id1 = id_check(head,id);
            //Check if the inserted id is valid or not
            if(checked_id1 == -1)
            {
                printf("This id does not exist!\n");
                goto label10;
            }
            label11: printf("please enter the amount of money you want to transfer: ");
            scanf("%lf",&trans_money);
            if(trans_money <= 0)
            {
                printf("transfered money should be positive and greater than zero!\n");
                goto label11;
            }
            //If the id is existed and the amount of money is positive
            deposit(head,id,trans_money);
            break;
        case '9':
            exit(0);
        default:
            printf("Wrong choice\n\n");

        }
    }
    return 0;
}
