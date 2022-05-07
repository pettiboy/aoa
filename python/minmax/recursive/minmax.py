from datetime import timedelta
from timeit import default_timer as timer
import random
import sys


def minmax(arr, l, h, minimum=sys.maxsize, maximum=-sys.maxsize):
    if l == h:
        return arr[l], arr[l]

    elif h - l == 1:
        if arr[l] < arr[h]:
            return arr[l], arr[h]
        else:
            return arr[h], arr[l]

    else:
        mid = (l + h) // 2
        minimum1, maximum1 = minmax(arr, l, mid, minimum, maximum)
        minimum2, maximum2 = minmax(arr, mid+1, h, minimum1, maximum1)

        # find smallest out of minimum1 and minimum2
        if minimum1 > minimum2:
            minimum = minimum2
        else:
            minimum = minimum1

        # find largest out of maximum1 and maximum2
        if maximum1 > maximum2:
            maximum = maximum1
        else:
            maximum = maximum2

        return minimum, maximum


def main():
    print("Length: ", end="")
    numOfElements = int(input())

    arr = [random.randrange(0, numOfElements * 10)
           for _ in range(numOfElements)]

    print("Elements:", arr)

    start = timer()
    minimum, maximum = minmax(arr, 0, len(arr) - 1)
    end = timer()

    print("Maximum:", maximum)
    print("Minimum:", minimum)
    print("Time:", timedelta(seconds=end - start))


if __name__ == '__main__':
    main()
