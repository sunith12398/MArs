#include <stdio.h>
#include <ctype.h> // For toupper()

// Function to decode the message
void decodeMessage(const char *encrypted) {
    int shift;
    char decodedChar;
    
    for (int i = 0; encrypted[i] != '\0'; i++) {
        // Calculate the shift (i+1 because the first letter is shifted by 1)
        shift = i + 1;

        // Convert to uppercase if not already
        char ch = toupper(encrypted[i]);

        // Reverse the shift
        decodedChar = ch - shift;

        // Handle wrap-around from 'A' to 'Z'
        if (decodedChar < 'A') {
            decodedChar += 26;
        }

        printf("%c", decodedChar);
    }
    printf("\n");
}

int main() {
    char encryptedMessage[100];

    printf("Enter the encrypted message:\n");
    scanf("%s", encryptedMessage);

    decodeMessage(encryptedMessage);

    return 0;
}
