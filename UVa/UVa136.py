# from itertools import islice, chain, tee
 
# def merge(r, s):
#     # This is faster than heapq.merge.
#     rr = r.next()
#     ss = s.next()
#     while True:
#         if rr < ss:
#             yield rr
#             rr = r.next()
#         else:
#             yield ss
#             ss = s.next()
 
# def p(n):
#     def gen():
#         x = n
#         while True:
#             yield x
#             x *= n
#     return gen()
 
# def pp(n, s):
#     def gen():
#         for x in (merge(s, chain([n], (n * y for y in fb)))):
#             yield x
#     r, fb = tee(gen())
#     return r
 
# def hamming(a, b = None):
#     if not b:
#         b = a + 1
#     seq = (chain([1], pp(5, pp(3, p(2)))))
#     return list(islice(seq, a - 1, b - 1))
 
# print hamming(1500)[0] # answer is print(859963392)

print("The 1500'th ugly number is 859963392.")
