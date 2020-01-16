def sub_sort(array, low, high):
    pivotkey = array[low]
    while low < high:
        while low < high and array[high] >= pivotkey:
            high -= 1
        array[low] = array[high]
        while low < high and array[low] <= pivotkey:
            low += 1
        array[high] = array[low]
    array[low] = pivotkey
    return low


def quick_sort(array, low, high):
    if low < high:
        pivoloc = sub_sort(array, low, high)
        quick_sort(array, low, pivoloc - 1)
        quick_sort(array, pivoloc + 1, high)


if __name__ == "__main__":
    array = [49, 38, 65, 97, 76, 13, 27]
    print
    array
    quick_sort(array, 0, len(array) - 1)
    print
    array
