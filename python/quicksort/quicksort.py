import random
from timeit import default_timer as timer
from datetime import timedelta


def partitionrand(arr, start, stop):
    ''' This function generates random pivot,
    swaps the first element with the pivot
    and calls the partition function.'''

    # Generating a random number between the
    # starting index of the array and the
    # ending index of the array.
    randpivot = random.randrange(start, stop)

    # Swapping the starting element of
    # the array and the pivot
    arr[start], arr[randpivot] = arr[randpivot], arr[start]

    return partition(arr, start, stop)


def partition(array, low, high):
    '''function to find the partition position'''

    # choose the rightmost element as pivot
    pivot = array[high]

    # pointer for greater element
    i = low

    # traverse through all elements
    # compare each element with pivot
    for j in range(low, high):
        # if element smaller than pivot is found
        if array[j] <= pivot:
            # swap it with the greater element pointed by i
            (array[i], array[j]) = (array[j], array[i])
            i = i + 1

    # swap the pivot element with the greater element specified by i
    (array[i], array[high]) = (array[high], array[i])

    # return the position from where partition is done
    return i


def quickSort(array, low, high):
    if low < high:

        # find pivot element such that
        # element smaller than pivot are on the left
        # element greater than pivot are on the right
        pi = partition(array, low, high)

        # for randomized quick sort
        # pi = partitionrand(array, low, high)

        # recursive call on the left of pivot
        quickSort(array, low, pi - 1)

        # recursive call on the right of pivot
        quickSort(array, pi + 1, high)


def main():
    print("Length: ", end="")
    numOfElements = int(input())

    data = [random.randrange(0, numOfElements * 10)
            for _ in range(numOfElements)]

    print("Unsorted:", data)

    start = timer()
    quickSort(data, 0, numOfElements - 1)
    end = timer()

    print("Sorted:", data)
    print("Time:", timedelta(seconds=end - start))


if __name__ == "__main__":
    main()
