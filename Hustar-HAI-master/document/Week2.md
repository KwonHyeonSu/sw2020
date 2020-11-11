 ### Week 2 - Line Detecting
 ### **내용** 
 동영상으로 찍은 트랙을 OpenCV에서 Canny와 Hough transform을 이용해 Line Detecting을 하였고
 실시간으로 카메라 모듈로부터 영상 받아오기위헤 MJPG Streamer, Cheese, 라즈베리파이 카메라 모듈을 사용해 보았다.  
 
 자율주행용 Track   
 ![image1](/document/images/image2.jpg)    
 
 OpenCV를 이용한 Line Detecting   
 ![image1](/document/images/image3.jpg)
 ![image1](/document/images/image4.jpg)  

 실시간으로 선 따오기. 당시에는 노트북의 웹캠을 이용했고, 몇주 이후의 영상입니다. 클릭하면 영상으로 연결됩니다.
 [![실시간으로 선 따오기](https://j.gifs.com/0YKqnX.gif)](https://youtu.be/KJzmF9WuidM) 
 

 ### **어려웠던점**
  Line Detecting을 구현하는데 있어 시간이 오래 걸릴줄 알았지만 OpenCV라는 라이브러리를 이용하다보니 생긱보다 쉽게 Line Detecting을 
  할수 있었다. 하지만 실제로 Line을 검출할때 쓰이는 Hough Transform과 다른 개념을 이해하는데 어려움을 겪었다
 
 ### **배운점**  
 어떻게 구현해야 할까 막막했지만 OpenCV라는 라이브러리의 존재를 알게 되었고 YOLO 등 Python에서 제공하는 라이브러리의 다양성과 편리성에 대해
 알게되었다. 또 생각보다 같은 인터넷에 Open source code가 많아 이를 활용하여 코딩하는 방법을 배울 수 있었다.
 
 
 **박재성**   
 처음에는 자율주행을 하기 위해서는 어떤 기능들이 필요한지 고민하였다.
 그중 나온것이 차선인식이었지만 이것을 어떻게 해야하는지도 막막하게 느껴졌다. 여러가지 검색을 하면서 알아낸것이 OpenCV에서 제공하는 라이브러리를 사용하거나
 LaneNet, PathNet등을 활용하는 것이였다. 관련된 여러 논문들도 읽어 보면서 여러가지 방법을 써서 차선인식을 하고 싶었지만 우리가 성공할 수 있었던 것은 OpenCV뿐이였다..
 이마저도 검색을 통해 가져온 코드에서 이것저것 바꿔보며 어떤 역활을 하는지 알아보았고 또 거기에 사용된 수학적 개념(Hough Transform)들을 블로깅을 통해서 같이 공부해가면서
 프로젝트를 진행했다. 그래도 생각보다 여러가지 오픈소스들을 찾아보고 활용해보는 기회가 되었다.
 
 
 **양영우**   
 Colab에서 line detecting을 설계하기 전 MNIST를 이용하여 손글씨를 인식하는 법을 먼저 배운 뒤 line detecting을 시도하였다.   
 line detecting을 위해 이미지를 Blur를 처리한 후 Canny를 이용하여 모든 line을 찾은 뒤 관심 영역을 지정하고 허프 변환으로 line을 detecting하는 법을 배웠다.   
 허프 변환을 이용할 때 line을 완벽하게 받아오지 못하는 경우가 있어 Canny가 프로젝트에 더 맞는다고 생각할 수 있었다.   
 
 **권현수**  
 소프트웨어적으로 어떻게 영상에서 라인을 구분해낼 것인지, 방법은 이미 온라인에 많이 나와있었다. 그렇기에 깊게 공부할 필요 없이 몇가지 라이브러리와 함수를 통해 전처리 과정을 구현할 수 있었다.   이 때 파이선이란 언어가 얼마나 효율적이고 범용적인지 깨닫게 되었다. OpenCV라는 라이브러리를 이용하여 Canny 함수를 이용해 영상에서의 Edge부분을 찾아내는 과정을 거쳤다. 하지만, 원하는 만큼 Edge를 잘 찾지 못하여 인터넷에 찾아본 결과, 몇가지 전처리 과정을 더 거쳐야 한다는 것을 알았다. Gaussian blur처리를 하고, Mask를 씌워 원하는 부분의 line만 찾아내는 방법을 또한 배웠다.
 
 **윤동준**   
 RC카가 혼자 주행하기 위해서 어떤 것들이 필요한지 인터넷에서 조사를 하면서 알게 되었고, 데이터 전처리의 필요성을 알게 되었다. 그리고 tf.keras를 통해 딥러닝 학습을
 해봤다. 대부분의 사람들이 OPENCV Library를 사용하여 차선 인식을 한 것을 보고, Google Colab에 이미 나와있는 소스를 직접 쳐보면서 이해를 했다.
 image read->grayscale->gaussian_blur->canny edge detection->관심 영역 지정->HoughLineP(선을 그리는 함수)->원본과 선을 덮는다.
 이미지 말고 동영상 또한 OPENCV를 통해 차선을 딸 수 있따는 것을 알게 되었다. 
 <br/>어려웠던 점은 파이썬을 한번도 써보지 않아서 코드를 이해하기가 생각보다 힘들었다. 그래서 파이썬을 동시에 공부하면서 인공지능을 공부를 하였다. 
 <br/>Citation:
 <br/>https://colab.research.google.com/drive/16fSbCyLntAUWtHE0bfGG8XLOq16Ut-l_#scrollTo=trE76Xl7oJRS\ 
 <br/>https://pinkwink.kr/1264
 
 **이상목**
 
 
 **이진우**   
