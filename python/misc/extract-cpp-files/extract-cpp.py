import re
pbnum = 0
f = open('./题库450题.txt', 'r')
p = r'第[0-9]*题'
cp = re.compile(p);
fs = f.read()
print(len(cp.findall(fs)))
