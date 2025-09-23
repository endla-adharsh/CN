#include <stdio.h>
#include <string.h>

void encrypt(char *text, int key) {
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        char ch = text[i];
        if (ch >= 'a' && ch <= 'z') {
            ch = ch + key;
            if (ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }
            text[i] = ch;
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = ch + key;
            if (ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }
            text[i] = ch;
        }
    }
}

void decrypt(char *text, int key) {
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        char ch = text[i];
        if (ch >= 'a' && ch <= 'z') {
            ch = ch - key;
            if (ch < 'a') {
                ch = ch + 'z' - 'a' + 1;
            }
            text[i] = ch;
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = ch - key;
            if (ch < 'A') {
                ch = ch + 'Z' - 'A' + 1;
            }
            text[i] = ch;
        }
    }
}

int main() {
    char message[100];
    int key, choice;

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = 0; 

    printf("Enter key (an integer): ");
    scanf("%d", &key);

    printf("Choose an option:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            encrypt(message, key);
            printf("Encrypted message: %s\n", message);
            break;
        case 2:
            decrypt(message, key);
            printf("Decrypted message: %s\n", message);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}
