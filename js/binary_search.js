var arguments = process.argv;

if (arguments.length < 4) {
  console.log('usage: binary_search.js [-h] item array [array ...]');
  return;
}

let item = parseInt(arguments[2]);
let array = [];

for (var i = 3; i < arguments.length; i++) {
  array.push(parseInt(arguments[i]));
}

if (binary_search(array, item)) {
  console.log('Found it!');
} else {
  console.log('Not found...');
}

function binary_search(array, item) {
  console.log('Searching for ' + item + ' in [' + array + ']');
  let left = 0;
  let right = array.length - 1;

  while (left <= right) {
    let middle = Math.floor((left + right) / 2);

    if (array[middle] < item) {
      left = middle + 1;
    } else if (array[middle] > item) {
      right = middle - 1;
    } else {
      return true;
    }
  }

  return false;
}
