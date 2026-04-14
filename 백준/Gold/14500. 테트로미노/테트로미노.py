# 회전, 대칭 가능
# 테트로미노 도형 5개 중에 1개만 놓으면 됨

def normalize(shape):
    r, c = zip(*shape)
    min_r = min(r)
    min_c = min(c)
    shifted = sorted((x - min_r, y - min_c) for x, y in shape)
    return tuple(shifted)

def rotate90(shape):
    return normalize(tuple((c, -r) for r, c in shape))

# 상하 대칭
def vertical_symmetry(shape):
    return normalize(tuple((-r, c) for r, c in shape))

# 좌우 대칭
def symmetry(shape):
    return normalize(tuple((r, -c) for r, c in shape))


def can_place(x, y, shape):  # (i, j)를 기준점으로 해서 k번째 도형을 배치할 수 있는 경우
    if all(0 <= r + x < N and 0 <= c + y < M for r, c in shape):
        return True
    return False
            
def place(grid, x, y, shape):
    cnt = 0
    for r, c in shape:    
        cnt += grid[r + x][c + y]
    return cnt

tetromino = set()
tetromino.add(((0,0), (0,1), (0,2), (0,3)))
tetromino.add(((0,0), (0,1), (1,0), (1,1)))
tetromino.add(((0,0), (1,0), (2,0), (2,1)))
tetromino.add(((0,0), (1,0), (1,1), (2,1)))
tetromino.add(((0,0), (0,1), (0,2), (1,1)))

# 가능한 모든 도형 모양 만들기
all_shapes = set()
for base in tetromino:
    cur = base

    # base 도형에 대해, 기본 + 회전 + 대칭
    for _ in range(4):
        all_shapes.add(cur)
        all_shapes.add(vertical_symmetry(cur))
        all_shapes.add(symmetry(cur))
        cur = rotate90(cur)

# print(*all_shapes, sep='\n')


N, M = map(int, input().split())
grid = [[] for _ in range(N)]

for i in range(N):
    grid[i] = list(map(int, input().split()))


max_value = 0

for i in range(N): # 500
    for j in range(M): # 500 
        for shape in all_shapes: # 아마 38개
            if can_place(i, j, shape): # (i, j)를 기준점으로 해서 도형을 배치할 수 있는 경우
                value = place(grid, i, j, shape)
                max_value = max(max_value, value)
                # print(f"(i, j) : ({i}, {j}), max_value : {max_value}, value : {value}, idx: {k}")

print(max_value)