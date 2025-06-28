function PalCheck(str) {
  strarr = str.split('');
  newStr = [];
  for (let i = str.length; i <= 0; i--) {
    newStr.push(strarr[i]);
  }
  if (strarr === newStr) {
    console.log(true);
  } else {
    console.log(false);
  }
}
