#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *top = NULL;
void push(int value)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Stack Overflow\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("Element pushed successfully\n");
}
void pop()
{
    struct Node *temp;

    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    temp = top;
    printf("Popped value : %d\n", top->data);
    top = top->next;
    free(temp);
}
void peek()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element : %d\n", top->data);
}
void empty()
{
    if (top == NULL)
        printf("Stack is empty\n");
    else
        printf("Stack is not empty\n");
}
void display()
{
    struct Node *temp = top;
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void count()
{
    int count = 0;
    struct Node *temp = top;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("No. of elements in stack : %d\n", count);
}
void destroy()
{
    struct Node *temp;
    while (top != NULL)
    {
        temp = top;
        top = top->next;
        free(temp);
    }
    printf("All stack elements destroyed\n");
}
int main()
{
    int choice, value;
    while (1)
    {
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Top");
        printf("\n4. Empty");
        printf("\n5. Exit");
        printf("\n6. Display");
        printf("\n7. Stack Count");
        printf("\n8. Destroy Stack");
        printf("\nEnter choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d", &value);
            push(value);
            break;

        case 2:
            pop();
            break;

        case 3:
            peek();
            break;

        case 4:
            empty();
            break;

        case 5:
            exit(0);

        case 6:
            display();
            break;

        case 7:
            count();
            break;

        case 8:
            destroy();
            break;

        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}

Output:

Enter choice : 1
Enter data : 56
Element pushed successfully
Enter choice : 1
Enter data : 80
Element pushed successfully
Enter choice : 2
Popped value : 80
Enter choice : 3
Top element : 56
Enter choice : 1
Enter data : 78
Element pushed successfully
Enter choice : 1
Enter data : 90
Element pushed successfully
Enter choice : 6
90 78 56
Enter choice : 7
No. of elements in stack : 3
Enter choice : 8
All stack elements destroyed
Enter choice : 4
Stack is empty
Enter choice : 5
