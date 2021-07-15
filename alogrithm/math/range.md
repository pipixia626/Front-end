# 取值范围

[a,b]->(rand() % (b-a+1))+ a;

(a,b]->(rand() % (b-a))+ a;

[a,b)->(rand() % (b-a))+ a + 1

# 全排列

next_permutation(a,b)

# 排序

sort(a,b)

# 欧几里德算法又称为辗转相除法，用于计算两个非负整数的最大公因数。
```
gcd(a, b) //要求a>=b
{
  if(b == 0)  return a
  return gcd(b, a % b)
}
```