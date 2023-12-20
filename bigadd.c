#include <stdio.h>
#include <stdlib.h>

struct intNode
{
    int value;
    struct intNode *next;
};

void push(struct intNode **stack, int digit)
{
    struct intNode *newNode = (struct intNode *)malloc(sizeof(struct intNode));
    if (!newNode) {
        exit(EXIT_FAILURE);
    }
    newNode->value = digit;
    newNode->next = *stack;
    *stack = newNode;
}

int pop(struct intNode **stack)
{
    if (*stack == NULL) {  //empt stack check
        return 0; 
    }
    int digit = (*stack)->value;
    *stack = (*stack)->next;
    // dont free memory here
    return digit;
}

struct intNode* addStacks(struct intNode *stack1, struct intNode *stack2)
{
    struct intNode *result = NULL;
    int carry = 0;

    while (stack1 != NULL || stack2 != NULL || carry != 0)
    {
        int sum = carry + pop(&stack1) + pop(&stack2);
        carry = sum / 10;
        sum %= 10;
        push(&result, sum);
    }

    return result;
}

void printStack(struct intNode *stack)
{
    while (stack != NULL) {
        printf("%d", pop(&stack));
    }
    printf("\n");
}

void freeStack(struct intNode **stack)
{
    while (*stack != NULL)
    {
        pop(stack);
    }
}

int main(int argc, char *argv[]) 
{
    if (argc != 3)
    {
        fprintf(stderr, "bigadd <operand one> <operand two>\n");
        return EXIT_FAILURE;
    }

    struct intNode *stack1 = NULL;
    struct intNode *stack2 = NULL;

    // push digits of operand #one onto stack#1
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        push(&stack1, argv[1][i] - '0');
    }

    // push digits of operand #two onto stack#2
    for (int i = 0; argv[2][i] != '\0'; i++)
    {
        push(&stack2, argv[2][i] - '0');
    }

    struct intNode *result = addStacks(stack1, stack2);

    printStack(result);

    //free here
    freeStack(&stack1);
    freeStack(&stack2);
    freeStack(&result);

    return EXIT_SUCCESS;
}