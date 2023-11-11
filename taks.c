#include <stdio.h>
#include <string.h>

typedef union {
    struct {
        char username[50];
        char password[50];
        int flag;
    } user;
} ActiveUser;

ActiveUser users[50];
int userCount = 0;

void registeruser()
{
    ActiveUser user1;
    printf("Enter your username\n");
    scanf("\t%s", user1.user.username);
    printf("Enter your password\n");
    scanf("\t%s", user1.user.password);
    printf("Enter 0 if you want to sign in anonymously otherwise enter 1 ");\
    scanf("\t%d",&user1.user.flag); 
    users[userCount] = user1;
    userCount++;
    if(user1.user.flag == 1){
        printf("User registered successfully\n"); 
    } else {
        printf("User registered anonymously\n"); 
    }
    
    
}

void loginuser()
{
    char username[50], password[50];
    printf("Enter your username\n");
    scanf("\t%s", username);
    printf("Enter your password\n");
    scanf("\t%s", password);
    for (int i = 0; i < userCount; i++)
    {
        if (users[i].user.flag == 1 && strcmp(username, users[i].user.username) == 0 && strcmp(password, users[i].user.password) == 0)
        {
            printf("Access granted!\n");
            return;
        }
    }
    printf("Access denied!\n");
}

int main(void)
{
    int choice;
    do
    {
        printf("\n1: Register\n2: Login\n3: Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            registeruser();
            break;
        case 2:
            loginuser();
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Wrong choice. Exiting...\n");
            break;
        }

    } while (choice != 3);
    return 0;
}
