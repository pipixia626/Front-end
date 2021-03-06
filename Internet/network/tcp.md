# TCP/IP

## TCP（Transmission Contrl Protocol 传输控制协议)
能够在多个不同网络实现信息传输的协议簇

### 特性

<strong>TCP是一种面向连接的、可靠的字节流服务</strong>

<strong>在一个TCP连接中，仅有两方进行彼此通信，广播和多播不能用于TCP</strong>

<strong>TCP使用校验和，确认和重传机制来保证可靠传输</strong>

<strong>TCP给数据分段进行排序，并使用累积确认保证数据的顺序不变和非重复</strong>

<strong>TCP使用滑动窗口机制来实现流量控制，通过动态改变窗口的大小进行拥塞控制</strong>

TCP 并不能保证数据一定会被对方接收到，因为这是不可能的。TCP 能够做到的是，如果有可能，就把数据递送到接收方，否则就（通过放弃重传并且中断连接这一手段）通知用户。因此准确说 TCP 也不是 100% 可靠的协议，它所能提供的是数据的可靠递送或故障的可靠通知

### TCP报文的头部结构
Source port 16   destination port 16

          seq 32
          
Data offset 4  Reserved 6  (URG/ACK/PSH/RST/SYS/FIN) windows size 16

CheckSum 16      Urgent Point 16

option 40


序号：seq序号(32),用来标识TCP源端向目的端发送的字节流，发起方发送数据时对此进行标记

确认序号：ack序号(32),只有ACK标志位为1时，确认序号字段才有效 ack=seq+1

标志位 对应上述六个

ACK：确认序号有效

FIN：释放一个连接

PSH：接收方应该尽快将这个报文交给应用层

RST：重置连接

SYN：发起一个新连接

URG：紧急指针（urgent pointer）有效



### 三次握手和四次挥手

#### 三次握手
所谓三次握手，是指建立一个TCP连接时，需要客户端和服务器总共发送3个包

三次握手的目的：确认通信双方收发数据的能力（防止失效的连接请求到达服务器，让服务器错误打开）

第一次握手：客户端发送连接请求，客户端随机生成一个起始序列号seq(假定为100）SYN标志位置1

第二次握手：服务器端收到报文，发现SYN=1，知道这是一个连接请求，于是将客户端的起始序列号100存起来，并且随机生成一个服务端的起始序列号（假定为300）,然后给客户端回复一段报文（报文含SYN和ACK标志位->1)序列号为300，ack=100+1

第三次握手：客户端收到服务端的回复后发现ACK=1并且ack=101，知道服务端已经收到序列号为100的那段报文；同时发现SYN=1，知道服务端同意了这次连接，于是就将服务端的序列号300给存下来，然后客户端再回复一段报文，报文含ACK标志位（ACK=1),ack=300+1,seq=100+1
需要注意的是不携带数据的ACK报文是不占据序列号的，所以后面第一次正式发送数据时seq还是101)。当服务端收到报文后发现ACK=1并且ack=301，就知道客户端收到序列号为300的报文了，就这样客户端和服务端通过TCP建立了连接。

#### 四次挥手
目的：关闭一个连接
假定：比如客户端初始化的序列号ISA=100，服务端初始化的序列号ISA=300。TCP连接成功后客户端总共发送了1000个字节的数据，服务端在客户端发FIN报文前总共回复了2000个字节的数据。

第一次挥手：当客户端的数据都传输完成后，客户端向服务端发出连接释放报文，释放连接报文含FIN=1，序列号=100+1+1000（其中的1是建立连接时占的一个序列号,客户端发出FIN报文段后不能发数据，但可以正常接收数据，FIN报文段即使不携带数据也要占据一个序列号

第二次挥手：服务端收到客户端发的FIN报文后，给客户端回复确认报文，确认报文包含ACK标志位（ACK=1)，确认序号ack=1101+1,序列号=2000+300
，此时服务端处于关闭等待状态，而不是给客户端发送FIN报文，这个状态还要持续一段时间，因为服务端可能还有数据没有发完

第三次挥手，服务端将最后数据（比如50个字节）发送完毕后，就向客户端发送连接释放报文，FIN=1,ACK=1,确认号和第二次挥手那样1102，序列号2000+300+50

第四次挥手，客户端收到服务端发送的FIN报文后，向服务端发出确认报文，ACK=1,ack=2350+1,seq=1102注意客户端发出确认报文后不是立马释放TCP连接，而是要经过2MSL(最长报文段寿命的2倍时长)后才释放TCP连接。而服务端一旦收到客户端发出的确认报文就会立马释放TCP连接，所以服务端结束TCP连接的时间要比客户端早一些


#### 为什么是三次握手和四次挥手

因为需要考虑连接时丢包的问题，如果只握手2次，第二次握手时如果服务端发给客户端的确认报文段丢失，此时服务端已经准备好了收发数(可以理解服务端已经连接成功)据，而客户端一直没收到服务端的确认报文，所以客户端就不知道服务端是否已经准备好了(可以理解为客户端未连接成功)，这种情况下客户端不会给服务端发数据，也会忽略服务端发过来的数据。

因为只有在客户端和服务端都没有数据要发送的时候才能断开TCP。而客户端发出FIN报文时只能保证客户端没有数据发了，服务端还有没有数据发客户端是不知道的。而服务端收到客户端的FIN报文后只能先回复客户端一个确认报文来告诉客户端我服务端已经收到你的FIN报文了，但我服务端还有一些数据没发完，等这些数据发完了服务端才能给客户端发FIN报文(所以不能一次性将确认报文和FIN报文发给客户端，就是这里多出来了一次)








## IP
