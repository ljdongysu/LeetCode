def reorderLogFiles( logs):
    """
    :type logs: List[str]
    :rtype: List[str]
    """
    digitLog = []
    letterLog = []
    for s in logs:
        if s.split(" ")[1][0].isdigit():
            digitLog.append(s)
        if  s.split(" ")[1][0].isalpha():
            letterLog.append(s)
    letterLog = sorted(letterLog,key=lambda s:s.split(" ")[0])
    letterLog = sorted(letterLog,key=lambda s:" ".join(s.split(" ")[1:]))
    logs = letterLog + digitLog
    return logs
a = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
print(reorderLogFiles(a))