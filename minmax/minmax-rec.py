import random
from timeit import default_timer as timer
from datetime import timedelta

# function to return maximum element
# using recursion
def findMaxRec(arr, n):

    # if n = 0 means whole array
    # has been traversed
    if n == 1:
        return arr[0]
    return max(arr[n - 1], findMaxRec(arr, n - 1))


# function to print Minimum element
# using recursion
def findMinRec(arr, n):

    # if size = 0 means whole array
    # has been traversed
    if n == 1:
        return arr[0]
    return min(arr[n - 1], findMinRec(arr, n - 1))


def main():
    print("Length: ", end="")
    numOfElements = int(input())

    data = [random.randrange(0, numOfElements * 10) for _ in range(numOfElements)]

    print("Unsorted:", data)

    start = timer()
    maximum, minimum = findMaxRec(data, len(data)), findMinRec(data, len(data))
    end = timer()

    print("Maximum:", maximum)
    print("Minimum:", minimum)
    print("Time:", timedelta(seconds=end - start))


if __name__ == "__main__":
    main()
