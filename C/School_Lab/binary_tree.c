#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

void printTree(struct Node* root);
void findNode(struct Node* nodes, int count);
void deleteNode(struct Node* nodes, int count);

int main() {
    int num;

    srand(time(NULL));

    printf("Please enter the total number of the Nodes: ");
    scanf("%d", &num);

    struct Node* nodes = malloc(num * sizeof(struct Node));

    for (int i = 0; i < num; i++) {
        nodes[i].data = rand() % 100;
        nodes[i].left = NULL;
        nodes[i].right = NULL;
    }

    for (int i = 0; i < num; i++) {
        int leftIndex = 2 * i + 1;
        int rightIndex = 2 * i + 2;

        if (leftIndex < num)
            nodes[i].left = &nodes[leftIndex];
        if (rightIndex < num)
            nodes[i].right = &nodes[rightIndex];
    }

    int choice;

    while (1) {
        printf("\n===== MENU =====\n");
        printf("1. Find a node\n");
        printf("2. Delete a node\n");
        printf("3. Print the tree\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                findNode(nodes, num);
                break;
            case 2:
                deleteNode(nodes, num);
                break;
            case 3:
                printTree(&nodes[0]);
                break;
            case 4:
                free(nodes);
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}

void printTree(struct Node* root) {
    if (root == NULL)
        return;

    printTree(root->left);
    printf("Node value: %d\n", root->data);
    printTree(root->right);
}

void findNode(struct Node* nodes, int count) {
    int s;
    printf("Enter index to find: ");
    scanf("%d", &s);

    if (s < 0 || s >= count) {
        printf("Invalid index!\n");
        return;
    }

    printf("Node %d : %d\n", s, nodes[s].data);
}

void deleteNode(struct Node* nodes, int count) {
    int d;
    printf("Enter node index to delete: ");
    scanf("%d", &d);

    if (d < 0 || d >= count) {
        printf("Invalid index!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        if (nodes[i].left == &nodes[d])
            nodes[i].left = NULL;

        if (nodes[i].right == &nodes[d])
            nodes[i].right = NULL;
    }

    nodes[d].data = 0;
    nodes[d].left = NULL;
    nodes[d].right = NULL;

    printf("Node %d deleted.\n", d);
}
