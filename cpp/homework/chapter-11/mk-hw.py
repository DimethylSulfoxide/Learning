import os, sys, re
import zipfile
from docx import Document
from docx import shared
os.chdir(sys.path[0])
HEI = 8.24
pt1 = r'^([0-9]+\-[0-9]+).*(cpp)$'
pt2 = r'^([0-9]+\-[0-9]+)'
cpt1 = re.compile(pt1)
cpt2 = re.compile(pt2)

dl = []
fl = []
for r, d, f in os.walk('.'):
    for i in f:
        if cpt1.match(i):
            fl.append(i)
            dl.append(cpt2.match(i).group())
        pass
dl.sort()
ds = list(set(dl))
ds.sort()
dfd = {}
for i in dl:
    if i not in dfd.keys():
        dfd[i] = []
    for j in fl:
        if re.match(i, j):
            dfd[i].append(j)
for i in dl:
    dfd[i] = list(set(dfd[i]))
    dfd[i].sort()
# for k, v in dfd.items():
#     print(k, ' : ', v)
for i in ds:
    os.mkdir(i)
for k, v in dfd.items():
    for i in v:
        os.system("cp "+ i + " ./" + k )
    pass
for k, v in dfd.items():
    doc = Document()
    for i in v:
        doc.add_picture(i.split('.')[0] + '.png', height = shared.Cm(HEI))
    doc.save(k + '/' + k + '.docx')
a2c = {5:'五', 6:'六', 7:'七', 8:'八', 9:'九', 10:'十', 11:'十一'}
fn = '苏俊峰01043第T章作业.zip'
c = dl[0].split('-')[0]
fn = fn.replace('T', a2c[int(c)])
f = zipfile.ZipFile(fn, 'w', zipfile.ZIP_DEFLATED)
for k, v in dfd.items():
    f.write(k)
    for i in v:
        f.write(k + '/' + i, k + '/' + i)
    f.write(k + '/' + k + '.docx', k + '/' + k + '.docx')
for k in dfd.keys():
    os.system('rm -rf ' + k)
f.close()
