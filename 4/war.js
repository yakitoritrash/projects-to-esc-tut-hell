//war game
//make a deck of 52 cards, A, K, Q, J, 10, 9, 8, 7, 6, 5, 4, 3, 2 (4 sets)
//shuffle the deck
//two players should have 26 cards each
//both players flip the last card (at the count of 3)
//the one with the higher card gets both the card on the table
//if both the cards have the same value (it is war) each player put in 3 more cards and then the fourth card is compared, whoever has the higher card gets all of them 10 cards. If a player does not have enough cards to play the war, their last card is considered in the war
//
//
//card - number / type;
//

class Cards {
  value;
  suit;
  constructor (value, suit) {
    this.value = value;
    this.suit = suit;
  }
}

class Deck {
  cards = [];
  constructor() {
    for (let i = 0; i < 14; i++) {
      const card = new Cards(i, hearts);
      cards.push(card);
    }
    for (let i = 0; i < 14; i++) {
      const card = new Cards(i, spades);
      cards.push(card);
    }
    for (let i = 0; i < 14; i++) {
      const card = new Cards(i, clubs);
      cards.push(card);
    }
    for (let i = 0; i < 14; i++) {
      const card = new Cards(i, diamonds);
      cards.push(card);
    }
  }
}

const deck = new Deck();
