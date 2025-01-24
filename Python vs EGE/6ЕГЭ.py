import turtle as t
k = 30
t.pensize(3)
for i in range(4):
    t.forward(12*k)
    t.right(90)
for i in range(3):
    t.forward(12*k)
    t.right(120)
t.up()
for x in range(0,13):
    for y in range(-12,1):
        t.goto(x*k,y*k)
        t.dot()
t.done()