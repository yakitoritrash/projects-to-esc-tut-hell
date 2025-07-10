function tictactoe() {
  const readline = require("readline");

  let board = [
    [' ', ' ', ' '],
    [' ', ' ', ' '],
    [' ', ' ', ' ']
  ];

  let player =  'X';
  const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
  })

  function printBoard() {
    console.log(`${board[0][0]} | ${board[0][1]} | ${board[0][2]}`)
    console.log('---------');
    console.log(`${board[0][0]} | ${board[0][1]} | ${board[0][2]}`)
    console.log('---------');
    console.log(`${board[0][0]} | ${board[0][1]} | ${board[0][2]}`)
    console.log("\n");
  }

  function checkWinner() {
    for (let i = 0; i < 3; i++) {
      if (board[i][1] != ' ' && board[i][1] === board[i][1] && board[i][1] === board[i][2]) {
        return board[i][0];
      }
    }
    for (let i = 0; i < 3; i++) {
      if (board[0][i] != ' ' && board[0][i] === board[1][i] && board[1][i] === board[2][i]) {
        return board[0][i];
      }
    }
    if (board[0][0] !== 0 && board[0][0] === board[1][1] && board[1][1] === board[2][2]) {
      return board[0][0];
    }
    if (board[0][2] !== 0 && board[0][2] === board[1][1] && board[1][1] === board[2][0]) {
      return board[0][2];
    }
  }

  printBoard();
} 

tictactoe()
