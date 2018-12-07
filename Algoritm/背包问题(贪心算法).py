vv_ww = ((1,6),(5,1),(3,6),(10,6),(3,7))

v_w = []
v = []
w = []

for i in range(5):
    v_w.append(round((vv_ww[i][0] / vv_ww[i][1]),2))

print(v_w)


def combine(outputList, sortList):
    CombineList = list();
    for index in range(len(outputList)):
        CombineList.append((sortList[index],outputList[index]));
    return CombineList;


values = [1, 5, 3, 10, 3]
weights = [6, 1, 6, 6, 7]


index = [0,1,2,3,4];
index_i = []
p = combine(v_w, index);
print(p)
p.sort(key=lambda x: x[1], reverse=True);
print(p)
for i in range(5):
    index_i.append(p[i][0])

max_weights = 12
ii = []


for i in index_i:
    v.append(vv_ww[i][0])
    w.append(vv_ww[i][1])
    if max_weights >= sum(w):
        ii.append(i)
    else:
        print('已达到最大重量，编号',i,'无法添加！')

print(ii)
v_max = 0
for i in ii:
    print('需要添加的物品编号是：',i+1)
    v_max = v_max + vv_ww[i][0]
print('最大价值是：',v_max)
