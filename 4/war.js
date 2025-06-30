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
  constructor (value, suit) {
    this.value = value;
    this.suit = suit;
  }
}

class Deck {
  constructor() {
    this.cards = [];
    const suits = ['hearts', 'spades', 'clubs', 'diamonds'];
    for (let suit of suits) {
      for (let value = 2; value <= 14; value++) {
        this.cards.push(new Cards(value, suit));
      }
    }
    this.Shuffle();
  }
  Shuffle() {
    let currentIndex = this.cards.length;
    while (currentIndex != 0) {
      let randomIndex = Math.floor(Math.random() * currentIndex);
      currentIndex--;
      [this.cards[currentIndex], this.cards[randomIndex]] = [this.cards[randomIndex], this.cards[currentIndex]];
    }
  }
}

class Player {
  constructor(name) {
    this.name = name;
    this.hand = [];
  }
  drawCard() {
    return this.hand.pop();
  }
}

const deck = new Deck();
const player1 = new Player('jon');
const player2 = new Player('ruth');

player1.hand = (deck.cards.slice(0, 26))
player2.hand = (deck.cards.slice(26, 51))


while (player1.hand.length !== 0 || player2.hand.length !== 0) {
  const topCard1 = player1.drawCard();
  const topCard2 = player2.drawCard();
  console.log(`${player1.name} : ${topCard1}`);
  console.log(`${player2.name} : ${topCard2}`);
  if (topCard1.value > topCard2.value) {
    player2.hand.pop(topCard2);
    player1.hand.push(topCard1);
  }
  if (topCard2.value > topCard1.value) {
    player1.hand.pop(topCard1);
    player2.hand.push(topCard2);
  }
  if (topCard1.value === topCard2.value) {
    war();
  }
}

function war(topCard1, topCard2) {
    table = [];
    table.push(player1.drawCard());
    table.push(player1.drawCard());
    table.push(player1.drawCard());
    topCard1 = table[table.length];
    table2 = [];
    table.push(player2.drawCard());
    table.push(player2.drawCard());
    table.push(player2.drawCard());
    topCard2 = table2[table.length];
    if (topCard1 > topCard2) {
      player1.push(table);
      player1.push(table2);
    }
    if (topCard2 > topCard1) {
      player2.push(table);
      player2.push(table2);
    }
    if (topCard1 === topCard2) {
    war();
  }
}
