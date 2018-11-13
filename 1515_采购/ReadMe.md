# 思路

## 我的递归思路

- 将 (begx,begy) 染色（赋值 5）
- 判断 `begx == endx, begy == endy` ，如果成立，输出 count 即步数
- 否则判断四个方向是否为死路或者已经走过的路，如果不是，执行递归 `find_shortest(begx',begy',endx,endy);`
- 如果四个方向均为死路或者已经走过的路，返回 -1
- 取四个方向返回结果的非负最小值即可

即 shorest = min{ shortest_1, shortest_2, shortest_3, shortest_4 }

## BFS 算法（广度优先）
