function sum(num) {
  res = 0;
  while (num >= 0) {
    res += num;
    num--;
  }
  console.log(res);
  return res;
}

sum(5);
