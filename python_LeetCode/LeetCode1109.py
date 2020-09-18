def cropFlightBookings(arr:list,n:int):
    result = [0] * (n + 1)
    for subList in  arr:
        if subList[0] < n:
            result[subList[0]] += subList[2]
        if subList[1] + 1<n:
            result[subList[1] + 1] -= subList[2]
        print(result)
    results = []
    results.append(result[1])
    for i in range(n):
        if i == 0:
            continue
        results.append(results[i -1] + result[i + 1])

    return results
print(cropFlightBookings([[1,2,10],[2,3,20],[2,5,25]],5))