def find_fewest_coins(coins, target):
    if target < 0:
        raise ValueError("target can't be negative")
    if target == 0:
        return []

    dp = [None] * (target + 1)
    dp[0] = []

    for i in range(1, target + 1):
        for coin in coins:
            if i - coin >= 0 and dp[i - coin] is not None:
                potential_combination = dp[i - coin] + [coin]
                
                if dp[i] is None or len(potential_combination) < len(dp[i]):
                    dp[i] = potential_combination

    if dp[target] is None:
        raise ValueError("can't make target with given coins")

    return sorted(dp[target])