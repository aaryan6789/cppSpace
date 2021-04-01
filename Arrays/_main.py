# from Arrays import twoSum
from Arrays.intervals_merge import merge
from Arrays.interval_list_intersection import intervalIntersection
from Arrays.sliding_window_max import maxSlidingWindow


def main():
    print("__main__")
    import pandas as pd
    data = pd.read_csv('https://archive.ics.uci.edu/ml/machine-learning-databases/iris/iris.data')
    print(data)

    from IPython.display import HTML
    HTML('https://archive.ics.uci.edu/ml/machine-learning-databases/iris/iris.data')

    var = [1, 2, 3, 4, 5, 2]
    # res = twoSum.twoSum(var, 5)
    print(var)

    A = [[1, 2], [3, 5], [4, 9], [11, 12], [12, 14]]
    res = merge(A)
    print("Merge Intervals ", res)

    B = [[0, 2], [3, 5], [4, 9], [11, 15], [15, 19]]
    res = intervalIntersection(A, B)
    print("Intervals Intersection ", res)

    nums = [1, 3, -1, -3, 5, 3, 6, 7]
    res = maxSlidingWindow(nums, 3)

    print(res)



if __name__ == "__main__":
    main()
