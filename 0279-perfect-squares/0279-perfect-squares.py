class Solution:
    def numSquares(self, n: int) -> int:
        ans = 0
        acc = 0
        squares = [i*i for i in range(floor(sqrt(n)),0,-1)]
        @cache
        def bfs(s):
            if s == n:
                return 0
            ans = []
            for num in squares:
                if s+num <= n:
                    ans.append(bfs(s+num))
            #print(ans)
            return 1 + min(ans)
        return bfs(0)


        