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
    buttons[row][col] = grid.set(row, col, 1, 2, blessed.button, {
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

}
