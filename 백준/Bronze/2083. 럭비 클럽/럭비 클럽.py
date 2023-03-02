while True:
    inp = input().split()
    
    if inp[0] == '#':
        break
    else:
       if (int(inp[1]) > 17) or (int(inp[2]) >= 80):
           print(f'{inp[0]} Senior')
       else:
           print(f'{inp[0]} Junior') 