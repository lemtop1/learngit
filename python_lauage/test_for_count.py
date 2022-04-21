import math

#需要两个函数,一个计算阶乘,一个计算各项结果
#阶乘好像有了,叫factorial

def count(k,n,p):
    ProbDF = 0
    for i in range(0,n):
        Value = math.factorial(n)/(math.factorial(i)*math.factorial(n-i))*(p**i)*(1-p)**(n-i)
        print(Value)
        ProbDF += Value
        print(ProbDF)

if __name__ == "__main__":
    k,n,p = int(input("k")),int(input("n")),float(input("p"))
    print(count(k,n,p))

