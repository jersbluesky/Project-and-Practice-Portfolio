def longestCommonPrefix(strs):
    arr=sorted(strs,key=len)
    result=""
    for i in range(len(arr[0])):
        for j in range(1,len(arr)):
            if arr[0][i]!=arr[j][i]:
                return result
        result+=arr[0][i]
    return result

strs = ["flower","flow","flight"]
result = longestCommonPrefix(strs)
print(result)