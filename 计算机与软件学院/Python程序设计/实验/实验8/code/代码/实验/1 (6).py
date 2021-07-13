import math

small_price, medium_price, big_price = 1/3, 3, 5
total_money=100
cnt=0

for i in range(math.ceil(total_money/small_price)):
    for j in range(math.ceil(total_money/medium_price)):
        for k in range(math.ceil(total_money/big_price)):
            if(i*small_price+j*medium_price+k*big_price==100 and i+j+k==100):
                print("小瓶汽水数量:", i, "中瓶汽水数量:", j, "大瓶汽水数量:", k)
                cnt+=1

print("一共有",cnt,"种购买方法")
