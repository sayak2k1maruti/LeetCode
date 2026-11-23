class ProductOfNumbers:

    def __init__(self):
        self.products = [1]

    def add(self, num: int) -> None:
        if num == 0:
            self.products = [1]
        else:
            self.products.append(self.products[-1] * num)

    def getProduct(self, k: int) -> int:
        last = len(self.products) - 1 - k 
        return self.products[-1] // self.products[last] if last >= 0 else 0

# Your ProductOfNumbers object will be instantiated and called as such:
# obj = ProductOfNumbers()
# obj.add(num)
# param_2 = obj.getProduct(k)