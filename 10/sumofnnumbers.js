function sum(num) {
  if (num === 1) {
    return 1;
  }
  console.log(num + sum(num - 1));
  return num + sum(num - 1);
}

sum(10);
