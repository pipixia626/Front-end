# OSPF open shortest path first 开放最短路径优先

## 简介
是一种链路状态路由协议，无路由循环，全局拓扑

OSPF 采用SPF (最短路由算法)计算到达目的地最短路径

## 算法
美国路由器都把自己当作根，并且基于累积成本(cost值)来计算到达目的地的最短路径

cost= 参考带宽/接口带宽

### OSPF报文类型

1.  Hello 建立和维护OSPF邻居关系
2.  DBD 链路状态数据库描述信息
3.  LSR 链路状态请求，向OSPF邻居请求链路状态信息
4.  LSU 链路状态更新
5.  LSAck 对LSU的LSA进行确认

#### OSPF区域性进行泛洪

区域分为主干区域和下层区域
这样每个区域内部的所以路由器经过泛洪后，就能知道本区域内的网络拓扑结构，之后通过区域边界路由器概括后再与主干路由器交换信息（注：主干路由器就是位于主干区域的路由器，它们同时也可以作为区域边界路由器。），这样这些区域构成的自治系统就完成系统的网络拓扑图的构建，而再与其他自治系统的交流时，只需要有一个主干路由器作为自治系统边界路由器就能与其他自治系统交流


### OSPF的三张表

- 邻居表 
OSPF用邻居机制来发现和维持路由的存在，邻居表存储了双向通信的邻居关系OSPF路由器列表的信息

- 拓扑表
 OSPF采用LSA 链路状态通告来描述网络拓扑信息，然后OSPF路由器用拓扑数据库来存储网络这些LSA

- OSPF路由表
对链路状态数据进行SPF 计算，而得出OSPF路由表

### 基本运行步骤

1. 建立邻接关系
2. 必要时候进行DR的选举
3. 发现路由
4. 选择合适的路由器
5. 维护路由信息


