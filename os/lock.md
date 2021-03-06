#  锁
用在同步机制比较多
为了控制多线访问共享资源时，避免因资源竞争而导致的数据错误了问题，都会在访问共享资源前加锁

## 原子操作
最小的执行单位，在该操作在执行完毕之前绝不会被其他事务或事件打断，需要硬件支持的


## 锁的种类
为了选择合适的锁，我们不仅需要清楚知道加锁的成本开销有多大，
还需要分析业务场景中访问的共享资源的方式，再来还要考虑并发访问共享资源时的冲突概率。

### 互斥锁和 自旋锁
最底层的两种，很多高级锁都是基于它们实现的

互斥锁和自旋锁对于加锁失败后的处理方式不一样

互斥：加锁失败后，线程会释放CPU,
自旋：线程会忙等，直到拿到锁

互斥锁是一种「独占锁」，比如当线程 A 加锁成功后，此时互斥锁已经被线程 A 独占了，只要线程 A 没有释放手中的锁，
线程 B 加锁就会失败，于是就会释放 CPU 让给其他线程，既然线程 B 释放掉了 CPU，自然线程 B 加锁的代码就会被阻塞。

#### 开销成本
两次线程上下文切换的成本
上下切换的耗时有大佬统计过，大概在几十纳秒到几微秒之间，如果你锁住的代码执行时间比较短，那可能上下文切换的时间都比你锁住的代码执行时间还要长。

所以，如果你能确定被锁住的代码执行时间很短，就不应该用互斥锁，而应该选用自旋锁，否则使用互斥锁。
### 读写锁
读写锁的工作原理是：当「写锁」没有被线程持有时，多个线程能够并发地持有读锁，
这大大提高了共享资源的访问效率，因为「读锁」是用于读取共享资源的场景，
所以多个线程同时持有读锁也不会破坏共享资源的数据。但是，一旦「写锁」被线程持有后，
读线程的获取读锁的操作会被阻塞，而且其他写线程的获取写锁的操作也会被阻塞。所以说，写锁是独占锁，
因为任何时刻只能有一个线程持有写锁，类似互斥锁和自旋锁，而读锁是共享锁，因为读锁可以被多个线程同时持有。知道了读写锁的工作原理后，我们可以发现，读写锁在读多写少的场景，能发挥出优势。


### 悲观锁
互斥锁、自旋锁、读写锁都是属于被告锁的
认为多线程同时修改共享资源的概率比较高，于是很容易出现冲突，索引访问共享资源前，先上锁

### 乐观锁
同理，如果多线程同时修改共享资源的概率比较低，可以采用悲观锁
先修改完共享资源，再验证这段时间内有没有发生冲突，如果没有其他线程在修改资源，那么操作完成
如果有，则放弃本次修改。

因此只有才冲突概率非常低，且加锁成本非常高的场景时，才考虑使用乐观锁
例子：
git

