function largestSmallest(arr) {
  res = [];
  res.push(Math.max(...arr));
  res.push(Math.min(...arr));
  console.log(arr);
  console.log(res);
  return res;
}

largestSmallest([12, 34, 56, 32, 89, 53]);
