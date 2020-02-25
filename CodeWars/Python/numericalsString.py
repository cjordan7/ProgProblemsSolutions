
# You are given an input string.

# For each symbol in the string if it's the first character occurrence, replace it
# with a '1', else replace it with the amount of times you've already seen it...


# But will your code be performant enough?



def numericals(s):
    numbers = {}
    string = ""
    for i in s:
        if i in numbers:
            numbers[i] += 1
        else:
            numbers[i] = 1
        string += str(numbers[i])
    return string
