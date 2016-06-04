### Solution method
构建Trie树求解问题！
以下面的例子说明问题：

    01000
    01110
    10010
    10110
    10111

构建的Tried树为：
![](https://github.com/getomoko/algorithms/blob/master/Character_Recognition/Trie.jpg)

所需的最小数目也就图中的圆圈数目，其中同层的圆圈只计算一次，因此本题需要的最小数目为3.

分别是第一层，第三层，第五层
将这五个数的1,3,5号数取出：

    000
    010
    100
    110
    111
   
可以区分这五个数！

圆圈标识了分叉的位置，因此这个位置的数据必须要取出，就是这个道理。