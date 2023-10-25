#include <stdio.h>
#include <stdlib.h>

// Definição de uma estrutura para representar um nó na lista
struct ListNode {
    int val;
    struct ListNode* next;
};

// Função para inverter a lista
struct ListNode* reverseLinkedList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* current = head;

    while (current != NULL) {
        struct ListNode* next_node = current->next;  // Armazena o próximo nó
        current->next = prev;  // Atualiza o próximo do nó atual para apontar para o nó anterior
        prev = current;  // Move prev para o nó atual
        current = next_node;  // Move current para o próximo nó
    }

    // O ponteiro prev agora aponta para a nova cabeça da lista revertida
    return prev;
}

// Função para imprimir a lista
void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // Construa a lista encadeada de entrada: 1 -> 2 -> 3 -> 4 -> 5
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->val = 3;
    head->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->val = 4;
    head->next->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->next->val = 5;
    head->next->next->next->next->next = NULL;

    // Inverter a lista
    struct ListNode* reversed_head = reverseLinkedList(head);

    // Imprimir a lista revertida
    printf("Lista Revertida: ");
    printList(reversed_head);

    // Libere a memória alocada
    free(head);
    free(reversed_head);

    return 0;
}
