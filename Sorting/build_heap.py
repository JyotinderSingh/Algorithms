# python3
swaps = []

def parent(i):
    return (i-1)//2

   
def leftChild(i):
    return 2*i + 1


def rightChild(i):
    return (2*i) + 2


def siftUp(data, i):
    while i > 0 and data[parent(i)] > data[i]:
        data[parent(i)], data[i] = data[i], data[parent(i)]
        i = parent(i)


def siftDown(data, i):
    minIndex = i
    l = leftChild(i)
    if l < len(data) and data[l] < data[minIndex]:
        minIndex = l
    
    r = rightChild(i)
    if r < len(data) and data[r] < data[minIndex]:
        minIndex = r

    if i != minIndex:
        # print(i, minIndex)
        data[i], data[minIndex] = data[minIndex], data[i]
        swaps.append((i, minIndex))
        siftDown(data, minIndex)


def build_heap(data):
    """Build a heap from ``data`` inplace.

    Returns a sequence of swaps performed by the algorithm.
    """

    for i in range(len(data)//2, -1, -1):
        siftDown(data, i)


def main():
    n = int(input())
    data = list(map(int, input().split()))
    # assert len(data) == n

    build_heap(data)

    print(len(swaps))
    for i, j in swaps:
        print(i, j)


if __name__ == "__main__":
    main()
