def beautyarray(Num):
    res = list([1])
    while(len(res)<Num):
        templist = []
        for i in res:
            if 2*i-1 <= Num:
                templist.append(2*i-1)
        for i in res:
            if 2*i <= Num:
                templist.append(2*i)
        res = templist
    return res
print(beautyarray(5))

