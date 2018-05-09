#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int shufflesNeeded(int deckSize);
void calculateDeck(int* deck, int deckSize);
int checkDeck(const int* deck, int deckSize);

int main(void)
{   
    int i;
    for (i = 2; i <= 1000; i++)
    {
        if (i % 2 == 0)
        {
            printf("Shuffles needed for %d cards: %d\n", i, shufflesNeeded(i));
        }
    }
}

// Get the ammount of shuffles needed
int shufflesNeeded(int deckSize)
{
    int count = 0;

    // Allocate deck array
    int* deck = malloc(sizeof(deck) * deckSize);

    // Populate deck array
    int i;
    for (i = 0; i <= deckSize; i++)
    {
        deck[i] = i;
    }

    do
    {
        calculateDeck(deck, deckSize);
        ++count;
    }
    while(!checkDeck(deck, deckSize));

    // Free memory
    free(deck);

    return count;
}

// Calculate the current deck
void calculateDeck(int* deck, int deckSize)
{
    int* temp = malloc(deckSize * sizeof(deck));
    memcpy(temp, deck, deckSize * sizeof(deck));

    int i;
    int j;
    for (i = 0, j = 0; i < deckSize / 2; i++, j += 2)
    {
        deck[j] = temp[i];
        deck[j + 1] = temp[i + deckSize / 2];
    }

    // Free memory
    free(temp);
}

// Check if the deck is equal to a starting deck
int checkDeck(const int* deck, int deckSize)
{
    int i;
    for (i = 0; i < deckSize; i++)
    {
        if (deck[i] != i)
        {
            return 0;
        }
    }
    return 1;
}