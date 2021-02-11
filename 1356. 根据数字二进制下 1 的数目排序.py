#1356. 根据数字二进制下 1 的数目排序
def sortByBits(arr) :
    return sorted(arr,key = lambda i: (bin(i).count('1') , i) )