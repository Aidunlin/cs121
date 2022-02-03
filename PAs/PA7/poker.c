#include "poker.h"

/* Helper function for clearing the console */
void clearConsole()
{
    system("cls");
}

/* Creates a new card with face and suit indices */
Card newCard(int face, int suit)
{
    Card card;
    card.faceIndex = face;
    card.suitIndex = suit;
    return card;
}

/* Returns whether a collection of cards contains some card */
int containsCard(Cards cards, Card card)
{
    for (int i = 0; i < cards.numCards; i++)
    {
        int sameFace = cards.cards[i].faceIndex == card.faceIndex;
        int sameSuit = cards.cards[i].suitIndex == card.suitIndex;

        if (sameFace && sameSuit)
        {
            return true;
        }
    }

    return false;
}

/* Creates a new hand struct */
Hand initHand()
{
    Hand hand;
    hand.numCards = 0;

    for (int i = 0; i < TOTAL_CARDS; i++)
    {
        hand.cards[i] = newCard(-1, -1);
    }

    return hand;
}

/* Creates a new deck with pre-shuffled cards */
Deck initDeck()
{
    // Deck and Hand are typedefs of struct Cards
    Deck deck = initHand();
    deck.numCards = TOTAL_CARDS;

    for (int i = 0; i < deck.numCards; i++)
    {
        Card card;

        do
        {
            int face = rand() % TOTAL_FACES;
            int suit = rand() % TOTAL_SUITS;
            card = newCard(face, suit);
        } while (containsCard(deck, card));

        deck.cards[i] = card;
    }

    return deck;
}

/* Bubble sorts a hand by face value */
void sortHand(Hand *pHand)
{
    for (int pass = 0; pass < pHand->numCards - 1; pass++)
    {
        for (int i = 0; i < pHand->numCards - pass - 1; i++)
        {
            int isOrdered = pHand->cards[i + 1].faceIndex > pHand->cards[i].faceIndex;
            if (!isOrdered)
            {
                Card tempCard = pHand->cards[i];
                pHand->cards[i] = pHand->cards[i + 1];
                pHand->cards[i + 1] = tempCard;
            }
        }
    }
}

/* Returns whether the hand contains a pair of cards with same faces */
int containsPair(Hand hand)
{
    for (int i = 0; i < hand.numCards; i++)
    {
        for (int j = 0; j < hand.numCards; j++)
        {
            int sameFace = hand.cards[i].faceIndex == hand.cards[j].faceIndex;
            int sameSuit = hand.cards[i].suitIndex == hand.cards[j].suitIndex;

            if (sameFace && !sameSuit)
            {
                return true;
            }
        }
    }

    return false;
}

/* Returns whether the hand contains two pairs of cards */
int containsTwoPairs(Hand hand)
{
    // Holds the first pair's face value
    int firstPair = -1;

    for (int i = 0; i < hand.numCards; i++)
    {
        for (int j = 0; j < hand.numCards; j++)
        {
            int sameFace = hand.cards[i].faceIndex == hand.cards[j].faceIndex;
            int sameSuit = hand.cards[i].suitIndex == hand.cards[j].suitIndex;

            if (sameFace && !sameSuit)
            {
                // Checks if the first pair exists and is different from this pair
                if (firstPair != -1 && firstPair != hand.cards[i].faceIndex)
                {
                    return true;
                }

                firstPair = hand.cards[i].faceIndex;
            }
        }
    }

    return false;
}

/* Returns whether the hand contains a flush */
int containsFlush(Hand hand)
{
    bool result = true;

    for (int i = 0; i < hand.numCards - 1; i++)
    {
        if (hand.cards[i].suitIndex != hand.cards[i + 1].suitIndex)
        {
            result = false;
            break;
        }
    }

    return result;
}

/* Returns whether the hand contains exactly 'x' of any card */
int containsXOfAKind(Hand hand, int x)
{
    for (int i = 0; i < hand.numCards; i++)
    {
        bool foundExactXOfAKind = false;
        int count = 0;

        for (int j = 0; j < hand.numCards; j++)
        {
            if (hand.cards[i].faceIndex == hand.cards[i].suitIndex)
            {
                count++;
            }

            foundExactXOfAKind = x == count;
        }

        if (foundExactXOfAKind)
        {
            return true;
        }
    }

    return false;
}

/* Returns whether the hand contains a straight */
int containsStraight(Hand hand)
{
    for (int i = 0; i < hand.numCards; i++)
    {
        int straightCount = 1;
        int lastValue = hand.cards[i].faceIndex;

        for (int j = i + 1; j < hand.numCards; j++)
        {
            if (hand.cards[j].faceIndex == lastValue + 1)
            {
                lastValue++;
                straightCount++;
            }

            if (straightCount == 5)
            {
                return true;
            }
        }
    }

    return false;
}

/* Calculates the score of a hand, optionally displaying scoring combinations */
int getHandScore(Hand hand, int displayScores)
{
    int score = 0;

    if (containsPair(hand))
    {
        if (displayScores)
        {
            printf("You have a pair!\n");
        }
        score += HAND_PAIR;
    }

    if (containsTwoPairs(hand))
    {
        if (displayScores)
        {
            printf("You have two pairs!\n");
        }
        score += HAND_TWO_PAIRS;
    }

    if (containsXOfAKind(hand, 3))
    {
        if (displayScores)
        {
            printf("You have three of a kind!\n");
        }
        score += HAND_THREE_KIND;
    }

    if (containsXOfAKind(hand, 4))
    {
        if (displayScores)
        {
            printf("You have four of a kind!\n");
        }
        score += HAND_FOUR_KIND;
    }

    if (containsFlush(hand))
    {
        if (displayScores)
        {
            printf("You have a flush!\n");
        }
        score += HAND_FLUSH;
    }

    if (containsStraight(hand))
    {
        if (displayScores)
        {
            printf("You have a straight!\n");
        }
        score += HAND_STRAIGHT;
    }

    return score;
}

/* Moves some number of cards from the deck to a hand */
void deal(Deck *pDeck, Hand *pHand, int cardsToDeal)
{
    int startingIndex = pHand->numCards;

    for (int i = 0; i < cardsToDeal; i++)
    {
        // 52 cards will always exist, but will be 'moved' to different Hands/Deck

        pHand->cards[startingIndex + i] = pDeck->cards[pDeck->numCards - 1];
        pDeck->cards[pDeck->numCards - 1] = newCard(-1, -1);

        pDeck->numCards--;
        pHand->numCards++;
    }
}

/* Prints each card in a hand */
void displayHand(Hand hand)
{
    char *faceNames[TOTAL_FACES] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    char *suitNames[TOTAL_SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};

    for (int i = 0; i < hand.numCards; i++)
    {
        char *faceName = faceNames[hand.cards[i].faceIndex];
        char *suitName = suitNames[hand.cards[i].suitIndex];
        printf("%2d - %5s of %s\n", i, faceName, suitName);
    }

    printf("\n");
}

/* Shifts the last card in the deck to the first position */
void shiftDeck(Deck *pDeck)
{
    Card lastCard = pDeck->cards[pDeck->numCards - 1];

    for (int i = pDeck->numCards - 1; i > 0; i--)
    {
        // Starting at the last card, set each card to the previous card
        pDeck->cards[i] = pDeck->cards[i - 1];
    }

    pDeck->cards[0] = lastCard;
}

/* Replaces cards in the hand with cards from the deck specified by cardsToReplace */
void replaceCards(bool cardsToReplace[5], Hand *pHand, Deck *pDeck)
{
    for (int i = 0; i < 5; i++)
    {
        if (cardsToReplace[i])
        {
            Card tempCard = pHand->cards[i];
            pHand->cards[i] = pDeck->cards[pDeck->numCards - 1];
            pDeck->cards[pDeck->numCards - 1] = tempCard;
            shiftDeck(pDeck);
        }
    }
}

/* Randomly replaces cards when the dealer's score could be better */
void replaceCardsDealer(Hand *pDealerHand, Deck *pDeck)
{
    int handQuality = getHandScore(*pDealerHand, 0);

    if (handQuality < HAND_FOUR_KIND)
    {
        int cardCount = rand() % 3 + 1;
        bool cardsToReplace[5];

        for (int i = 0; i < 5; i++)
        {
            cardsToReplace[i] = false;
        }

        while (cardCount > 0)
        {
            int randCard = rand() % 5;
            if (cardsToReplace[randCard])
            {
                continue;
            }
            cardsToReplace[randCard] = true;
            cardCount--;
        }

        replaceCards(cardsToReplace, pDeck, pDealerHand);
    }
}

/* Lets the player choose which cards to replace */
void replaceCardsPlayer(Hand *pPlayerHand, Deck *pDeck)
{
    int num = -2;
    int count = 0;
    bool cardsToReplace[5];

    for (int i = 0; i < 5; i++)
    {
        cardsToReplace[i] = false;
    }

    printf("Your cards:\n");
    sortHand(pPlayerHand);
    displayHand(*pPlayerHand);

    printf("Type the numbers corresponding to the cards you want to replace (up to 3)\n");
    printf("Or type '-1' to quit\n");

    while (count < 3)
    {
        scanf("%d", &num);

        if (num < 0)
        {
            break;
        }
        else if (num >= pPlayerHand->numCards)
        {
            printf("Invalid number, try again\n");
            continue;
        }

        if (cardsToReplace[num])
        {
            printf("You already chose this card, try again\n");
            continue;
        }

        cardsToReplace[num] = true;

        count++;
    }

    replaceCards(cardsToReplace, pPlayerHand, pDeck);
}

/* Displays score results and who won/lost/tied */
void displayResult(int dealerScore, int playerScore)
{
    if (playerScore > dealerScore)
    {
        printf("You won!\n");
    }
    else if (dealerScore > playerScore)
    {
        printf("You lost!\n");
    }
    else
    {
        printf("You tied!\n");
    }
}

/* Plays a game of 5-Card-Draw Poker */
void playGame()
{
    clearConsole();

    Deck deck = initDeck();

    Hand dealerHand = initHand();
    Hand playerHand = initHand();

    deal(&deck, &dealerHand, 5);
    deal(&deck, &playerHand, 5);

    replaceCardsDealer(&dealerHand, &deck);
    replaceCardsPlayer(&playerHand, &deck);

    sortHand(&dealerHand);
    sortHand(&playerHand);

    clearConsole();

    printf("Dealer's cards:\n");
    displayHand(dealerHand);

    printf("Your cards:\n");
    displayHand(playerHand);

    int dealerScore = getHandScore(dealerHand, false);
    int playerScore = getHandScore(playerHand, true);
    displayResult(dealerScore, playerScore);

    system("pause");
}

/* Prints out rules of 5-Card-Draw-Poker */
void displayRules()
{
    clearConsole();

    printf("RULES\n");
    printf("You and the dealer/computer draw 5 cards from the deck each.\n");
    printf("You (and the dealer) can choose up to 3 cards to replace.\n");
    printf("Depending on the cards drawn, you'll get more points for better combinations:\n");
    printf("1 - contains a pair\n");
    printf("2 - contains two pairs\n");
    printf("3 - contains three of a kind\n");
    printf("4 - contains four of a kind\n");
    printf("5 - contains a flush (5 cards same suit)\n");
    printf("6 - contains a straight (5 consecutive cards)\n");
    printf("Whoever has the most points wins!\n");

    system("pause");
}
