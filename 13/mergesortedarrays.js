function mergeSorted(arr1, arr2) {
  arr3 = [];
  if (arr1.length > arr2.length) {
    for (let i = 0; i < arr1.length; i++) {
      if (arr1[i] <= arr2[i]) {
        arr3.push(arr1[i]);
      } else {
        arr3.push(arr2[i]);
      }
    }
  }
  if (arr2.length >= arr1.length) {
    for (let i = 0; i < arr2.length; i++) {
      if (arr1[i] <= arr2[i]) {
        arr3.push(arr1[i]);
      } else {
        arr3.push(arr2[i]);
      }
    }
  }
  console.log(arr3);
}

mergeSorted([2, 3, 4, 5, 7], [6, 8, 9, 10]);
