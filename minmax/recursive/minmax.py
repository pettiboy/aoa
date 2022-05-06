from datetime import timedelta
from timeit import default_timer as timer
import random
import sys

# Divide and conquer solution to find the minimum and maximum number in a list


def findMinAndMax(nums, left, right, min=sys.maxsize, max=-sys.maxsize):

    # if the list contains only one element

    if left == right:               # common comparison

        if min > nums[right]:          # comparison 1
            min = nums[right]

        if max < nums[left]:           # comparison 2
            max = nums[left]

        return min, max

    # if the list contains only two elements

    if right - left == 1:           # common comparison

        if nums[left] < nums[right]:      # comparison 1
            if min > nums[left]:       # comparison 2
                min = nums[left]

            if max < nums[right]:      # comparison 3
                max = nums[right]

        else:
            if min > nums[right]:      # comparison 2
                min = nums[right]

            if max < nums[left]:       # comparison 3
                max = nums[left]

        return min, max

    # find the middle element
    mid = (left + right) // 2

    # recur for the left sublist
    min, max = findMinAndMax(nums, left, mid, min, max)

    # recur for the right sublist
    min, max = findMinAndMax(nums, mid + 1, right, min, max)

    return min, max


if __name__ == '__main__':

    print("Length: ", end="")
    numOfElements = int(input())

    nums = [random.randrange(0, numOfElements * 10)
            for _ in range(numOfElements)]

    print("Elements:", nums)

    # initialize the minimum element by INFINITY and the
    # maximum element by -INFINITY
    start = timer()
    (minimum, maximum) = findMinAndMax(nums, 0, len(nums) - 1)
    end = timer()

    print("Maximum:", maximum)
    print("Minimum:", minimum)
    print("Time:", timedelta(seconds=end - start))
