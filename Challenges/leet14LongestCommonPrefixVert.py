# LEET 14 - 'Easy' - Longest Common Prefix: Vertical Scan
# Write a function to find the longest common prefix string amongst an array of strings.
# If there is no common prefix, return an empty string.

# This code is the product of a study. I began trying to get through the answer myself,
# and when I couldn't get it to pass all of the test cases, I researched the best 
# possible ways to complete this algorithm

"""Function - take the python list as a parameter, then determine the
longest common prefix by comparing the letters in the strings left to right.
This is accomplished using a for loop with another for loop embedded, 
and comparing the parts of the array."""
def longestCommonPrefix(strs):
    # Sorting the array by length makes the code run quicker, so that if there
    # the strings that are shorter than others, they are checked first, at the beginning.
    arr = sorted(strs, key = len)
    result = ""
    for i in range(len(arr[0])):
        for j in range(1,len(arr)):
            if arr[0][i] != arr[j][i]:
                return result
        result += arr[0][i]
    return result

strs = ["flower","flow","flight"]
result = longestCommonPrefix(strs)
print(result)