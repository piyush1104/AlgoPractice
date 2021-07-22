// https://www.geeksforgeeks.org/remove-bst-keys-outside-the-given-range/
// good problem with good insight.
// so the thing is we need to remove all the keys from BST that are not in the range of min - max.
// now the approach I took was getting very complicated as I was thinking of iterating all the elements of tree
// but you don't need to iterate every element. If some element < min, then it means, its left tree is also invalid. So now we need to worry about right subtree only.
