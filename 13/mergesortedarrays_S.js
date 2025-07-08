function mergeSort(arr1, arr2) {
  const arr3 = [];
  for (let arr of arr1) {
    arr3.push(arr);
  }
  for (let arr of arr2) {
    arr3.push(arr);
  }
  arr3.sort((a, b) => a - b) 
  console.log(arr3);
}

mergeSort([2, 4, 6, 7, 11, 12], [3, 5, 7, 8, 9, 10])
