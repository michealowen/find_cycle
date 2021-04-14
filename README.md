![alt sss](find_cycle.jpg)

# 寻找有向图中给定长度的环

## 1.已办与待办事项
### 已办
- [x] 项目架构 C++、 cmake、cygwin
- [x] Tiernan算法实现

> Tiernan J C. An efficient search algorithm to find the elementary circuits of a graph[J]. Communications of the ACM, 1970, 13(12): 722-726.

- [x] Johnson算法实现及调优


> Johnson D B. Finding all the elementary circuits of a directed graph[J]. SIAM Journal on Computing, 1975, 4(1): 77-84.

### 待办
- [ ] Weinblatt 算法实现(与Tiernan应该区别不大)


> Weinblatt H. A new search algorithm for finding the simple cycles of a finite directed graph[J]. Journal of the ACM (JACM), 1972, 19(1): 43-56.

- [ ] Tarjan 算法实现


> Tarjan R. Enumeration of the elementary circuits of a directed graph[J]. SIAM Journal on Computing, 1973, 2(3): 211-216.
- [ ] Szwarcfiter and Lauer  算法实现

> Szwarcfiter J L, Lauer P E. A search strategy for the elementary cycles of a directed graph[J]. BIT Numerical Mathematics, 1976, 16(2): 192-204.

- [ ] K.A. Hawick and H.A. James∗算法实现



> Hawick K A, James H A. Enumerating Circuits and Loops in Graphs with Self-Arcs and Multiple-Arcs[C]//FCS. 2008: 14-20.
- [ ] 王玉英、陈平、苏旸 算法实现
> [1]王玉英,陈平,苏旸.生成有向图中全部简单回路的一种新算法[J].陕西师范大学学报(自然科学版),2008(04):12-15.

- [ ] 各种算法寻找指定长度环的变种

## 2. 项目语言及环境

- 语言:C++ 11
- 平台:Cygwin 或 linux(Ubuntu)
- 项目依赖: boost
## 3.项目目录结构

- src:源代码目录
- - app:可执行文件的代码
- - algorithm:各个算法
- - io:IO库
- - network: 核心数据结构
- - util: debug工具
- - test: 测试
- build:编译目录
- CmakeLists.txt: cmake 文件
- data: 图数据
## 4.项目编译与执行
### 编译


```c
cd build
cmake ..
make
```

### 执行
编译共得到三个可执行文件
- **find_cycle.exe:找环算法**
- **generate.exe:生成图**
- **test.exe:执行测试**

执行命令


- **找环**
```c
/* 执行找环算法 */
cd build
// 第一个参数为使用算法名,john代表Johnson算法
// 第二个参数为使用数据,data目录下的n20_e70/n20_e70.txt
./find_cycle.exe john ../data/n20_e70/n20_e70.txt
```
|算法简称| 算法 |
|--|--|
| john | Johnson算法 |
| tiernan | TIernan算法 |
| tarjan| Tarjan算法 |
- **生成图**
```c
/* 执行生成图算法 */
cd build
// 在data下新建一个目录
mkdir ../data/n10_e20
// 第一个参数图的顶点数
// 第二个参数图的边数量
// 第三个参数为数据存放目录
// 下面命令生成了 10个顶点 20个边的图
./generate.exe 10 20 ../data/n10_e20/n10_e20.txt
```
- **测试**
```c
/* 执行测试 */
cd build
./test
```
