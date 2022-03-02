def selectionSort(arr):
  for i in range(len(arr)-1, 0, -1):
    maxPosition = 0
    for location in range(1,i+1):
      if(arr[location] > arr[maxPosition]):
        maxPosition = location
    
    arr[i], arr[maxPosition] = arr[maxPosition], arr[i]
