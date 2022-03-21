S = list(map(int, input()))
di1 = [0] * 10
di2 = [0] * 4
di3 = [0] * 2

for d in S:
    di1[d] += 1
    di2[d&3] += 1
    di3[d&1] += 1

def out():
    slen = len(S)
    if slen == 1:
        return 'Yes' if not S[0]%8 else 'No'
    if slen == 2:
        n0 = S[0] * 10 + S[1]
        n1 = S[1] * 10 + S[0]
        if (not n0 % 8) or (not n1 % 8):
            return 'Yes'
        return 'No'
    if di1[2]:
        if di2[1] and di3[1] > 1:
            #112
            return 'Yes'
        if di2[3] and di3[0] > 1:
            #32
            return 'Yes'
    if di1[4]:
        if di2[0] > 1 and di3[1]:
            #104
            return 'Yes'
        if di2[2] and di3[0] > 2:
            #24
            return 'Yes'
    if di1[6]:
        if di2[1] and di3[0] > 1:
            #16
            return 'Yes'
        if di2[3] and di3[1] > 1:
            #136
            return 'Yes'
    if di1[8]:
        if di2[0] > 1 and di3[0] > 2:
            #008
            return 'Yes'
        if di2[2] and di3[1] > 1:
            #128
            return 'Yes'
    return 'No'

print(out())