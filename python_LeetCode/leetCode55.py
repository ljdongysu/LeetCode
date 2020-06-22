def leet55(numList:list):
    maxlength = 0
    for i in range(len(numList)-1):
        maxlength = max(maxlength,numList[i]+i)
        if maxlength <= i:
            return False
    return True


print(leet55([2,3,1,1,4]))
print(leet55([3,2,1,0,4]))