
# def sum(x, y):
#     return x + y

# print(sum(3, 4))

# lst = [1, 2, 3, 4, 5]
# print(lst[0])
# print(len(lst))

# for x in lst:
#     print(x)

# # for(int i = 0 ; i < lst.size() ; ++i) {
# int x = lst[i];
# cout << x << endl;
#}


# for i in range(len(lst)): # for(int i = 0 ; i < lst.size() ; ++i)
#     print(lst[i])

# range(4) -
# [0, 1, 2, 3]

########## Classes ##########

# Person:
#   name: string
#   surname: string
#   age: int

class Person:

    def __init__(self, name, surname, age):
        self.name = name
        self.surname = surname
        self.age = age
    
    def get_full_name(self):
        return self.name + " " + self.surname



selim = Person("Selim", "Guvenilir", 13)
nazir = Person("Nazir", "Nayal", 26)

print("Selim's full name is", selim.name, selim.surname)
print("Selim's full name is", selim.get_full_name())


lst = []
lst.append(selim)
lst.append(nazir)