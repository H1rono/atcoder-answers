from math import floor

price = floor(1.08 * int(input()))
print("Yay!" if price < 206 else "so-so" if price == 206 else ":(")