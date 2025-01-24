import turtle as t
k = 30
for i in range(4):
    t.forward(10*k)
    t.right(90)
t.up()
for x in range(11):
    for y in range(-11,0):
        t.goto(x*k,y*k)
        t.dot(4)
