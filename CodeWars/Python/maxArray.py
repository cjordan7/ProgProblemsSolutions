from functools import reduce

def max_product(lst, n_largest_elements):
    lst.sort(reverse = True)
    return reduce(lambda x, y : x * y, lst[:n_largest_elements])
