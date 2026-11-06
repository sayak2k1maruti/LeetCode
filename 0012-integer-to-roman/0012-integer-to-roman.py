class Solution:
    def intToRoman(self, num: int) -> str:
        mapping = (
            (1000,'M'),
            (900 ,'CM'),
            (500,'D'),
            (400,'CD'),
            (100,'C'),
            (90,'XC'),
            (50,'L'),
            (40,'XL'),
            (10,'X'),
            (9,'IX'),
            (5,'V'),
            (4,'IV'),
            (1,'I')
        )
            
        ans = []
        # while num>0:
        #     for n,r in mapping:
        #         if n <= num:
        #             ans.append(r)
        #             num -= n
        #             break
        # return ''.join(ans)
        for n,r in mapping:
            if not num:
                break
            count = num//n
            ans.append(r*count)
            num -= count * n
        return ''.join(ans)
        