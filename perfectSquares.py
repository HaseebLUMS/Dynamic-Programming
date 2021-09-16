class Solution(object):
    memo = {}
    memo[1] = 1
    def getPerfectSquaresList(self, n):
        res = []
        for i in range(1, n+1):
            tmp = i*i
            if tmp > n:
                return res
            if tmp <= n:
                res = res + [tmp]
        return res

    def numSquares(self, n):
        perfectSquaresList = self.getPerfectSquaresList(n)
        return self.solve(n, perfectSquaresList)

    def solve(self, n, perfectSquaresList):
        if n in self.memo:
            return self.memo[n]

        res = []

        if n == 0: 
            return 0

        for i in perfectSquaresList:
            if n-i < 0:
                continue
            res = res + [1 + self.solve(n-i, perfectSquaresList)]
        # if len(res) < 1:
        #     return 0
        ans = min(res)
        self.memo[n] = ans
        return ans
        


s = Solution()
print(s.numSquares(42))