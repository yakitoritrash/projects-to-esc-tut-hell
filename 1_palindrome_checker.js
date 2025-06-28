function PalCheck(str) {
  strarr = str.split('');
  newStr = [];
  for (let i = str.length - 1; i >= 0; i--) {
    newStr.push(strarr[i]);
  }
  if (strarr === newStr) {
    return true;
  } else {
    return false;
  }
}

if (PalCheck('bob')) {
  console.log(true);
} else {
  console.log(false);
}
