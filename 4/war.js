class Card {
  constructor(value, suit) {
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
        this.cards.push(new Card(value, suit));
      }
    }
    this.shuffle();
  }
  
  shuffle() {
    let currentIndex = this.cards.length;
    while (currentIndex != 0) {
      let randomIndex = Math.floor(Math.random() * currentIndex);
      currentIndex--;
      [this.cards[currentIndex], this.cards[randomIndex]] = 
        [this.cards[randomIndex], this.cards[currentIndex]];
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

  player1.hand = deck.cards.slice(0, 26);
  player2.hand = deck.cards.slice(26, 52);

  let round = 1;

  while (player1.hasCards() && player2.hasCards()) {
    console.log(`\nRound ${round++}`);
    console.log(`${player1.name}: ${player1.cardCount()} cards | ${player2.name}: ${player2.cardCount()} cards`);
    
    const card1 = player1.drawCard();
    const card2 = player2.drawCard();
    
    console.log(`${player1.name} plays: ${cardValueToString(card1.value)} of ${card1.suit}`);
    console.log(`${player2.name} plays: ${cardValueToString(card2.value)} of ${card2.suit}`);
    
    const cardsInPlay = [card1, card2];
    
    while (card1.value === card2.value) {
      console.log("WAR!");
      
      // Check if players have enough cards for war
      const warCards1 = drawWarCards(player1);
      const warCards2 = drawWarCards(player2);
      
      cardsInPlay.push(...warCards1, ...warCards2);
      
      // Draw comparison card
      const warCard1 = player1.drawCard();
      const warCard2 = player2.drawCard();
      
      if (!warCard1 || !warCard2) break;
      
      cardsInPlay.push(warCard1, warCard2);
      console.log(`${player1.name} wars with: ${cardValueToString(warCard1.value)} of ${warCard1.suit}`);
      console.log(`${player2.name} wars with: ${cardValueToString(warCard2.value)} of ${warCard2.suit}`);
      
      if (warCard1.value !== warCard2.value) {
        card1.value = warCard1.value;
        card2.value = warCard2.value;
      }
    }
    
    // Determine winner of the round
    if (card1.value > card2.value) {
      console.log(`${player1.name} wins the round!`);
      // Add all cards to the bottom of winner's deck
      player1.hand = [...cardsInPlay, ...player1.hand];
    } else if (card2.value > card1.value) {
      console.log(`${player2.name} wins the round!`);
      player2.hand = [...cardsInPlay, ...player2.hand];
    } else {
      console.log("Total war - cards remain in play");
    }
  }

  // Game over
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

// Start the game
playWar();
