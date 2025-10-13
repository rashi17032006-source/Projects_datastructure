#eligible for voting or not
print("enter your age:")
age=int(input())
if age >= 18:
    print('hurrah!you are eligilbe')
else:
    print('so sorry baacha bade ho jao phele')
    

#find the vote center
print('now you are eligible then please find your voting venue')
print('enter your pincode')
pincode=int(input()) 
if pincode==284404:
    print('madawara')
elif pincode == 460402:
    print( 'patel nagar bhopal')
elif  pincode==285001:
    print('urai')
elif pincode==480661:
    print('seoni')
elif pincode==470661:
    print('damoh')