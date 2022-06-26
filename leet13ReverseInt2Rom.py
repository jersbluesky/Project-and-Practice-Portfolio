
s = input("Enter a number between 1 and 3499: ")
s = str(s)
length = len(s)
romNum = ""

def numPatternLogic(currentRom, midRom, nxtRom, s, digit):
    activeNum = int(s[digit])
    if activeNum == 0:
        return None
    if activeNum < 4 and activeNum > 0:
        return str(currentRom * activeNum)
    elif activeNum == 4:
        return str(currentRom + midRom)
    elif activeNum == 5:
        return str(nxtRom)
    elif activeNum > 5 and activeNum < 9:
        return str(nxtRom + (currentRom * (activeNum - 5)))
    elif activeNum == 9:
        return str(currentRom + nxtRom)

# Apply numPatternLogic to each digit
# # Set the variables (currentRom, midRom, nxtRom) depending on which digit
# # we are working on.

current_array = ["I", "X", "C", "M"]
mid_array = ["V", "L", "D"]

lengthNum = length - 1
digit = 0

while length > 0:
    currentRom = current_array[lengthNum]
    if length < 2:
        midRom = mid_array[lengthNum]
        nxtRom = current_array[lengthNum + 1]
    else: 
        midRom = "D"
        nxtRom = "M"
    addRom = numPatternLogic(currentRom, midRom, nxtRom, s, digit)
    if addRom != None:
        romNum += addRom        
    length -= 1
    digit += 1
    lengthNum -= 1

print(f'The Roman Numeral equivalent for {s} is {romNum}.')
    
    