import random
from timeit import default_timer as timer
from datetime import timedelta


def binarySearch(list, x, low, high):
    # Repeat until the pointers low and high meet each other
    while low <= high:
        mid = low + (high - low) // 2

        if list[mid] == x:
            return mid

        elif list[mid] < x:
            low = mid + 1

        else:
            high = mid - 1

    return -1


def main():
    print("Length: ", end="")
    numOfElements = int(input())

    data = [2 * i + 1 for i in range(numOfElements)]
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
