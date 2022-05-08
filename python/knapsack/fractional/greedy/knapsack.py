class ItemValue:
    def __init__(self, profit, weight, index):
        self.index = index
        self.profit = profit
        self.weight = weight
        self.cost = profit // weight

    def __lt__(self, other):
        return self.cost < other.cost


def calculate_max_value(weights, values, capacity):
    items = []
    for i in range(len(weights)):
        items.append(ItemValue(weights[i], values[i], i))

    # sorting items by value
    items.sort(reverse=True)

    total_value = 0
    for i in items:
        current_weight = int(i.weight)
        current_profit = int(i.profit)

        if capacity - current_weight >= 0:
            capacity -= current_weight
            total_value += current_profit
        else:
            fraction = capacity / current_weight
            total_value += current_profit * fraction
            capacity = int(capacity - (current_weight * fraction))
            break

    return total_value


def main():
    weights = [10, 40, 20, 30]
    values = [60, 40, 100, 120]
    capacity = 50

    max_value = calculate_max_value(weights, values, capacity)
    print("Maximum value in Knapsack =", max_value)


if __name__ == "__main__":
    main()
