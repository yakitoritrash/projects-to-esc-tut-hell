function tictactoe() {
  const readline = require("readline");

  let board = [
    ['', '', ''],
    ['', '', ''],
    ['', '', '']
  ];

  let player =  'X';
  const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
  })

  function printBoard() {
    console.log(`${board[0][0]} | ${board[0][1]} | ${board[0][2]}`)
    console.log("- | - | -");
    console.log(`${board[0][0]} | ${board[0][1]} | ${board[0][2]}`)
    console.log("- | - | -");
    console.log(`${board[0][0]} | ${board[0][1]} | ${board[0][2]}`)
    console.log("- | - | -");
  }
  
  printBoard();
} 

tictactoe()
