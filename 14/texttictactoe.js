function tictactoe() {
  const readline = require("readline");

  let board = [
    [' ', ' ', ' '],
    [' ', ' ', ' '],
    [' ', ' ', ' ']
  ];

  let currentPlayer = 'X';
  const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
  });

  function printBoard() {
    console.log(` ${board[0][0]} | ${board[0][1]} | ${board[0][2]} `);
    console.log('-----------');
    console.log(` ${board[1][0]} | ${board[1][1]} | ${board[1][2]} `);
    console.log('-----------');
    console.log(` ${board[2][0]} | ${board[2][1]} | ${board[2][2]} `);
    console.log("\n");
  }

  function checkWinner() {
    // Check rows
    for (let i = 0; i < 3; i++) {
      if (board[i][0] !== ' ' && board[i][0] === board[i][1] && board[i][1] === board[i][2]) {
        return board[i][0];
      }
    }
    
    // Check columns
    for (let i = 0; i < 3; i++) {
      if (board[0][i] !== ' ' && board[0][i] === board[1][i] && board[1][i] === board[2][i]) {
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
    let isTie = true;
    for (let i = 0; i < 3; i++) {
      for (let j = 0; j < 3; j++) {
        if (board[i][j] === ' ') {
          isTie = false;
          break;
        }
      }
    }
    if (isTie) return 'T';
    
    return null;
  }

  function makeMove() {
    printBoard();
    rl.question(`Player ${currentPlayer}, enter your move (row,col): `, (input) => {
      const [row, col] = input.split(',').map(num => parseInt(num.trim()) - 1);

      if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] === ' ') {
        board[row][col] = currentPlayer;
        const winner = checkWinner();
        if (winner) {
          printBoard();
          if (winner === 'T') {
            console.log("It's a tie!");
          } else {
            console.log(`Player ${winner} wins!`);
          }
          rl.close();
          return;
        }
        
        currentPlayer = currentPlayer === 'X' ? 'O' : 'X';
      } else {
        console.log('Invalid move! Try again.');
      }
      
      makeMove();
    });
  }

  console.log('Welcome to Tic Tac Toe!');
  console.log('Enter moves as "row,col" (e.g., "1,2" for first row, second column)');
  makeMove();
} 

tictactoe();
