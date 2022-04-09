def main():
    goods_num, coupon_num, coupon_price = map(int, input().split())
    goods_prices = list(map(int, input().split()))
    discounted_prices = []
    used_coupon_num = 0
    for price in goods_prices:
        using_coupon_num, dis_price = divmod(price, coupon_price)
        used_coupon_num += using_coupon_num
        discounted_prices.append(dis_price)
    coupon_num -= used_coupon_num
    if coupon_num <= 0:
        sum_price = sum(discounted_prices) - coupon_num * coupon_price
        print(sum_price)
        return
    discounted_prices = sorted(discounted_prices)
    if coupon_num >= goods_num:
        print(0)
        return
    sum_price = sum(discounted_prices[:-coupon_num])
    print(sum_price)


main()