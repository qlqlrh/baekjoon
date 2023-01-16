cnt = int(input())

for j in range(cnt):
    
    myinp = input()
    flag = 0 # 앞이 X다.
    num = 1
    total = 0
    
    for i in range(len(myinp)):
                
        if (myinp[i] == 'O' and flag == 0):
            flag = 1 # 앞이 O이다.
            num = 1
            total = total + num
            
        elif (myinp[i] == 'O' and flag == 1):
            num = num + 1
            total = total + num
            
        else:
            flag = 0
            
    print(total)