function remDupes (arr) {
  const map = new Map();
  for (let a of arr) {
    map.set(a, (map.get(a) || 0) + 1);
  }
  console.log(arr);
  console.log(map);
  console.log(Array.from(map.keys()));
}

remDupes([3, 4, 5, 6, 7, 3, 1, 1]);
