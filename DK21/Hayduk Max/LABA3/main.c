#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main() {
    struct Node* root = NULL;
    int choice, value;
    while (1) {
        printf("1. Вставити елемент\n");
        printf("2. Видалити елемент\n");
        printf("3. Пошук елементу\n");
        printf("4. Друк дерева (зворотній обхід)\n");
        printf("5. Вихід\n");
        printf("Ваш вибір: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Введіть значення для вставки: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Введіть значення для видалення: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 3:
                printf("Введіть значення для пошуку: ");
                scanf("%d", &value);
                if (search(root, value) != NULL) {
                    printf("Елемент знайдено в дереві.\n");
                }
                else {
                    printf("Елемент не знайдено в дереві.\n");
                }
                break;
            case 4:
                printf("Друк дерева (зворотній обхід): ");
                printTree(root);
                printf("\n");
                break;
            case 5:
                deleteTree(root);
                exit(0);
            default:
                printf("Невірний вибір. Спробуйте ще раз.\n");
        }
        printf("\n");
    }
    return 0;
}
