#include <stdio.h>

// Função para realizar a busca binária no array ordenado
int search(int nums[], int numSize, int target) {
    int left = 0;             // Índice esquerdo do intervalo
    int right = numSize - 1;  // Índice direito do intervalo

    while (left <= right) {  // Enquanto o intervalo for válido
        int middle = left + (right - left) / 2; // Calcula o índice do meio

        if (nums[middle] == target) {
            return middle; // Target encontrado, retorna o índice
        } else if (nums[middle] < target) {
            left = middle + 1; // Ajusta o índice esquerdo para a direita
        } else {
            right = middle - 1; // Ajusta o índice direito para a esquerda
        }
    }

    return -1; // Target não encontrado
}

int main() {
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int numSize = sizeof(nums) / sizeof(nums[0]); // Calcula o tamanho do array
    int target = 1; // Valor a ser buscado

    int result = search(nums, numSize, target); // Realiza a busca

    if (result != -1) {
        printf("Target %d encontrado no índice %d\n", target, result);
    } else {
        printf("Target %d não encontrado no array.\n", target);
    }

    return 0;
}



