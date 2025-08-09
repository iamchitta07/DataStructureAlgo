#include "functions.h"
#include "stdio.h"
#include "stdlib.h"

int main() {
    int n;
    printf("Enter Number of Inputs: ");
    scanf("%d", &n);
    int* arr = (int*)malloc(n*sizeof(int));
    input(arr, n);
    Node* root = constructAVLTree(arr, n);
    printf("-------- Choose any Option --------\n");
    printf("1. View the Tree\n");
    printf("2. Delete a Value from the Tree\n");
    printf("3. Height of the Tree\n");
    printf("4. Exit\n");
    printf("-----------------------------------\n");
    int choice;
    int flag = 1;
    while(flag) {
        printf("Choose any option from the given menu (1-4): ");
        scanf("%d", &choice);
        switch(choice) {
            int val;
            case 1:
                traversal(root);
                break;
            case 2:
                printf("Enter the Value You Want to Delete: ");
                scanf("%d", &val);
                root = deleteNode(root, val);
                break;
            case 3:
                printf("Height of the Tree is: %d\n", height(root));
                break;
            case 4:
                printf("Exiting...\n");
                flag = 0;
                break;
            default:
                printf("Please Enter a Valid Choice!!\n");
        }
    } freeNodes(root);
    free(arr);
    arr = NULL;
    return 0;
}
