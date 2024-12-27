// OopChallenge.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <cstdlib>
#include <ctime>


class Animal {
public:
    Animal() {
        std::cout << "create Animal class" << std::endl;
    }

    virtual void makeSound() = 0;

    virtual ~Animal() {
        std::cout << "delete Animal class" << std::endl;
    }
};

class Dog : public Animal {
public:
    Dog() : Animal() {
        std::cout << "create Dog class" << std::endl;
    }
    void makeSound() override {
        std::cout << "개 소리" << std::endl;
    }

    ~Dog() override {
        std::cout << "delete Dog class" << std::endl;
    }
};

class Cat : public Animal {
public:
    Cat() {
        std::cout << "create Cat class" << std::endl;
    }
    void makeSound() override {
        std::cout << "고양이 소리" << std::endl;
    }

    ~Cat() override {
        std::cout << "delete Cat class" << std::endl;
    }
};

class Cow : public Animal {
public:
    Cow() {
        std::cout << "create Cow class" << std::endl;
    }
    void makeSound() override {
        std::cout << "소 소리" << std::endl;
    }

    ~Cow() override {
        std::cout << "delete Cow class" << std::endl;
    }
};

class Zoo {
private:
    Animal* animals[10];

public:
    // 동물을 동물원에 추가하는 함수
    // - Animal 객체의 포인터를 받아 포인터 배열에 저장합니다.
    // - 같은 동물이라도 여러 번 추가될 수 있습니다.
    // - 입력 매개변수: Animal* (추가할 동물 객체)
    // - 반환값: 없음
    void addAnimal(Animal* animal) {
        for (int index{ 0 }; index < 10; index++) {
            if (animals[index] == nullptr) {
                animals[index] = animal;
                break;
            }
        }

    }

    // 동물원에 있는 모든 동물의 행동을 수행하는 함수
    // - 모든 동물 객체에 대해 순차적으로 소리를 내고 움직이는 동작을 실행합니다.
    // - 입력 매개변수: 없음
    // - 반환값: 없음
    void performActions() {
        int index{ 0 };
        while (index < 10 && animals[index] != nullptr) {
            this->animals[index]->makeSound();
            index++;
        }
    }

    // Zoo 소멸자
    // - Zoo 객체가 소멸될 때, 동물 벡터에 저장된 모든 동물 객체의 메모리를 해제합니다.
    // - 메모리 누수를 방지하기 위해 동적 할당된 Animal 객체를 `delete` 합니다.
    // - 입력 매개변수: 없음
    // - 반환값: 없음
    ~Zoo() {
        int index{ 0 };
        while (index < 10 && animals[index] != nullptr) {
            delete this->animals[index];
            index++;
        }
        std::cout << "delete Zoo class" << std::endl;
    }
};

// 랜덤 동물을 생성하는 함수
// - 0, 1, 2 중 하나의 난수를 생성하여 각각 Dog, Cat, Cow 객체 중 하나를 동적으로 생성합니다.
// - 생성된 객체는 Animal 타입의 포인터로 반환됩니다.
// - 입력 매개변수: 없음
// - 반환값: Animal* (생성된 동물 객체의 포인터)
Animal* createRandomAnimal() {
    switch (std::rand() % 3)
    {
    case 0:
        return new Dog();

    case 1:
        return new Cat();

    case 2:
        return new Cow();
    }

}

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    Zoo* zoo = new Zoo();

    for (int index{ 0 }; index < 10; index++) {
        zoo->addAnimal(createRandomAnimal());
    }

    zoo->performActions();

    zoo->~Zoo();
}


// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
