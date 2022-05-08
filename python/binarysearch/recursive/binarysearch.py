import random
from timeit import default_timer as timer
from datetime import timedelta


def binarySearch(arr, x, low, high):

    if high >= low:

        mid = low + (high - low) // 2

        # If found at mid, then return it
        if arr[mid] == x:
            return mid

        # Search the left half
        elif arr[mid] > x:
            return binarySearch(arr, x, low, mid - 1)

        # Search the right half
        else:
            return binarySearch(arr, x, mid + 1, high)

    else:
        return -1


def main():
    print("Length: ", end="")
    numOfElements = int(input())

    data = [random.randrange(0, numOfElements * 10)
            for _ in range(numOfElements)]
    # sort randomly generated array
    data.sort()
    print("Randomly generated array:", data)
    print("Find element: ", end="")
    find = int(input())

    start = timer()
    result = binarySearch(data, find, 0, len(data) - 1)
    end = timer()

    if result != -1:
        print("Element is present at index " + str(result))
    else:
        print("Not found")

    # print("Sorted:", data)
    print("Time:", timedelta(seconds=end - start))


if __name__ == "__main__":
    main()
