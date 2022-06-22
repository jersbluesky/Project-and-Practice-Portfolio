def are_reverses_1(string_1, string_2):
    reverse_string_1 = ""
    for i in range(len(string_1)):
        reverse_string_1 += string_1[-i-1]
    print(reverse_string_1)
    if reverse_string_1 == string_2:
        answer = True
    else:
        answer = False
    return answer


def are_reverses_2(string_1, string_2):
    for i in range(len(string_1)):
        if string_1[i] == string_2[-i]:
            return True
        else:
            return False

print('Are "ABC" and "CBA" reverses of each other? (Should be True.)')
are_reverses_1("ABC", "CBA")
are_reverses_2("ABC", "CBA")