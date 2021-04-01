import heapq
# // Find K'th largest element in an array

# // Method 1 : Using min-heap
# // 1. Make a MinHeap of the 1st K elements in the array
# // 2. Now after this compare the element with the top of the minHeap
# //    If the element is greater then the TOP then it is inserted in the heap
# //      Else, keep going
# // Time Complexity = Make Heap = O(k)
# //                     Heapify = (n-k) logK


def findKthLargest(nums, k):
    minHeap = []
    
    for num in nums:
        heapq.heappush(minHeap, num)
        if len(minHeap) > k:
            heapq.heappop(minHeap)

    return heapq.heappop(minHeap)

# // Method 2 = Using MaxHeap
# // 1. Create a Max Heap
# // 2. Pop from the heap k times
# // Return the top item.
# // Time Complexity = O(n + Klogn)

def findKthLargest1(nums, k):
    maxHeap = []

    for num in nums:
        heapq.heappush(maxHeap, -num)

    while k > 0:
        item = -heapq.heappop(maxHeap)
        k -= 1
        
    return item

