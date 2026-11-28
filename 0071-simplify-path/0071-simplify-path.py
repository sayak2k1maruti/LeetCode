class Solution:
    def simplifyPath(self, path: str) -> str:
        ans = ['']
        for p in path.split('/'):
            if p == '.' or p == '':
                continue
            elif p == '..':
                ans.pop()
            else:
                ans.append(p)
            if not ans:
                ans.append("")
        ans = '/'.join(ans)
        return ans if ans else "/"

        