s = "1"+"9"*127 #Пример как записывать
while "333" in s or "999" in s:
    if "333" in s:
        s = s.replace("333","9",1)
    else:
        s = s.replace("999","3",1)
print(s)