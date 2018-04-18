s = input()

c = ['b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'z']

def f(l):
    r = []
    for i in range(len(l)):
        if l[i] in c:
            r.append('.')
            r.append(l[i])
        else:
            r.append(l[i])
    return r

l = list(filter(lambda x: x not in ['a','e','i','o','u','y'], list(s.lower())))
l = ''.join(f(l))
print(l)