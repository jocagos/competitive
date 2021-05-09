def solution(data, n):
    ans = [0] * len(data)
    d = dict()
    for val in data:
        if val not in d:
            d[val] = 1
        else:
            d[val] += 1
    idx = 0
    for val in data:
        if d[val] 
