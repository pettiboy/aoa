from datetime import timedelta
from timeit import default_timer as timer
import random
import sys


def findMinAndMax(arr, left, right, minimum=sys.maxsize, maximum=-sys.maxsize):

    # if the list contains only one element
    if left == right:

        if minimum > arr[right]:
            minimum = arr[right]

        if maximum < arr[left]:
            maximum = arr[left]

        return minimum, maximum

    # if the list contains only two elements
    elif right - left == 1:

        if arr[left] < arr[right]:
            if minimum > arr[left]:
                minimum = arr[left]

            if maximum < arr[right]:
                maximum = arr[right]

        else:
            if minimum > arr[right]:
                minimum = arr[right]

            if maximum < arr[left]:
                maximum = arr[left]

        return minimum, maximum

    else:
        # find the middle element
        mid = (left + right) // 2

        # recur for the left sublist
        minimum1, maximum1 = findMinAndMax(arr, left, mid, minimum, maximum)

        # recur for the right sublist
        minimum2, maximum2 = findMinAndMax(
            arr, mid + 1, right, minimum1, maximum1)

        return minimum2, maximum2


if __name__ == '__main__':

    print("Length: ", end="")
    numOfElements = int(input())

    arr = [random.randrange(0, numOfElements * 10)
           for _ in range(numOfElements)]

    print("Elements:", arr)

    # initialize the minimum element by INFINITY and the
    # maximum element by -INFINITY
    start = timer()
    minimum, maximum = findMinAndMax(arr, 0, len(arr) - 1)
    end = timer()

    print("Maximum:", arr)
    print("Minimum:", arr)
    print("Time:", timedelta(seconds=end - start))
