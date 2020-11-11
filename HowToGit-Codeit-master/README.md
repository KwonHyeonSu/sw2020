# HowToGit-Codeit

git init -> 버전관리 시작 , .git 폴더 생성

commit 해야됨 -> 사용자 이름, 이메일 주소 지정하기

git config --global user.name "soo"
git config --global user.email "gustngusrud1@naver.com"

git add calculator.py

git commit -m "Create calulator.py" -> 커밋 메시지

git status -> 변경될 사항과 아닌 것을 확인

git add . -> 변경된 모든 사항을 staging Area에 추가

git reset calculator.py -> stating Area에서 제거

git push -> (local -> hub)

git pull -> (hub -> local)

git log -> 커밋 히스토리 내역 확인

git log --pretty=oneline -> 예쁘게 한줄로 출력

git show ->구체적으로 어떻게 수정이 되었는지

git commit -> -m 옵션 없이 긴 커밋 메시지를 저장 가능

git commit --amend -> 가장 최근에 수정한 commit 메시지 수정가능

git config alias.history 'log --pretty=oneline' -> git history라는 명령어가 git log --pretty=oneline이라는 명령어로 대체됨

git diff (첫번째 commit id) (두번째 commit id) ->  첫번째와 두번째의 commit 차이

git reset --hard (commit id) -> head를 바꾸어 working directory의 내용을 아얘 바꿔버림

git config alias.history 'log --pretty=oneline' -> 긴 코드를 한 명령어로 명시하기

git remote add origin https://github.com/kyuri-dev/Math_Box.git -> 리모트 레포지토리 만들기

git push -u origin master -> 리모트 레포지토리 'origin'에 master 브랜치 넣기 (처음에 push할 때 -u 명령어를 추가해야함)


```
Git은 내부적으로 크게 3가지 종류의 작업 영역을 두고 동작합니다.

각 작업 영역의 이름은

working directory
staging area
repository
```

git reset 뒤의 명령어 차이   

![image](https://user-images.githubusercontent.com/48755297/87432313-c8e72280-c622-11ea-85ec-bcf0ab467d75.png)

git reset --hard HEAD~2 -> Commit 2번 이전 내용으로
git reset --hard HEAD^ -> Commit 바로 이전 내용으로

git tag [태그 이름] [커밋 아이디] -> 태그 달기

git tag -> 태그 확인

git show [태그 이름] -> 태그와 관련된 Commit 보기

git branch -> 모든 branch 표시

git branch '브랜치 이름' -> branch 만들기

git branch -d test '브랜치 이름' -> branch 삭제

git checkout premium -> branch로 이동하기

git checkout -b '브랜치 이름' -> branch 만들고 바로 거기에 들어가기

git merge master -> 브랜치 병합 (master브랜치와 병합)

![image](https://user-images.githubusercontent.com/48755297/87853773-0364fe00-c948-11ea-82e4-87f271bdd623.png)

![image](https://user-images.githubusercontent.com/48755297/87853820-78d0ce80-c948-11ea-892b-9d889d3c0a7a.png)

git merge --abort -> merge 취소

> commit과 branch의 상세 설명 -> https://www.codeit.kr/learn/courses/version-control-with-git/2930

git fetch -> pull과 달리 merge하지 않고 가져오기만 함

git blame [파일 이름] -> 파일이 어떤 커밋에 의해 탄생했는지 내역을 보여줌

git revert [커밋 아이디] -> git reset과 비슷함. 하지만, push 할 수 있음

git revert [첫번째 커밋 아이디]...[두번째 커밋 아이디] -> 첫 번째 커밋부터 두 번째 커밋까지 revert 실행.

git reflog -> head가 가리키던 커밋의 history

git log --pretty=oneline --all --graph ->커밋과 브랜치의 흐름을 그래프로 보여줌

git rebase -> merge와 비슷함, 하지만커밋을 새로 만들지 않는다. (커밋 히스토리를 깔끔하게 만들어줌)

git stash -> 변경사항 임시저장

git stash list -> 임지저장 스택 확인

git stash apply -> 임시저장 스택 불러오기

git stash drop -> 스택 하나 없애기

git stash pop -> 스택 하나 불러오고 없애기

git cherry-pick [커밋 아이디] -> [커밋 아이디]만 가져오기


# 마지막 정리 노트

2. Git 써보기


git init : 현재 디렉토리를 Git이 관리하는 프로젝트 디렉토리(=working directory)로 설정하고 그 안에 레포지토리(.git 디렉토리) 생성


git config user.name 'codeit' : 현재 사용자의 아이디를 'codeit'으로 설정(커밋할 때 필요한 정보)


git config user.email 'teacher@codeit.kr' : 현재 사용자의 이메일 주소를 'teacher@codeit.kr'로 설정(커밋할 때 필요한 정보)


git add [파일 이름] : 수정사항이 있는 특정 파일을 staging area에 올리기


git add [디렉토리명] : 해당 디렉토리 내에서 수정사항이 있는 모든 파일들을 staging area에 올리기 


git add . : working directory 내의 수정사항이 있는 모든 파일들을 staging area에 올리기


git reset [파일 이름] : staging area에 올렸던 파일 다시 내리기


git status : Git이 현재 인식하고 있는 프로젝트 관련 내용들 출력(문제 상황이 발생했을 때 현재 상태를 파악하기 위해 활용하면 좋음) 


git commit -m "커밋 메시지" : 현재 staging area에 있는 것들 커밋으로 남기기


git help [커맨드 이름] : 사용법이 궁금한 Git 커맨드의 공식 메뉴얼 내용 출력






3. GitHub 시작하기


git push -u(또는 --set-upstream) origin master : 로컬 레포지토리의 내용을 처음으로 리모트 레포지토리에 올릴 때 사용합니다.


git push : 위의 커맨드를 한번 실행하고 난 후에는 git push라고만 쳐도 로컬 레포지토리의 내용을 리모트 레포지토리에 올릴 수 있습니다.


git pull : 바로 위의 위에 있는 커맨드를 한번 실행하고 난 후에는 git pull이라고만 쳐도 리모트 레포지토리의 내용을 로컬 레포지토리로 가져옵니다.


git clone [프로젝트의 GitHub 상 주소] : GitHub에 있는 프로젝트를 내 컴퓨터로 가져오기






4. Git에서 커밋 다루기


git log : 커밋 히스토리를 출력


git log --pretty=oneline : --pretty 옵션을 사용하면 커밋 히스토리를 다양한 방식으로 출력할 수 있습니다. --pretty 옵션에 oneline이라는 값을 주면 커밋 하나당 한 줄씩 출력해줍니다. --pretty 옵션에 대해 더 자세히 알고싶으면 이 링크를 참고하세요. 


git show [커밋 아이디] : 특정 커밋에서 어떤 변경사항이 있었는지 확인


git commit --amend : 최신 커밋을 다시 수정해서 새로운 커밋으로 만듦


git config alias.[별명] [커맨드] : 길이가 긴 커맨드에 별명을 붙여서 이후로는 별명으로도 해당 커맨드를 실행할 수 있게 설정


git diff [커밋 A의 아이디] [커밋 B의 아이디] : 두 커밋 간의 차이 비교


git reset [옵션] [커밋 아이디] : 옵션에 따라 하는 작업이 달라짐(옵션을 생략하면 --mixed 옵션이 적용됨) 


		(1) HEAD가 특정 커밋을 가리키도록 이동시킴(--soft는 여기까지 수행)

		(2) staging area도 특정 커밋처럼 리셋(--mixed는 여기까지 수행)

		(3) working directory도 특정 커밋처럼 리셋(--hard는 여기까지 수행)



		그리고 이때 커밋 아이디 대신 HEAD의 위치를 기준으로 한 표기법(예 : HEAD^, HEAD~3)을 사용해도 됨



git tag [태그 이름] [커밋 아이디] : 특정 커밋에 태그를 붙임






5. Git에서 브랜치 사용하기


git branch [새 브랜치 이름] : 새로운 브랜치를 생성


git checkout -b [새 브랜치 이름] : 새로운 브랜치를 생성하고 그 브랜치로 바로 이동


git branch -d [기존 브랜치 이름] : 브랜치 삭제


git checkout [기존 브랜치 이름] : 그 브랜치로 이동


git merge [기존 브랜치 이름] : 현재 브랜치에 다른 브랜치를 머지


git merge --abort : 머지를 하다가 conflict가 발생했을 때, 일단은 머지 작업을 취소하고 이전 상태로 돌아감






6. Git 실전 I


git fetch : 로컬 레포지토리에서 현재 HEAD가 가리키는 브랜치의 업스트림(upstream) 브랜치로부터 최신 커밋들을 가져옴(가져오기만 한다는 점에서, 가져와서 머지까지 하는 git pull과는 차이가 있음)


git blame : 특정 파일의 내용 한줄한줄이 어떤 커밋에 의해 생긴 것인지 출력 


git revert : 특정 커밋에서 이루어진 작업을 되돌리는(취소하는) 커밋을 새로 생성






7. Git 실전 Ⅱ


git reflog : HEAD가 그동안 가리켜왔던 커밋들의 기록을 출력


git log --all --graph : 모든 브랜치의 커밋 히스토리를, 커밋 간의 관계가 잘 드러나도록 그래프 형식으로 출력


git rebase [브랜치 이름] : A, B 브랜치가 있는 상태에서 지금 HEAD가 A 브랜치를 가리킬 때, git rebase B를 실행하면 A, B 브랜치가 분기하는 시작점이 된 공통 커밋 이후로부터 존재하는 A 브랜치 상의 커밋들이 그대로 B 브랜치의 최신 커밋 이후로 이어붙여짐(git merge와 같은 효과를 가지지만 커밋 히스토리가 한 줄로 깔끔하게 된다는 차이점이 있음)


git stash : 현재 작업 내용을 스택 영역에 저장


git stash apply [커밋 아이디] : 스택 영역에 저장된 가장 최근의(혹은 특정) 작업 내용을 working directory에 적용


git stash drop [커밋 아이디] : 스택 영역에 저장된 가장 최근의(혹은 특정) 작업 내용을 스택에서 삭제


git stash pop [커밋 아이디] : 스택 영역에 저장된 가장 최근의(혹은 특정) 작업 내용을 working directory에 적용하면서 스택에서 삭제


git cherry-pick [커밋 아이디] : 특정 커밋의 내용을 현재 커밋에 반영




! 그 밖에 알아야할 사실 

(1) git commit이라고만 쓰고 실행하면 커밋 메시지를 입력할 수 있는 텍스트 에디터 창이 뜹니다. 거기서 커밋 메시지를 입력하고 저장하고 나면 커밋이 이루어집니다.



(2) git push와 git pull은 그 작업 단위가 브랜치입니다. 예를 들어, master 브랜치에서 git push를 하면 master 브랜치의 내용만 리모트 레포지토리의 master 브랜치로 전송되지, premium 브랜치의 내용이 전송되는 것은 아닙니다.(git push에 --all이라는 옵션을 주면 모든 브랜치의 내용을 전송할 수 있기는 합니다.)





자, Git 토픽에서 배운 커맨드들을 쭉 정리해봤는데요. 기억이 다 잘 나시나요? 이 커맨드들만 제대로 이해하고 사용해도 여러분이 어디에서 어떤 일을 하든 Git을 사용할 때 불편함이 없을 겁니다. 혹시라도 Git으로 아주 세밀한 작업 또는 여기서 배우지 않은 새로운 커맨드를 써야한다고 할지라도 겁낼 필요가 없습니다. 이 토픽에서는 커맨드 뿐만 아니라 Git의 내부 동작 원리도 제대로 배웠기 때문에 여러분이 조금만 노력하면 그런 것들도 금방 쉽게 할 수 있을 겁니다. 



이제 어디를 가도 '나 Git 쓸 줄 알아!' 라고 자신있게 말할 수 있게 되신 여러분, 축하합니다! 


## 안상태 교수님 강의

conda env list : 콘다 가상환경 리스트확인

conda create -n my_env : 콘다 가상환경 만들기

conda env remove -n my_env : 콘다 가상환경 지우기

conda activate my_env : 가상환경 들어가기

conda deactivate : 가상환경 나오기





















