

def minLength(squareList):
    if len(squareList) == 1:
        return squareList[0][0]
    for i in range(1,len(squareList)):

        for j in range(len(squareList[0])):
            temp = squareList[i - 1][ j]
            if j > 0:
                temp = min(temp,squareList[i][j-1])
            if j < len(squareList[0])-1:
                temp = min(temp,squareList[i][j+1])
            squareList[i][j] += temp
    minpath = squareList[len(squareList)-1][0]
    for i in range(1,len(squareList[0])):
        minpath = min(minpath,squareList[len(squareList)-1][i])
    return minpath
a = [[1,2,3],[4,5,6],[7,8,9]]
print(minLength(a))