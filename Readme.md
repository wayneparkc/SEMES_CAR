# SEMES_CAR PJT

### 1. SEMES_CAR

<b> 주요 특징 </b>
1. SUV, Truck, Sedan은 Car를 상속 받아 사용하였다.
2. Factory 패턴을 통해 Car 다형성을 구성하여 사용하였다.
    ```
    Car를 반환했지만, SUV, Truck, Sedan으로 구분하여 사용 가능.
    ```
3. unordered_map<int, functional<int>()>>를 통해, step 별로 함수를 호출하여
   if문을 최소화 하였다.
4. 코드를 해더 및 cpp로 분리하여 모듈화를 진행하였다.

<b> 세부 특징 </b>

    a. Car.cpp / h
       차량 부품, 차량 테스트, 차량 함수
    b. Sedan.cpp / h
       세단 전용 구조
    c. SUV.cpp / h
       SUV 전용 구조
    d. Truck.cpp / h
       Truck 전용 구조조
    e. console.cpp / h
       CLI 단계 별 관리
    f. part.h
       enum class를 통해 차량 부품 관리
    g. main.cpp
       Car.h, Console.h를 가져와
       main에서 서로 약한 결합으로 사용.

### 2. SEMES_CAR_GUI

<b> 주요 특징 </b>

1. 자동차 타입, 엔진 타입, 브레이크 타입, 조향장치 타입을 선택할 수 있다. 
2. 자동차 제조를 통해 서버로 선택한 옵션을 전송하고 결과를 받을 수 있다. 
3. 제조에 실패했을 경우, 서버로부터 에러 메세지를 받아 확인할 수 잇다. 
4. 제조에 성공했을 경우, 선택한 제조 옵션과 함께 결과창을 확인할 수 있다. 

<b>세부 특징</b>

    a. MainWindow.xaml
        자동차 제조 옵션 선택 창
    b. ResultWindow.xaml
        자동차 제조 성공 시 선택한 옵션을 확인할 수 있는 결과창
    c. ErrorDialog.xaml
        자동차 제조 실패 혹은 예외 발생 시 에러 로그를 확인할 수 있는 에러창

### 3. SEMES_CAR_SERVER

<b> 주요 특징 </b>
1. Socket를 통해 서버를 열어 사용자의 입력을 대기 한다.
2. 사용자가 전달한 4개의 인자를 변환하여, 차량 타입 및 부품을 선택한다.
3. Car 타입을 상속 받은 Sub의 오버라이딩 한 Test() 함수에서 부품을 검사한다.
4. 결과에 따라 SU, FA로 결과를 반환하고, 이유를 동봉하였다.
5. SEMES_CAR에서 구성한 헤더 및 cpp 구조를 재사용하였다.

<b> 세부 특징 </b>

    a. Car.cpp / h
       차량 부품, 차량 테스트
    b. Sedan.cpp / h
       세단 전용 테스트
    c. SUV.cpp / h
       SUV 전용 테스트
    d. Truck.cpp / h
       Truck 전용 테스트
    e. socket.cpp / h
       socket 서버 관리
    f. part.h
       enum class를 통해 차량 부품 관리
    g. main.cpp
       socket 서버 시작.
       
### 4. SEMES_CAR_CLI

<b> 주요 특징 </b>

<b> 세부 특징 </b>
