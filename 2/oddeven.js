function isOdd(num) {
  if (num % 2 != 0) {
    return true;
  } else {
    return false;
  }
}

if (isOdd(8)) {
  console.log(true);
} else {
  console.log(false);
}
