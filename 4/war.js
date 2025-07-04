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
  hasCards() {
    return this.hand.length > 0;
  }
  cardCount() {
    return this.hand.length;
  }
}

function playWar() {
  const deck = new Deck();
  const player1 = new Player('jon');
  const player2 = new Player('ruth');

  player1.hand = (deck.cards.slice(0, 26))
  player2.hand = (deck.cards.slice(26, 52))

  let round = 1;

  while (player1.hasCards() && player2.hasCards()) {
    console.log(`\nRound ${round++}`);
    console.log(`${player1.name}: ${player1.cardCount()} cards | ${player2.name}: ${player2.cardCount()} cards`);
    const topCard1 = player1.drawCard();
    const topCard2 = player2.drawCard();
    console.log(`${JSON.stringify(player1.name)} : ${JSON.stringify(topCard1)}`);
    console.log(`${JSON.stringify(player2.name)} : ${JSON.stringify(topCard2)}`);

    const cardsInPlay = [topCard1, topCard2];

    while (topCard1.value === topCard2.value) {
      console.log("WAR!");

      const warCard1 = drawWarCards(player1);
      const warCard2 = drawWarCards(player2);

      if (!warCard1 || !warCard2) break;
      console.log(`${player1.name} wars with: ${cardValueToString(warCard1.value)} of ${warCard1.suit}`);
      console.log(`${player2.name} wars with: ${cardValueToString(warCard2.value)} of ${warCard2.suit}`);

      if (warCard1.value !== warCard2.value) {
        topCard1.value = warCard1.value;
        topCard2.value = warCard2.value;
      }
    }
    if (topCard1.value > topCard2.value) {
      console.log(`${player1.name} wins the round!`);
      player1.hand = [...cardsInPlay, ...player1.hand];
    } else if (topCard2.value > topCard1.value) {
      console.log(`${player2.name} wins the round!`);
      player2.hand = [...cardsInPlay, ...player2.hand];
    } else {
      console.log("Total war - cards remain in play");
    }
  }

  if (player1.hasCards()) {
    console.log(`${player1.name} wins the game!`);
  } else {
    console.log(`${player2.name} wins the game!`);
  }
}

function drawWarCards(player) {
  const cards = [];
  const cardsToDraw = Math.min(3, player.cardCount());
  for (let i = 0; i < cardsToDraw; i++) {
    cards.push(player.drawCard());
  }
  return cards;
}

function cardValueToString(value) {
  const faceCards = {
    11: 'J',
    12: 'Q',
    13: 'K',
    14: 'A'
  };
  return faceCards[value] || value.toString();
}

playWar();
