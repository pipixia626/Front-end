# RIP 路由信息协议

属于网络层，其主要应用于规模较小的、可靠性要求较低的网络，可以通过不断的交换信息让路由器动态的适应网络连接的变化，这些信息包括每个路由器可以到达哪些网络，这些网络有多远等。

缺点：收敛慢和支持的广播网络规模有限

相对于BGP协议来说，并不知道网络的拓扑结构是怎么样的，一旦中间出现了差错，信息传递就会出现问题


## 原理
通过跳数来衡量到达目的网络的距离
