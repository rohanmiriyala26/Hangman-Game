#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#define MAX_WORD_LENGTH 100
#define MAX_TRIES 6
struct WordWithHint {
    char word[MAX_WORD_LENGTH];
    char hint[MAX_WORD_LENGTH];
};
void displayHangman(int incorrectGuesses) {
    char *hangmanStages[] = {
        "  +---+\n"
        "  |   |\n"
        "      |\n"
        "      |\n"
        "      |\n"
        "      |\n",
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        "      |\n"
        "      |\n"
        "      |\n",
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        "  |   |\n"
        "      |\n"
        "      |\n",
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " /|   |\n"
        "      |\n"
        "      |\n",
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " /|\\  |\n"
        "      |\n"
        "      |\n",
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " /|\\  |\n"
        " /    |\n"
        "      |\n",
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " /|\\  |\n"
        " / \\  |\n"
        "      |\n"
    };

    printf("%s", hangmanStages[incorrectGuesses]);
}
void displayWord(const char word[], const bool guessed[]) {
    for (int i = 0; word[i] != '\0'; ++i) {
        if (guessed[i]) {
            printf("%c ", word[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}
int main() {
    struct WordWithHint words[] = {
        {"apple", "A fruit that is red or green."},
        {"banana", "A fruit that is yellow."},
        {"cherry", "A fruit that is red."},
        {"grape", "A fruit that is purple or green."},
        {"orange", "A fruit that is orange and also in green"},
        {"pear", "A fruit that is green or yellow."},
        {"pineapple", "A fruit that is spiky and yellow."},
        {"strawberry", "A fruit that is red and has seeds on the outside."},
        {"watermelon", "A fruit that is green on the outside."}
    };
	int numWords = sizeof(words) / sizeof(words[0]);
    srand(time(NULL));
    int randomIndex = rand() % numWords;
    char *word = words[randomIndex].word;
    char *hint = words[randomIndex].hint;
    int wordLength = strlen(word);
    bool guessed[wordLength];
    memset(guessed, false, sizeof(guessed));
    int numTries = 0;
    int incorrectGuesses = 0;
    while (numTries < MAX_TRIES) {
        printf("Hint: %s\n", hint);
        displayHangman(incorrectGuesses);
        displayWord(word, guessed);
        printf("Guess a letter: ");
        char guess;
        scanf(" %c", &guess);
        guess = tolower(guess);
        bool found = false;
        for (int i = 0; i < wordLength; ++i) {
            if (word[i] == guess) {
                guessed[i] = true;
                found = true;
            }
        }
        if (!found) {
            ++numTries;
            ++incorrectGuesses;
            printf("Incorrect guess. You have %d tries left.\n", MAX_TRIES - numTries);
        }
        bool allGuessed = true;
        for (int i = 0; i < wordLength; ++i) {
            if (!guessed[i]) {
                allGuessed = false;
                break;
            }
        }
        if (allGuessed) {
            printf("%s\n", word);
            printf("Congratulations! You guessed the word.\n");
            return 0;
        }
    }
    displayHangman(incorrectGuesses);
    printf("Sorry, you ran out of tries. The word was %s.\n", word);
    return 0;
}
