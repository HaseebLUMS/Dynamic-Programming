class Solution(object):

    memo = {}

    def lastStoneWeightII(self, stones):
        return self.hHastStoneWeightII(sorted(stones))

    def hHastStoneWeightII(self, stones):
        if len(stones) == 1: return stones[0]

        if str(stones) in self.memo:
            return self.memo[str(stones)]
        
        res = []
        for indi, i in enumerate(stones):
            for indj, j in enumerate(stones):
                if indi == indj: continue

                stonesCopy = stones[:]
                stonesCopy[indi] = 101
                stonesCopy[indj] = 101
                stonesCopy = [x for x in stonesCopy if x != 101]
                stonesCopy = self.sortInsert(stonesCopy, self.smash(i, j))

                res += [self.hHastStoneWeightII(stonesCopy)] 
        ans = min(res)
        self.memo[str(stones)] = ans
        return ans

    def smash(self, a, b):
        if b > a:
            return b-a
        return a-b
    def sortInsert(self, arr, a):
        for ind, ele in enumerate(arr):
            if ele > a:
                arr.insert(ind, a)
                return arr
        return arr + [a]


s = Solution()
print(s.lastStoneWeightII([31,26,33,21,40]))