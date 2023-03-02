vowel = 'aeiouAEIOU'

while 1 :
    inp = input()
    cnt = 0
    
    if inp == '#':
        break
    else:
        for i in inp:
            if i in vowel:
                cnt += 1
    print(cnt)