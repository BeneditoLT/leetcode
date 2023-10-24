#include <stdio.h>
#include <stdlib.h>

// Função para encontrar os índices dos números que somam ao alvo
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Aloca espaço para armazenar os índices dos números que somam ao alvo.
    int* indices = (int*)malloc(2 * sizeof(int));

    // Verifica se a alocação de memória foi bem-sucedida
    if (indices == NULL) {
        *returnSize = 0; // Se falhar, definimos o tamanho do resultado como 0
        return NULL;     // E retornamos NULL para indicar um erro
    }

    // Percorre o array para encontrar a solução
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            // Verifica se a soma dos elementos nos índices i e j é igual ao alvo
            if (nums[i] + nums[j] == target) {
                indices[0] = i;     // Armazena o índice do primeiro número do par
                indices[1] = j;     // Armazena o índice do segundo número do par
                *returnSize = 2;   // Define o tamanho do resultado como 2 (encontramos um par)
                return indices;    // Retorna os índices do par encontrado
            }
        }
    }

    // Se não encontrar um par que some ao alvo, define o tamanho do resultado como 0
    *returnSize = 0;
    free(indices); // Libera a memória alocada para "indices" se nenhum par for encontrado
    return NULL;    // Retorna NULL para indicar que nenhum par foi encontrado.
}

int main() {
    // Exemplo de entrada
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize;
    int* result;

    // Calcula o tamanho do vetor "nums"
    int nums_length = sizeof(nums) / sizeof(nums[0]);

    // Chama a função "twoSum" para encontrar os índices dos números que somam ao alvo
    result = twoSum(nums, nums_length, target, &returnSize);

    // Verifica o tamanho do resultado e imprime os índices do par encontrado ou uma mensagem de erro
    if (returnSize == 2) {
        printf("[%d, %d]\n", result[0], result[1]);
    } else {
        printf("Nenhum par encontrado.\n");
    }

    // Libera a memória alocada para o resultado
    free(result);

    return 0;
}