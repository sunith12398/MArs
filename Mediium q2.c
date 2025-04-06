#include <stdio.h>
#include <string.h>

// Morse code dictionary
struct MorseCode {
    char *code;
    char letter;
};

// Morse code mapping
struct MorseCode morseDictionary[] = {
    {".-", 'A'}, {"-...", 'B'}, {"-.-.", 'C'}, {".-..", 'D'}, {"." , 'E'},
    {"..-.", 'F'}, {"--." , 'G'}, {"....", 'H'}, {".." , 'I'}, {".---", 'J'},
    {"-.-", 'K'}, {".-..", 'L'}, {"--", 'M'}, {"-." , 'N'}, {"---", 'O'},
    {".--.", 'P'}, {"--.-", 'Q'}, {".-.", 'R'}, {"..." , 'S'}, {"-" , 'T'},
    {"..-", 'U'}, {"...-", 'V'}, {".--", 'W'}, {"-..-", 'X'}, {"-.--", 'Y'},
    {"--..", 'Z'},
    {"-----", '0'}, {".----", '1'}, {"..---", '2'}, {"...--", '3'}, {"....-", '4'},
    {".....", '5'}, {"-....", '6'}, {"--...", '7'}, {"---..", '8'}, {"----.", '9'}
};

// Function to decode Morse code
void decodeMorse(const char *morseCode) {
    char temp[10];
    int tempIndex = 0;

    for (int i = 0; i <= strlen(morseCode); i++) {
        if (morseCode[i] == '.' || morseCode[i] == '-') {
            temp[tempIndex++] = morseCode[i];
        } else if (morseCode[i] == ' ' || morseCode[i] == '\0') {
            temp[tempIndex] = '\0';

            // Check for Morse code in the dictionary
            for (int j = 0; j < sizeof(morseDictionary) / sizeof(morseDictionary[0]); j++) {
                if (strcmp(temp, morseDictionary[j].code) == 0) {
                    printf("%c", morseDictionary[j].letter);
                    break;
                }
            }
            
            // Handle spaces between words
            if (morseCode[i] == ' ') {
                printf(" ");
            }
            tempIndex = 0;
        }
    }
    printf("\n");
}

int main() {
    char morseCode[1000];

    printf("Enter Morse code (use spaces between letters and ' / ' between words):\n");
    fgets(morseCode, sizeof(morseCode), stdin);

    decodeMorse(morseCode);

    return 0;
}
