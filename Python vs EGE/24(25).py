f = open("D:/pythonProject/24(25).txt")
s = f.read()
s = s.replace("XZZY", " ")
a = [len(x) for x in s.split()]
print(max(a)+6)