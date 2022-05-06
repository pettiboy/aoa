import random
from timeit import default_timer as timer
from datetime import timedelta


def insertionSort(array):
    for i in range(1, len(array)):
        key = array[i]
        j = i - 1

        # Compare key with each element on the left of it
        # until an element smaller than it is found
        while j >= 0 and key < array[j]:
            array[j + 1] = array[j]
            j = j - 1

        # Place key at after the element
        # just smaller than it.
        array[j + 1] = key


def main():
    print("Length: ", end="")
    numOfElements = int(input())

    data = [random.randrange(0, numOfElements * 10)
            for _ in range(numOfElements)]

    print("un sorted:", data)

    start = timer()
    insertionSort(data)
    end = timer()

    print("Sorted:", data)
    print("Time:", timedelta(seconds=end - start))


if __name__ == "__main__":
    main()
