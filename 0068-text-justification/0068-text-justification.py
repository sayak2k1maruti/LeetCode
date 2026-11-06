class Solution:
    def fullJustify(self, words: list[str], maxWidth: int) -> list[str]:
        ans = []
        i = 0
        line = []
        count_word = 0
        count_letter = 0
        space_extra = maxWidth
        def arrange_space(line,count_word,extra_space):
            space = extra_space // (count_word - 1) if count_word > 1 else 0
            reminder = extra_space % (count_word - 1) if count_word > 1 else 0
            strl  = ''
            if reminder:
                s = ' '*(space+1)
                s_ = ' '*space
                strl = s.join(line[:reminder+1]) + s_ +s_.join(line[reminder+1:])
            else:
                s = ' '*space
                strl = s.join(line)
            strl += ' '*(maxWidth -len(strl))
            return strl
            
                
        while i < len(words):
            
            if len(words[i]) <= space_extra:
                count_word += 1
                count_letter += len(words[i])
                space_extra -= (len(words[i]) + 1) # +1 for space
                line.append(words[i])
                i+=1
            else:
                line_str = ''
                space_extra += len(line)
                ans.append(arrange_space(line,count_word,space_extra))
                line.clear()
                count_word = 0
                count_letter = 0
                space_extra = maxWidth
            
        if line:
            temp = ' '.join(line)
            ans.append(
                temp + ' ' * (maxWidth - len(temp))
            )
            #ans.append(arrange_space(line,count_word,space_extra))
        return ans

        