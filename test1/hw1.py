def canWin(nums, l, r, memo):
    if l > r:
        return 0
    if (l, r) in memo:
        return memo[(l, r)]
    pickLeft = nums[l] - canWin(nums, l + 1, r, memo)
    pickRight = nums[r] - canWin(nums, l, r - 1, memo)
    memo[(l, r)] = max(pickLeft, pickRight)
    return memo[(l, r)]

def PredictTheWinner(nums):
    memo = {}
    return canWin(nums, 0, len(nums) - 1, memo) >= 0

N = int(input().strip())
nums = list(map(int, input().strip().split()))

if PredictTheWinner(nums):
    print("true")
else:
    print("false")


