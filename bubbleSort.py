def bubbleSort(arr):
  n = len(arr)
  for j in range(n):
    for i in range(n-1):
      if(arr[i] > arr[i+1]):
        arr[i], arr[i+1] = arr[i+1], arr[i]
