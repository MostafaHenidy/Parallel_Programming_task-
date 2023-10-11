#include <stdio.h>
#include <string.h>
struct user
{
    char username[50];
    char password[50];
};
struct user users[50];
int userCount = 0;

void registeruser (){
    struct user user1 ;
    printf("Enter your username\n");
    scanf("\t%s",user1.username);
    printf("Enter your password\n");
    scanf("\t%s",user1.password);
    users[userCount] =user1;  
    userCount++;
    printf("User registered successfully\n");
}
void loginuser(){
    char username[50],password[50];
    printf("Enter your username\n");
    scanf("\t%s",username);
    printf("Enter your password\n");
    scanf("\t%s",password);
    for(int i=0; i<userCount;i++  ){
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            printf("Access granted!\n");
            return;
        }
    }
    printf("Access denied!\n");
}
int main(void){
    int choice ; 
    do {
        printf ("\n1 :Register \n2:Login \n3 Exit\n");
        scanf("%d",&choice);
        switch (choice){
            case 1: 
            registeruser();
            break;
            case 2:
            loginuser();
            break;
            default :
            printf("wrong choice Exiting\n");

        }
        
    }
    while(choice != 3 );
    return 0;

}