import random
from timeit import default_timer as timer
from datetime import timedelta


def straightMaxMin(arr):
    n = len(arr)
    maximum = arr[0]
    minimum = arr[0]

    for i in range(1, n):
        if arr[i] > maximum:
            maximum = arr[i]
        if arr[i] < minimum:
            minimum = arr[i]

    return maximum, minimum


def main():
    print("Length: ", end="")
    numOfElements = int(input())

    data = [random.randrange(0, numOfElements * 10)
            for _ in range(numOfElements)]

    print("Unsorted:", data)

    start = timer()
    maximum, minimum = straightMaxMin(data)
    end = timer()

    print("Maximum:", maximum)
    print("Minimum:", minimum)
    print("Time:", timedelta(seconds=end - start))


if __name__ == "__main__":
    main()
