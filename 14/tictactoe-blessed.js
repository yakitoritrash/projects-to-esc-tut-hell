const blessed = require('blessed');
const contrib = require('blessed-contrib');

const screen = blessed.screen({
  smartCSR: true,
  title: 'Tic Tac Toe'
});

let board = [
  [' ', ' ', ' '],
  [' ', ' ', ' '],
  [' ', ' ', ' ']
];

let currentPlayer = 'X';
let gameOver = false;

const grid = new contrib.grid({rows: 3, cols: 3, screen: screen});

const buttons = [];
for (let row = 0; row < 3; row++) {
  buttons[row] = [];
  for (let col = 0; col < 3; col++) {
    buttons[row][col] = grid.set(row, col, 1, 1, blessed.button, {  // Changed from 1,2 to 1,1 for proper grid sizing
      mouse: true,
      keys: true,
      shrink: true,
      padding: {top: 1, bottom: 1},
      style: {
        fg: 'white',
        bg: 'black',
        focus: {
          bg: 'blue'
        },
        hover: {
          bg: 'red'
        }
      },
      content: ' '
    });

    buttons[row][col].on('press', () => handleMove(row, col));
    screen.append(buttons[row][col]);
  }
}

const statusBox = blessed.box({
  top: '80%',
  left: 'center',
  width: '50%',
  height: '20%',
  content: `Player ${currentPlayer}'s turn`,
  tags: true,
  border: {
    type: 'line'
  },
  style: {
    fg: 'white',
    border: {
      fg: '#f0f0f0'
    }
  }
});
screen.append(statusBox);

const quitText = blessed.text({
  bottom: 0,
  left: 'center',
  content: 'Press ESC or Q to quit',
  style: {
    fg: 'gray'
  }
});
screen.append(quitText);

function handleMove(row, col) {
  if (gameOver || board[row][col] !== ' ') return;

  board[row][col] = currentPlayer;
  buttons[row][col].setContent(currentPlayer);
  buttons[row][col].style.fg = currentPlayer === 'X' ? 'green' : 'yellow';
  screen.render();

  const winner = checkWinner();
  if (winner) {
    gameOver = true;
    statusBox.setContent(winner === 'T' 
      ? '{center}Game Over! It\'s a tie!{/center}'  // Fixed closing tag
      : `{center}Player ${winner} wins!{/center}`);
    statusBox.style.border.fg = 'green';
    screen.render();
    return;
  }

  currentPlayer = currentPlayer === 'X' ? 'O' : 'X';
  statusBox.setContent(`Player ${currentPlayer}'s turn`);
  screen.render();
}

function checkWinner() {
  // Check rows
  for (let i = 0; i < 3; i++) {
    if (board[i][0] !== ' ' && board[i][0] === board[i][1] && board[i][1] === board[i][2]) {  // Fixed missing comparison
      return board[i][0];
    }
  }
  
  // Check columns
  for (let i = 0; i < 3; i++) {
    if (board[0][i] !== ' ' && board[0][i] === board[1][i] && board[1][i] === board[2][i]) {  // Fixed missing comparison
      return board[0][i];
    }
  }

  // Check diagonals
  if (board[0][0] !== ' ' && board[0][0] === board[1][1] && board[1][1] === board[2][2]) {
    return board[0][0];
  }
  if (board[0][2] !== ' ' && board[0][2] === board[1][1] && board[1][1] === board[2][0]) {
    return board[0][2];
  }

  // Check for tie
  for (let i = 0; i < 3; i++) {
    for (let j = 0; j < 3; j++) {
      if (board[i][j] === ' ') {
        return null;  // Game not over yet
      }
    }
  }
  return 'T';  // Tie if we get here
}

screen.key(['escape', 'q', 'C-c'], function() {
  return process.exit(0);
});

buttons[0][0].focus();
screen.render();
