from collections import Counter
class Solution:
    def buildMap(self,s,words):
        mp = {}

        for word in set(words):
            index = 0
            while True:
                i = s.find(word,index)
                if i == -1:
                    break
                mp[i] = word
                index =i + 1
        return mp
        
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        mp = self.buildMap( s,words )
        k = len(words[0])
        i,j = 0,0
        ans = []
        wordM = Counter(words)
        for start in range(k):
            i = j = start
            used = {**wordM}
            count = 0
            for j in range(i,len(s) -k + 1,k):
                if j not in mp:
                    used = {**wordM}
                    i = j+k
                    count = 0
                    continue
                if used[mp[j]]:
                    used[mp[j]] -= 1
                    count += 1
                else:
                    while mp[i] != mp[j]:
                        used[mp[i]] += 1
                        count -=1
                        i += k
                    i+=k
                # if not any(ii for ii in used.values()):
                #     ans.append(i)
                if count == len(words):
                    ans.append(i)
        # for i in range(len(s) - len(words)*k + 1):
        #     if i not in mp:
        #         continue
        #     used = {**wordM}
        #     j = i
        #     flag = True
        #     while j < len(s) :
        #         if j not in mp:
        #             break
        #         elif not used[mp[j]]:
        #             break
        #         else:
        #             used[mp[j]] -=1
        #             j+=k
        #     if not sum(i for i in used.values()):
        #         ans.append(i)
        return ans
