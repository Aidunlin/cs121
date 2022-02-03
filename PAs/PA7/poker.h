#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define _CRT_SECURE_NO_WARNINGS

#define TOTAL_FACES 13
#define TOTAL_SUITS 4
#define TOTAL_CARDS TOTAL_FACES *TOTAL_SUITS

typedef enum HandPoints
{
    HAND_PAIR = 1,
    HAND_TWO_PAIRS,
    HAND_THREE_KIND,
    HAND_FOUR_KIND,
    HAND_FLUSH,
    HAND_STRAIGHT
} HandPoints;

typedef struct Card
{
    int faceIndex;
    int suitIndex;
} Card;

typedef struct Cards
{
    Card cards[TOTAL_CARDS];
    int numCards;
} Cards, Hand, Deck;

/* Helper function for clearing the console */
void clearConsole();

/* Creates a new card with face and suit indices */
Card newCard(int face, int suit);

/* Returns whether a collection of cards contains some card */
int containsCard(Cards cards, Card card);

/* Creates a new hand struct */
Hand initHand();

/* Creates a new deck with pre-shuffled cards */
Deck initDeck();

/* Bubble sorts a hand by face value */
void sortHand(Hand *pHand);

/* Returns whether the hand contains a pair of cards with same faces */
int containsPair(Hand hand);

/* Returns whether the hand contains two pairs of cards */
int containsTwoPairs(Hand hand);

/* Returns whether the hand contains a flush */
int containsFlush(Hand hand);

/* Returns whether the hand contains exactly 'x' of any card */
int containsXOfAKind(Hand hand, int x);

/* Returns whether the hand contains a straight */
int containsStraight(Hand hand);

/* Calculates the score of a hand, optionally displaying scoring combinations */
int getHandScore(Hand hand, int displayScores);

/* Moves some number of cards from the deck to a hand */
void deal(Deck *pDeck, Hand *pHand, int cardsToDeal);

/* Prints each card in a hand */
void displayHand(Hand hand);

/* Shifts the last card in the deck to the first position */
void shiftDeck(Deck *pDeck);

/* Replaces cards in the hand with cards from the deck specified by cardsToReplace */
void replaceCards(bool cardsToReplace[5], Hand *pHand, Deck *pDeck);

/* Randomly replaces cards when the dealer's score could be better */
void replaceCardsDealer(Hand *pDealerHand, Deck *pDeck);

/* Lets the player choose which cards to replace */
void replaceCardsPlayer(Hand *pPlayerHand, Deck *pDeck);

/* Displays score results and who won/lost/tied */
void displayResult(int dealerScore, int playerScore);

/* Plays a game of 5-Card-Draw Poker */
void playGame();

/* Prints out rules of 5-Card-Draw-Poker */
void displayRules();
