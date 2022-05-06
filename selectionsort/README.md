# Insertion Sort

## Pseudo Code

```python
def selectionSort(arr, n):
    for i in range(0, n):
        minIndex = i

        for j in range(i+1, n):
            if arr[j] < arr[minIndex]:
                minIndex = j

        arr[i], arr[minIndex] = arr[i], arr[minIndex]
```

## Analysis

### Time Complexities:

Also, we can analyze the complexity by simply observing the number of loops. There are 2 loops so the complexity is n\*n = n2.

#### Worst Case Complexity: O(n2)

If we want to sort in ascending order and the array is in descending order then, the worst case occurs.

#### Best Case Complexity: O(n2)

It occurs when the array is already sorted

#### Average Case Complexity: O(n2)

It occurs when the elements of the array are in jumbled order (neither ascending nor descending).

The time complexity of the selection sort is the same in all cases.

At every step, you have to find the minimum element and put it in the right place. The minimum element is not known until the end of the array is not reached.

### Space Complexity

Space complexity is `O(1)` because an extra variable key is used.

## Attribution

- https://www.programiz.com/dsa/selection-sort
