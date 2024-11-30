
def sum(x, y):
    return x + y

print(sum(3, 4))

lst = [1, 2, 3, 4, 5]
print(lst[0])
print(len(lst))

for x in lst:
    print(x)

# for(int i = 0 ; i < lst.size() ; ++i) {
# int x = lst[i];
# cout << x << endl;
#}


for i in range(len(lst)): # for(int i = 0 ; i < lst.size() ; ++i)
    print(lst[i])

# range(4) -
> [0, 1, 2, 3]