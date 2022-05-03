import random
from timeit import default_timer as timer
from datetime import timedelta


def selectionSort(array):
    for step in range(len(array)):
        minIndex = step
        for i in range(step + 1, len(array)):
            # select the minimum element in each loop
            if array[i] < array[minIndex]:
                minIndex = i
        # put min at the correct position
        array[step], array[minIndex] = array[minIndex], array[step]


def main():
    print("Length: ", end="")
    numOfElements = int(input())

    data = [random.randrange(0, numOfElements * 10) for _ in range(numOfElements)]

    start = timer()
    selectionSort(data)
    end = timer()

    # print("Sorted:", data)
    print("Time:", timedelta(seconds=end - start))


if __name__ == "__main__":
    main()
