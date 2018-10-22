# 由两种遍历还原树

## 思路

使用递归实现，每次判断出左子树右子树，然后让每个子树作为树根继续判断。

## 以顺序数组输出的方式

用队列实现，每次先左后右节点入队，然后依次出对，每一个节点出对让其子节点入队。  
注意先将出对的节点存储值存入数组中，因为对于 `nullptr` 需要存入一个特殊标记占位，且每次 `nullptr` 出对都需要让两个 `nullptr` 入队，所以在队列循环条件处需要加入一个队尾小于队长的判断，防止无限循环。

```C++
int i = 0;
while (rear < max_size && front != rear) {
    if (queue[front] != nullptr) {
        queue[rear++] = queue[front]->left;
        queue[rear++] = queue[front]->right;
        ret[i++] = queue[front++]->val;
    } else {
        ret[i++] = '@';
        queue[rear++] = nullptr;
        queue[rear++] = nullptr;
        front++;
    }
}
int k = 0;
for (int j = 0; j < i; j++) {
    if (ret[j] != '@') {
        for (int l = 0; l < k; l++) {
            std::cout << "NULL ";
        }
        std::cout << ret[j] << " ";
        k = 0;
    } else
        k++;
}
```