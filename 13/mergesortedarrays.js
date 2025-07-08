function mergeSorted(arr1, arr2) {
  let arr3 = [];
  if (arr1.length > arr2.length) {
    for (let i = 0; i <= arr1.length - 1; i++) {
      if (arr1[i] <= arr2[i]) {
        arr3.push(arr1[i]);
        arr3.push(arr2[i]);
      } else {
        arr3.push(arr2[i]);
        arr3.push(arr1[i]);
      }
    }
  }
  if (arr2.length >= arr1.length) {
    for (let i = 0; i <= arr2.length - 1; i++) {
      if (arr1[i] <= arr2[i]) {
        arr3.push(arr1[i]);
        arr3.push(arr2[i]);
      } else {
        arr3.push(arr2[i]);
        arr3.push(arr1[i]);
      }
    }
  }
  console.log(arr1);
  console.log(arr2);
  console.log(arr3);
}

mergeSorted([2, 4, 6, 7, 11, 12], [3, 5, 7, 8, 9, 10]);
