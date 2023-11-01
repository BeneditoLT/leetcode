#include <stdio.h>

int firstUniqChar(char *s) {
    int arr[26] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        int charIndex = s[i] - 'a';
        arr[charIndex]++;
    }

    for (int i = 0; s[i] != '\0'; i++) {
        int charIndex = s[i] - 'a';
        if (arr[charIndex] == 1) {
            return i;
        }
    }

    return -1;
}

int main() {
    char s[] = "helloh";

    int result = firstUniqChar(s);
    if (result != -1) {
        printf("O primeiro caractere único está no índice %d\n", result);
    } else {
        printf("Não foram encontrados caracteres únicos na string.\n");
    }

    return 0;
}
