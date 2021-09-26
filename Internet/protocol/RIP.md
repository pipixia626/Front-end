# Border group protocol

## 基本概念

自治系统AS(Autonomous System)
指在一个实体管辖下的拥有相同选路策略的IP网络
BGP网络中的每一个AS都被分配一个唯一的AS号用于区分不同的AS


## 分类
按照运行方式分为EBGP(External/Exiterior BGP)和IBGP(internal/Interior BGP)

### EBGP
运行于不同AS之间的BGP，为了防止AS产生环路，当BGP设备接收EBGP对等体发生的路由时，会将带有本地AS号的路由丢弃

### IBGP
运行于同一AS内部的BGP称为IBGP，为了防止AS内产生环路，BGP设备不将从IBGP对等体学到的路由通告给其他IBGP对等体

## BGP工作原理
通过对等体的建立，更新和删除等交互过程
主要有5种报文，6种状态机和5个原则

