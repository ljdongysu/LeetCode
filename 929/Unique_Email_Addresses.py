a = list(["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"])
res = []
for temp in a:
    temp1 = temp.split("@")[0]
    temp2 = temp.split("@")[1]
    temp1 = "".join(temp1.split("."))
    temp1 = temp1[0:temp1.rfind('+',1)]
    if temp1+'@'+temp2 not in res:
        res.append(temp1+'@'+temp2)
print(len(res))
