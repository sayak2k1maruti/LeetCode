class Solution:
    def simplifyPath(self, path: str) -> str:
        ans = ['']
        for p in path.split('/'):
            match p:
                case '..':
                    ans.pop()
                case '.':
                    continue
                case '':
                    continue
                case _:
                    ans.append(p)
            if not ans:
                ans.append("")
        ans = '/'.join(ans)
        return ans if ans else "/"

        