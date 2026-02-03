#include <stdio.h>
#include "lab7.h"
int main(){
    int running = 1;
    while(running){
        int input;
        printf("1. Compute Over Speed\n");
        printf("2. Compute Fine\n");
        printf("3. Add Ticket\n");
        printf("4. Total Fines\n");
        printf("5. Get Ticket Count\n");
        printf("6. Reset Tickets and Fines\n");
        printf("7. Check License Suspension\n");
        printf("8. Exit\n");
        printf("Enter your choice:\t");
        scanf("%d",&input);
        switch(input){
            case 1:
                int limit, actual;
                printf("\nEnter speed limit:\t");
                scanf("%d",&limit);
                printf("\nEnter actual speed:\t");
                scanf("%d",&actual);
                int over_speed = compute_over_speed(limit, actual);
                if(over_speed == -1){
                    printf("\nInvalid input. Speeds must be non-negative.\n");
                } else {
                    printf("\nOver speed:\t%d\n", over_speed);
                }
                break;
            case 2:
                int over_speed_fine;
                printf("\nEnter over speed: ");
                scanf("%d",&over_speed_fine);
                int fine = compute_fine(over_speed_fine);
                if(fine == -1){
                    printf("\nInvalid input. Over speed must be non-negative.\n");
                } else {
                    printf("\nFine:\t$%d\n", fine);
                }
                break;
                case 3:
                int fine_dollars;
                printf("\nEnter fine amount in dollars:\t");
                scanf("%d",&fine_dollars);
                int ticket_count = add_ticket(fine_dollars);
                if(ticket_count == -1){
                    printf("\nInvalid input. Fine amount must be non-negative.\n");
                } else {
                    printf("\nTicket added. Total tickets:\t%d\n", ticket_count);
                }
                break;
            case 4:
                int total = total_fines();
                printf("\nTotal fines:\t$%d\n", total);
                break;
            case 5:
                int count = get_ticket_count();
                printf("\nTotal tickets:\t%d\n", count);
                break;
            case 6:
                int reset_status = reset_tickets_and_fines();
                if(reset_status == 0){
                    printf("\nTickets and fines have been reset.\n");
                } else {
                    printf("\nError resetting tickets and fines.\n");
                }
                break;
            case 7:
                int suspension_status = check_license_suspension();
                if(suspension_status == 1){
                    printf("\nLicense is suspended.\n");
                } else {
                    printf("\nLicense is not suspended.\n");
                }
                break;
            case 8:
                running = 0;   
                break;  
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}