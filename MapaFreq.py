n = len(Text)
for i in range(n-k+1):
    Pattern = Text[i:i+k]
    freq[Pattern] = 0