import random
from timeit import default_timer as timer
from datetime import timedelta


def selectionSort(array, n):
    for i in range(n):

        # find min element ka index
        minIndex = i
        for j in range(i + 1, n):
            if array[j] < array[minIndex]:
                minIndex = j

        # swap min ele with the step being looped over
        array[i], array[minIndex] = array[minIndex], array[i]


def main():
    print("Length: ", end="")
    numOfElements = int(input())

    data = [random.randrange(0, numOfElements * 10)
            for _ in range(numOfElements)]

    print("Before: ", data)
    start = timer()
    selectionSort(data, len(data))
    end = timer()
    print("After: ", data)

    print("Time:", timedelta(seconds=end - start))


if __name__ == "__main__":
    main()
