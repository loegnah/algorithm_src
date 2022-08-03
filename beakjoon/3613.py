#orgWord = 'b_b_aAA_a'
orgWord = input()

def changeUp(word):
    return chr(ord(word)-32)
def changeDown(word):
    return chr(ord(word)+32)
def isDownWord(word):
    return 'a'<=word and word<='z'
def checkCpp(idx):
    if idx==0 or idx==len(orgWord)-1:
        return False
    if isDownWord(orgWord[idx-1]) and isDownWord(orgWord[idx+1]):
        return True
    return False

isCpp = False
isJava = False
isError = False

for i in range(len(orgWord)):
    w = orgWord[i]
    if w == '_':
        if checkCpp(i):
            isCpp = True
        else:
            isError = True
    elif 'A'<=w and w<='Z':
        isJava = True
    elif w<'a' or w>'z':
        isError = True

ans = ''

if (isCpp and isJava) or isError:
    print("Error!")
elif orgWord[0]<='Z':
    print("Error!")
elif (not isCpp and not isJava):
    print(orgWord)
elif isCpp:
    stt = False
    for w in orgWord:
        if w == '_':
            stt = True
        elif stt:
            stt = False
            ans += changeUp(w)
        else:
            ans += w
    print(ans)
else:
    for w in orgWord:
        if w < 'a':
            ans += '_' + changeDown(w)
        else:
            ans += w
    print(ans)
