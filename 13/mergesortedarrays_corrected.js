function mergeArrays(arr1, arr2) {
  let arr3 = [];
  let i = 0;
  let j = 0;

  while (i < arr1.length && j < arr2.length) {
    if (arr1[i] <= arr2[j]) {
      arr3.push(arr1[i]);
      i++;
    } else {
      arr3.push(arr2[j]);
      j++;
    }
  }

  while (i < arr1.length) {
    arr3.push(arr1[i]);
    i++;
  }

  while (j < arr2.length) {
    arr3.push(arr2[j]);
    j++;
  }

  console.log(arr1);
  console.log(arr2);
  console.log(arr3);

  return arr3;
}

mergeArrays([2, 4, 6, 7, 11, 12], [3, 5, 7, 8, 9, 10])
