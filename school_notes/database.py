import pickle

# login system
username = input("Kullanıcı adınızı girin: ")
password = input("Şifrenizi girin: ")

login_authentication = {}
with open("login_authentication.pkl", "rb") as file:
    login_authentication = pickle.load(file)

pickle.dum

# account system

mat1 = int(input("Lütfen birinci dönem matematik notunuzu girin: "))
mat2 = int(input("Lütfen ikinci dönem matematik notunuzu girin: "))
turkce1 = int(input("Lütfen birinci dönem türkçe notunuzu girin: "))
turkce2 = int(input("Lütfen ikinci dönem türkçe notunuzu girin: "))

x = mat1 + mat2 + turkce1 + turkce2
x = x / 4

if x < 70:
    print("Belge alamadın.")
elif x < 85:
    print("Teşekkür aldın.")
else:
    print("Taktir aldın.")