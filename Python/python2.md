# 파일 입출력  
  
'''  
#파일 쓰기  
score_file = open("score.txt", "w", encoding = "utf8")  
print("수학 : 0", file=score_file)  
print("영어 : 50", file=score_file)  
score_file.close()  
  
score_file = open("score.txt", "a", encoding="utf8")  
score_file.write("과학 : 80\n")  
score_file.write("코딩 : 100")  
score_file.close()  
  
'''  
  
'''  
#한줄씩 받기  
score_file = open("score.txt", "r", encoding = "utf8")  
print(score_file.readline(), end="") #줄별로 읽기, 한 줄 읽고 커서는 다음 줄로 이동  
print(score_file.readline(), end="")  
print(score_file.readline(), end="")  
print(score_file.readline(), end="")  
score_file.close()  
  
'''  
  
'''  
#파일이 총 몇 줄인지 모를 때  
score_file = open("score.txt", "r", encoding="utf8")  
while True:  
    line = score_file.readline()  
    if not line:   
        break  
    print(line, end="")  
score_file.close()  
  
'''  
  
score_file = open("score.txt", "r", encoding="utf8")  
lines = score_file.readlines() #list 형태로 저장  
for line in lines:  
    print(line, end="")  
score_file.close()    


# pickle  
  
'''  
#피클 쓰기  
  
import pickle  
profile_file = open("profile.pickle", "wb")  
profile = {"이름":"박명수", "나이":30, "취미":["축구","골프","코딩"]}  
print(profile)  
pickle.dump(profile, profile_file) #profile에 있는 정보를 file에 저장  
profile_file.close()  
  
'''  
  
#피클 읽기  
  
import pickle  
profile_file = open("profile.pickle", "rb")  
profile = pickle.load(profile_file) #file에 있는 정보를 profile에 불러오기  
print(profile)  
profile_file.close()  


# with - 파일처리 쉽게함 - close 적을 필요 없음  
'''  
  
with open("study.txt", "w", encoding="utf8") as study_file:  
    study_file.write("파이썬을 열심히 공부하고 있어요")  
  
'''  
  
with open("study.txt", "r", encoding="utf8") as study_file:  
    print(study_file.read())  


# 클래스  
  
class Unit:  
    def __init__(self, name, hp, damage):  
        self.name = name  
        self.hp = hp  
        self.damage = damage  
        print("{0} 유닛이 생성 되었습니다.".format(self.name))  
        print("체력 {0}, 공격력 {1}".format(self.hp, self.damage))  
  
  
marine1 = Unit("마린", 40, 5)  
marine2 = Unit("마린", 40, 5)  
tank = Unit("탱크", 150, 35)  

# 클래스  
  
class Unit:   
    def __init__(self, name, hp, damage):  
        self.name = name  
        self.hp = hp  
        self.damage = damage  
        print("{0} 유닛이 생성 되었습니다.".format(self.name))  
        print("체력 {0}, 공격력 {1}".format(self.hp, self.damage))  
  
  
marine1 = Unit("마린", 40, 5)   
marine2 = Unit("마린", 40, 5)    
tank = Unit("탱크", 150, 35)    
 
#레이스 : 공중 유닛, 비행기. 클로킹 (상대방에게 보이지 않음)  
wraith1 = Unit("레이스", 80, 5)  
print("유닛 이름 : {0}, 공격력 : {1}".format(wraith1.name, wraith1.damage))  
  
#마인드 컨트롤 스킬  
wraith2 = Unit("빼앗은 레이스", 80, 5)  
wraith2.clocking = True  
  
if wraith2.clocking == True:  
    print("{0} 는 현재 클로킹 상태입니다.".format(wraith2.name))  
  
# 클래스  


#일반 유닛  
class Unit:   
    def __init__(self, name, hp):  
        self.name = name  
        self.hp = hp   

class AttackUnit(Unit):
    def __init__(self, name, hp, damage):  
        Unit.__init__(self, name, hp)  
        self.damage = damage  

    def attack(self, location):  
        print("{0} : {1} 방향으로 적군을 공격 합니다. [공격력 {2}]"\
            .format(self.name, location, self.damage))  
  
    def damaged(self, damage):  
        print("{0} : {1} 데미지를 입었습니다.".format(self.name, damage))  
        self.hp -= damage  
        print("{0} : 현재 체력은 {1} 입니다.".format(self.name, self.hp))  
        if(self.hp <= 0):  
            print("{0} : 파괴되었습니다.".format(self.name))  
  
  
#파이어뱃 : 공격 유닛, 화염방사기.  
firebat1 = AttackUnit("파이어뱃", 50, 16)  
firebat1.attack("5시")  
  
firebat1.damaged(25)  
firebat1.damaged(25)  

# 클래스  


#일반 유닛  
class Unit:   
    def __init__(self, name, hp):  
        self.name = name  
        self.hp = hp   

class AttackUnit(Unit):
    def __init__(self, name, hp, damage):  
        Unit.__init__(self, name, hp)  
        self.damage = damage  

    def attack(self, location):  
        print("{0} : {1} 방향으로 적군을 공격 합니다. [공격력 {2}]"\  
            .format(self.name, location, self.damage))  
  
    def damaged(self, damage):  
        print("{0} : {1} 데미지를 입었습니다.".format(self.name, damage))   
        self.hp -= damage  
        print("{0} : 현재 체력은 {1} 입니다.".format(self.name, self.hp))    
        if(self.hp <= 0):    
            print("{0} : 파괴되었습니다.".format(self.name))    

#드랍쉽 : 공중 유닛, 수송기. 마린 / 파이어뱃 / 탱크 등을 수송. 공격 X  

#날 수 있는 기능을 가진 클래스  
class Flyable:  
    def __init__(self, flying_speed):  
        self.flying_speed = flying_speed  

    def fly(self, name, location):  
        print("{0} : {1} 방향으로 날아갑니다. [속도 {2}]"\  
            .format(name, location, self.flying_speed))  

#공중 공격 유닛 클래스  
class FlyableAttackUnit(AttackUnit, Flyable):  
    def __init__(self, name, hp, damage, flying_speed):  
        AttackUnit.__init__(self, name, hp, damage)  
        Flyable.__init__(self, flying_speed)  

#발키리 : 공중 공격 유닛, 한번에 14발 미사일 발사.  
valkyrie = FlyableAttackUnit("발키리", 200, 6, 5)  
valkyrie.fly(valkyrie.name, "3시")  

# super
#건물
class BuildingUnit(Unit):
    def __init__(self, name, hp, location):
        #Unit.__init__(self, name, hp, 0)
        super().__init__(name, hp, 0)
        self.location = location
        
# 퀴즈
class House:  
    def __init__(self, location, house_type, deal_type, price, completion_year):    
        self.location = location  
        self.house_type = house_type  
        self.price = price  
        self.deal_type = deal_type  
        self.completion_year = completion_year  
      
    def show_detail(self): 
        print(self.location , self.house_type, self.deal_type\  
            ,self.price, self.completion_year)  
      
houses = []  
house1 = House("강남", "아파트", "매매", "10억", "2010년")  
house2 = House("마포", "오피스텔", "전세", "5억", "2007년")    
house3 = House("송파", "빌라", "월세", "500/50", "2000년") 
houses.append(house1)   
houses.append(house2) 
houses.append(house3)   
  
print("총 {0}대의 매물이 있습니다.".format(len(houses)))  
for house in houses:  
    house.show_detail()  
  
# 예외처리

try:  
  
    print("나누기 전용 계산기입니다.")  
    nums = []  
    nums.append(int(input("첫 번째 : ")))  
    nums.append(int(input("두 번째 : ")))
    #nums.append(int(nums[0] / nums[1]))
  
    print("{0} / {1} = {2}".format(nums[0], nums[1], nums[2]))  
  
except ValueError:  
    print("에러! 잘못된 값을 입력하였습니다.")  
  
except ZeroDivisionError as err:  
    print(err)  

except Exception as err: #나머지 모든 오류  
    print("알 수 없는 에러가 발생하였습니다.") 
    print(err)   
    
# 일부러 에러 발생
  
try:  
    print("한 자리 숫자 나누기 전용 계산기입니다.")  
    num1 = int(input("첫 번째 숫자를 입력하세요 : "))  
    num2 = int(input("두 번째 숫자를 입력하세요 : "))  
    if num1 >= 10 or num2 >= 10:  
        raise ValueError  
    print("{0} / {1} = {2}".format(num1, num2, int(num1 / num2)))  
  
except ValueError:  
    print("잘못된 값을 입력하였습니다. 한 자리 숫자만 입력하세요")  
  

# 사용자 정의 예외처리  

class BigNumberError(Exception):  
    def __init__(self, msg):  
        self.msg = msg  

    def __str__(self):  
        return self.msg  
  
try:    
    print("한 자리 숫자 나누기 전용 계산기입니다.")    
    num1 = int(input("첫 번째 숫자를 입력하세요 : "))    
    num2 = int(input("두 번째 숫자를 입력하세요 : "))    
    if num1 >= 10 or num2 >= 10:    
        raise BigNumberError("입력값 : {0}, {1}".format(num1, num2))    
    print("{0} / {1} = {2}".format(num1, num2, int(num1 / num2)))    
    
except ValueError:    
    print("잘못된 값을 입력하였습니다. 한 자리 숫자만 입력하세요")    
    
except BigNumberError as err:    
    print("에러가 발생하였습니다. 한 자리 숫자만 입력하세요.")  
    print(err)  

# finally

class BigNumberError(Exception):  
    def __init__(self, msg):  
        self.msg = msg  

    def __str__(self):  
        return self.msg  
  
try:    
    print("한 자리 숫자 나누기 전용 계산기입니다.")    
    num1 = int(input("첫 번째 숫자를 입력하세요 : "))    
    num2 = int(input("두 번째 숫자를 입력하세요 : "))    
    if num1 >= 10 or num2 >= 10:    
        raise BigNumberError("입력값 : {0}, {1}".format(num1, num2))    
    print("{0} / {1} = {2}".format(num1, num2, int(num1 / num2)))    
    
except ValueError:    
    print("잘못된 값을 입력하였습니다. 한 자리 숫자만 입력하세요")    
    
except BigNumberError as err:    
    print("에러가 발생하였습니다. 한 자리 숫자만 입력하세요.")  
    print(err)  

finally:    
    print("계산기를 이용해 주셔서 감사합니다.")    


# 모듈  

import theater_module  
theater_module.price(3) #3명이서 영화보러 갔을 때 가격  
theater_module.price_morning(4)  
theater_module.price_soldier(8)  

import theater_module as mv  
mv.price(3)  
mv.price_morning(4)  
mv.price_soldier(5)  
  
from theater_module import *  
price(3)  
price_morning(4)  
price_soldier(5)  
  
from theater_module import price, price_morning  
price(3)  
price_morning(5)  

from theater_module import price_soldier as price  
price(5)  


```python
#일반 가격
def price(people):
    print("{0}명 가격은 {1}원 입니다.".format(people, people*10000))


#조조할인 가격
def price_morning(people):
    print("{0}명 조조할인 가격은 {1}원 입니다.".format(people, people*6000))


#군인할인 가격
def price_soldier(people):
    print("{0}명 군인 가격은 {1}원 입니다.".format(people, people*4000))
```


# 패키지(모듈의 집합)
```python
# from travel.thailand import ThailandPackage
# trip_to = ThailandPackage()
# trip_to.detail()

# from random import *
from travel import *
trip_to = vietnam.VietnamPackage()
trip_to = thailand.ThailandPackage()

trip_to.detail()
```

__init__.py
```python
__all__ = ["vietnam", "thailand"]
```
