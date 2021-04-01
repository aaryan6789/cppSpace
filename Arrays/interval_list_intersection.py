

def intervalIntersection(A, B):
    """
    :type A: List[List[int]]
    :type B: List[List[int]]
    :rtype: List[List[int]]
    """
    # Result is a List of List
    res = []        # Declare an empty list first

    i = 0
    j = 0

    while (i < len(A) and j < len(B)):
        lo = max(A[i][0], B[j][0])
        hi = min(A[i][1], B[j][1])

        if lo <= hi:
            res.append([lo, hi])

        if A[i][1] < B[j][1]:
            i += 1
        else:
            j += 1

    return res
