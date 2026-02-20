#include <stdio.h>
//#include "lab7.h"
static int _ticket_store(int op,int value){
    static int total_fines = 0, total_tickets = 0;
    switch(op){
        case 0:
            return total_fines;break;
        case 1:
            total_tickets++;total_fines+=value;return total_tickets;break;
        case 2:
           return total_tickets;break;
        case 3:
            total_tickets = 0;total_fines = 0;return 0;break;
        default:
            return -1;break;
    }
    if(total_tickets < 0) total_tickets = 0;
    if(total_fines < 0) total_fines = 0;
}
int compute_over_speed(int limit,int actual){
    if(actual<0||limit<0) return -1;
    if(actual<limit) return 0;
    return actual-limit;
}
int compute_fine(int over_speed){
    if(over_speed<0) return -1;
    if(over_speed==0) return 0;
    if(over_speed<=10) return 50+5*over_speed;
    if(over_speed<=20) return 100+10*(over_speed-10);
    return 200+15*(over_speed-20); 
}
int add_ticket(int fine_dollars){
    if(fine_dollars<0) return -1;
    return _ticket_store(1,fine_dollars);
}
int total_fines(void){
    return _ticket_store(0,0);
}
int get_ticket_count(void){
    return _ticket_store(2,0);
}
int reset_tickets_and_fines(void){
    _ticket_store(3,0);
    if(_ticket_store(0,0)==0&&_ticket_store(2,0)==0) return 0;
    return -1;
}
int check_license_suspension(void){
    if(_ticket_store(0,0)>=500)return 1;
    return 0;
}