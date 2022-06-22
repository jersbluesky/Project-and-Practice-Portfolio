def are_reverses(string_1, string_2):
    reverse_string_1 = ""
    for i in range(len(string_1)):
        reverse_string_1 += string_1[-i-1]
    print(reverse_string_1)
    if reverse_string_1 == string_2:
        answer = True
    else:
        answer = False
    return answer

print('Are "ABC" and "CBA" reverses of each other? (Should be True.)')
are_reverses("ABC", "CBA")