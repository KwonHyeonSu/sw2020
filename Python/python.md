#링크 : https://www.youtube.com/watch?v=kWiCuklohdY&t=315s

int(3.5) -> 3 #정부부분만 출력   

print("z"*9) -> ㅋㅋㅋㅋㅋㅋㅋㅋㅋ   
정수형을 프린트 : str(age)   

print(2**3) -> 8   

print(7/3) -> 2.3333   
print(7//3) -> 2   
print(7%3) -> 1   

not, and(&), or(|)   

abs(-5) -> 5   
pow(4,2) -> 16   
max(5,12) -> 12   
min(5,12) -> 5   
round(3.14) -> 3 (반올림)   

from math import * -> math 라이브러리 내의 모든 기능을 이용
   
> floor(4.99) -> 4 #내림      
> ceil(3.14) -> 4 #올림      
> sqrt(16) -> 4 #제곱근     

from random import *

random() -> 0.0 ~ 1.0 임의의 값   
randrange(1,46) #1~45   
randint(1,45) #1~45

# 문자열 포맷

#방법1
print("나는 %d살입니다." % 20)
print("나는 %s를 좋아해요." % "파이썬")
print("Apple은 %c로 시작해요" % "A")

print("나는 %s살입니다." % 20)
print("나는 %s색과 %s색을 좋아해요."% ("파란", "빨간"))


#방법2
print("나는 {}살입니다.".format(20))
print("나는 {0}색과 {1}색을 좋아해요.".format("파란", "빨간"))

#방법3
print("나는 {age}살이며, {color}색을 좋아해요.".format(age = 20, color = "빨간"))

#방법4
age = 20
color = "빨간"
print(f"나는 {age}살이며, {color}색을 좋아해요.")


# 사전

cabinet = {3:"유재석", 100:"김태호"}   
print(cabinet[3]) #유재석   
print(cabinet[100]) #김태호   

print(cabinet.get(3)) #유재석   
#print(cabinet[5]) #오류나고 프로그램 종료   
print(cabinet.get(5)) #오류 안나고 None 반환   
print("hi")   

print(3 in cabinet) #True   
print(5 in cabinet) #False   

cabinet = {"A-3":"유재석", "B-100":"김태호"}   
print(cabinet["A-3"])   
print(cabinet["B-100"])   

#새 손님   
print(cabinet)   
cabinet["A-3"] = "김종국"   
cabinet["C-20"] = "조세호"   
print(cabinet)   

#간 손님   
del cabinet["A-3"]   
print(cabinet)   

#ket 들만 출력    
print(cabinet.keys())   

#value 만 출력   
print(cabinet.values())   

#key, value 쌍으로 출력   
print(cabinet.items())   

cabinet.clear()   
print(cabinet)   

#튜플
#리스트는 []로 둘러싸지만, 튜플은 ()으로 둘러싼다.   
#리스트는 그 값의 생성, 삭제 수정이 가능하지만 튜플은 그 값을 바꿀 수 없다.   

menu = ("돈까스", "치즈까스")   
print(menu[0])  
print(menu[1])  

#menu.add("생선까스")  

#name = "김종국"  
#age = 20  
#hobby = "코딩"  
#print(name, age, hobby)  

(name, age, hobby) = ("김종국", 20, "코딩")  
print(name, age, hobby)  


# 세트(set : 집합)
#중복 안됨, 순서 없음   
my_set = {1,2,3,3,3}   
print(my_set)   

java = {"유재석", "김태호", "양세형"}  
python = set(["유재석", "박명수"])  

#교집합 (java 와 python을 모두 할 수 있는 개발자)  
print(java & python)  
print(java.intersection(python))  

#합집합 (java를 할 수 있거나 python 할 수 있는 개발자)  
print(java | python)  
print(java.union(python))  

#차집합 (java 할 수 있지만 python은 할 줄 모르는 개발자)  
print(java - python)  
print(java.difference(python))  

#파이선 할 줄 아는사람 늘어남  
python.add("김태호")  
print(python)  

#java를 잊었어요  
java.remove("김태호")  
print(java)  


# 퀴즈
from random import *

users = range(1, 21)
users = list(users)

print(users)
shuffle(users)
print(users)

winners = sample(users, 4)

print("-- 당첨자 발표 --")
print("치킨 당첨자 : {0}".format(winners[0]))
print("커피 당첨자 : {0}".format(winners[1:]))
print("-- 축하합니다 --")

# if

weather = input("오늘 날씨는 어때요? ")
if weather == "비" or weather == "눈":
    print("우산을 챙기세요")
elif weather == "미세먼지":
    print("마스크를 챙기세요")
else:
    print("준비물 필요 없어요.")

temp = int(input("기온은 어때요? "))
if 30 <= temp:
    print("너무 더워요. 나가지 마세요")
elif 10 <= temp and temp < 30 :
    print("괜찮은 날씨에요")
elif 0<= temp and temp <10:
    print("외투를 챙기세요")
else:
    print("너무 추워요. 나가지 마세요")

# for
for waiting_no in range(1, 6): #1,2,3,4,5
    print("대기번호 : {0}".format(waiting_no))

starbucks = ["아이언맨", "토르", "아이엠 그루트"]
for customer in starbucks:
    print("{0}, 커피가 준비되었습니다.".format(customer))
    
# while

customer = "토르"
index = 5
while index >= 1:
    print("{0} 커피가 준비 되었습니다. {1}번 남았어요.".format(customer, index))
    index -= 1
    if index==0 :
        print("커피는 폐기처분되었습니다.")

'''
customer = "아이언맨"
index = 1
while True:
    print("{0} 커피가 준비 되었습니다. 호출 {1}회".format(customer, index))
    index += 1
'''

customer = "토르"
person = "Unknown"

while person != customer:
    print("{0} 커피가 준비되었습니다.".format(customer))
    person = input("이름이 어떻게 되세요? ")

# continue, break  

absent = [2,5] #결석  
no_book = [7] #책을 깜빡했음  
for student in range(1, 11): #1,2,3,4,5,6,7,8,9,10  
    if student in absent:  
        continue #코드 실행 건너 뜀  
    elif student in no_book:  
        print("오늘 수업 여기까지. {0}는 교무실로 따라와".format(student))  
        break  
    print("{0}, 책을 읽어봐".format(student))  

# for한줄

#출석번호가 1 2 3 4 ,앞에 100을 붙이기로 함 -> 101, 102, 103, 104.   
student = [1,2,3,4,5]   
print(student)  
student = [i+100 for i in student]  
print(student)  
  
#학생 이름을 길이로 변환  
student = ["Iron man", "Thor", "I am groot"]  
student = [len(i) for i in student]  
print(student)  

#학생 이름을 대문자로 변환
student = ["Iron man", "Thor", "I am groot"]  
student = [i.upper() for i in student]  
print(student)  


# 퀴즈

from random import *  
  
cnt = 0 #총 탑승 승객 수  
for i in range(1, 51): #1~50  
    time = randrange(5, 51) #5분 ~ 50분  
    if 5<= time <= 15:  
        print("[0] {0}번째 손님 (소요시간 : {1}분)".format(i, time))  
        cnt += 1
    else:
        print("[ ] {0}번째 손님 (소요시간 : {1}분)".format(i, time))

print("총 탑승 승객 : {0} 분".format(cnt))


# 함수    
  
def open_account():    
    print("새로운 계좌가 생성되었습니다.")    

def deposit(balance, money): #입금  
    print("입금이 완료되었습니다. 잔액은 {0} 원입니다.".format(balance + money))  
    return balance + money  
  
def withdraw(balance, money):  
    if balance > money:  
        print("출금이 완료되었습니다. 잔액은 {0} 원입니다.".format(balance-money))  
        return balance-money  
    else:  
        print("출금이 완료되지 않았습니다. 잔액은 {0} 원입니다.".format(balance))  
        return balance  
  
def withdraw_night(balance, money): #저녁에 출금  
    commission = 100 #수수료 100원  
    return commission, balance - money - commission  
  
balance = 0 #잔액  
balance = deposit(balance, 1000)  
balance = withdraw(balance, 2000)  
commision, balance = withdraw_night(balance, 500)  
print("수수료 {0}원이며, 잔액은 {1}원입니다.".format(commision, balance))    

## 기본값

def profile(name, age, main_lang):  
    print("이름 : {0}\t나이 : {1}\t주 사용 언어 : {2}"\  
        .format(name, age, main_lang))  

profile("유재석", 20, "파이선")  
profile("김태호", 25, "자바")  

#같은 학교 같은 학년 같은 반 수업.  

def profile(name, age = 17, main_lang = "파이썬"):  
    print("이름 : {0}\t나이 : {1}\t주 사용 언어: {2}"\  
        .format(name, age, main_lang))  

profile("유재석")  
profile("김태호")  


## 키워드값

def profile(name, age, main_lang):  
    print(name, age, main_lang)  

profile(name = "유재석", main_lang =  "파이썬", age = 20)  
profile(main_lang = "자바", age = 25, name = "김태호")  


## 가변인자

'''  
def profile(name, age, lang1, lang2, lang3, lang4, lang5):  
    print("이름 : {0}\t나이 : {1}\t".format(name, age), end = "")  
    print(lang1, lang2, lang3, lang4, lang5)  
'''  
def profile(name, age, *language):  
    print("이름 : {0}\t나이 : {1}\t".format(name, age), end = "")  
    for lang in language:  
        print(lang, end = " ")  
    print()  
  
profile("유재석", 20, "Python", "Java", "C", "C++", "C#")  
profile("김태호", 25, "Kotlin", "Swift")  

# 지역변수와 전역변수   
gun = 10  

def checkpoint(soldiers): #경계근무  
    global gun  
    gun = gun - soldiers  
    print("[함수 내] 남은 총 : {0}".format(gun))  
  
def checkpoint_ret(gun, soldiers):  
    gun = gun - soldiers  
    print("[함수 내] 남은 총 : {0}".format(gun))  
    return gun  
  
print("전체 총 : {0}".format(gun))  
checkpoint(2)  
gun = checkpoint_ret(gun, 2)  
print("전체 총 : {0}".format(gun))  

# 표준 입출력  
scores = {"수학":0, "영어":50, "코딩":100}  
for subject, score in scores.items():   
    print(subject.ljust(8), str(score).rjust(4), sep=":")  

#은행 대기순번표  
#001, 002, 003, ...  
for num in range(1, 21):  
    print("대기번호 : " + str(num).zfill(3))  
  
answer = input("아무 값이나 입력하세요 : ")  
answer = 10  
print(type(answer))  
print("입력하신 값은 " + answer + "입니다.")  


# 출력 포맷   

#빈 자리는 빈공간으로 두고, 오른쪽 정렬을 하되, 총 10자리 공간을 확보  
print("{0: >10}".format(500))  
#양수일 땐 +로 표시, 음수일 땐 -로 표시  
print("{0: >+10}".format(500))  
print("{0: >10}".format(-500))  
  
#왼쪽 정렬하고, 빈칸으로 _로 채움  
print("{0:_<+10}".format(500))  
  
#3자리 마다 콤마를 찍어주기  
print("{0:,}".format(100000000000))  
  
#3자리 마다 콤마를 찍어주기, +-부호도 붙이기  
print("{0:+,}".format(100000000000))  
print("{0:+,}".format(-100000000000))  
  
#3자리 마다 콤마를 찍어주기, 부호도 붙이고, 자릿수 확보하기  
#돈이 많으면 행복하니까 빈 자리는 ^로 채워주기  
print("{0:^<+30,}".format(100000000000))  
  
#정리 - 각 자리별로 들어가야 하는 것 : print("{0:빈칸채우기 정렬여부 부호 차지하는자릿수 3자리마다콤마".format(~~~))  
  
#소수점 출력  
print("{0:f}".format(5/3))  
  
#소수점 특정 자리수 까지만 표시  
print("{0:.2f}".format(5/3))     
