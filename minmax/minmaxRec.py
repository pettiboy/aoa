import random
from timeit import default_timer as timer
from datetime import timedelta

print("Length: ", end="")
numOfElements = int(input())

data = [random.randrange(0, numOfElements * 10)
        for _ in range(numOfElements)]


def maxMin(i, j, maximum, minimum):
    if i == j:
        maximum = data[i]
        minimum = data[i]

    elif i == j - 1:
        if data[i] < data[j]:
            maximum = data[j]
            minimum = data[i]
        else:
            maximum = data[i]
            minimum = data[j]
    else:
        max1 = maximum
        min1 = minimum

    mid = (i + j) / 2

    maxMin(i, mid, maximum, minimum)
    maxMin(mid + 1, j, max1, min1)

    if (maximum < max1):
        maximum = max1

    if (minimum > min1):
        minimum = min1

    return maximum, minimum


def main():
    print("Unsorted:", data)

    start = timer()
    maximum, minimum = maxMin(data[0], data[len(data) - 1], data[0], data[0])
    end = timer()

    print("Maximum:", maximum)
    print("Minimum:", minimum)
    print("Time:", timedelta(seconds=end - start))


if __name__ == "__main__":
    main()
