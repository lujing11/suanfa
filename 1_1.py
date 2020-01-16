l = [2, 3, 5, 10, 15, 16, 18, 22, 26, 30, 32, 35, 41, 42, 43, 55, 56, 66, 67, 69, 72, 76, 82, 83, 88]
def seek(l,arg,start = 0,end = None):#关键字参数end默认为空
    end = len(l) if end == None else end#如果为空，第一次进来用列表l的原始长度，不为空则用上一个end的值
    if start < end:
        long = (end - start) // 2 + start
        if l[long] < arg:
            return seek(l,arg,start = long+1,end = end)
        elif l[long] > arg:
            return seek(l,arg,start = start,end = long-1)
        else:
            return '找到了，{}的位置在{}号'.format(l[long],long)#递归的返回值是逐级向上返回，所以需要每个条件都return
    else:
        return '未查到'

print(seek(l,18))