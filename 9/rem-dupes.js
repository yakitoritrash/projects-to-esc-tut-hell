function remDupes (arr) {
  set = new Set(arr);
  console.log(Array.from(set));
}

remDupes([3, 2, 1, 4, 5, 2, 3]);
