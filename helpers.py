from nltk.tokenize import sent_tokenize


def lines(a, b):
    """Return lines in both a and b"""
    return set(a.split("\n")).intersection(set(b.split("\n")))


def sentences(a, b):
    """Return sentences in both a and b"""
    return set(sent_tokenize(a, language="english")).intersection(set(sent_tokenize(b, language="english")))


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""
    subs_a = set()
    subs_b = set()
    for i in range(len(a)-(n-1)): 
        subs_a.add(a[i:i+n])
    for i in range(len(b)-(n-1)): 
        subs_b.add(b[i:i+n])
    return subs_a.intersection(subs_b)