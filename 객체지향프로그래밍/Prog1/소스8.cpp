#include<iostream>
#include<string>

using namespace std;

struct Human // 구조체란 서로 다른 종류의 데이터(변수들)를 하나로 묶어서 관리하기 위한 틀이다.
// 이와 유사한 기능이 class 라는 것이 있다. 
// 이 둘의 차이점은 기본 접근 제어자가 다르다.
// 구조체는 public이고 class는 private이다.
// 왜 사용하는가? 관련 데이터 묶음 - 여러 변수가 하나의 논리적인 개념을 나타낼 때, 
// 이 변수들을 구조체로 묶으면 코드의 가독성과 관리 효율이 크게 향상된다.
// 예) 학생 정보 (이름, 학번, 성적), 책 정보 (제목, 저자),날짜 (년, 월, 일)
{
private:
	int age, height, weight; // 사람의 나이,키,몸무게를 저장하는 멤버 변수 선언
	string name; // 이름을 저장할 수 있는 string 멤버 변수 선언
	char blood_type; // 혈액형을 나타내는 문자 멤버 변수 선언
	
public:
	Human() :age(0), height(0), weight(0), name("NULL"), blood_type('?')
		// 기본 생성자: 인자 없이 호출될 때 사용. 멤버 변수에 기본값을 설정한다.
	{

	}
	Human(int a, int h, int w, const string& n, char b)
		: age(a), height(h), weight(w), name(n), blood_type(b)
		// 매개변수 있는 생성자: 객체 생성 시 외부에서 값을 받아 초기화한다.
	{
	
	}

	int getAge() const // private의 변수들을 읽어오는 역할을 한다.
	{
		return age;
	}

	int getHeight() const // private의 변수들을 읽어오는 역할을 한다.
	{
		return height;
	}

	int getWeight() const // private의 변수들을 읽어오는 역할을 한다.
	{
		return weight;
	}

	const string& getName() const // private의 변수들을 읽어오는 역할을 한다.
	{
		return name;
	}

	char getBloodType() const // private의 변수들을 읽어오는 역할을 한다.
	{
		return blood_type;
	}

	void setAge(int newAge) // 새 나이 값을 인자로 받음
	{
		// 유효성 검사: 나이는 0보다 작을 수 없다.
		if (newAge >= 0 && newAge <= 120) 
		{
			age = newAge; // 유효하면 멤버 변수 age를 새 값으로 변경
			// cout << "나이 변경: " << age << endl; // 변경 확인 메시지
		}
		else
		{
			cerr << "오류: 유효하지 않은 나이 값 (" << newAge << "). 나이를 변경하지 않는다." << endl; // 오류 메시지
		}
	}

	// 키(height) 값을 설정하는 함수
	void setHeight(int newHeight)
	{
		// 유효성 검사: 키는 0보다 작거나 같을 수 없다.
		if (newHeight > 0 && newHeight < 300) 
		{
			height = newHeight; // 유효하면 변경
			// cout << "키 변경: " << height << endl;
		}
		else
		{
			cerr << "오류: 유효하지 않은 키 값 (" << newHeight << "). 키를 변경하지 않는다." << endl;
		}
	}

	// 몸무게(weight) 값을 설정하는 함수
	void setWeight(int newWeight)
	{
		// 유효성 검사: 몸무게는 0보다 작거나 같을 수 없다.
		if (newWeight > 0 && newWeight < 1000) 
		{
			weight = newWeight; // 유효하면 변경
			// cout << "몸무게 변경: " << weight << endl;
		}
		else
		{
			cerr << "오류: 유효하지 않은 몸무게 값 (" << newWeight << "). 몸무게를 변경하지 않는다." << endl;
		}
	}

	// 이름(name) 값을 설정하는 함수
	void setName(const string& newName) // string 값을 const string&로 받음
	{
		// 유효성 검사: 이름이 비어있지 않은지 확인
		if (!newName.empty()) // name.empty()는 string이 비어있으면 true 반환
		{
			name = newName; // 유효하면 변경
			// cout << "이름 변경: " << name << endl;
		}
		else
		{
			cerr << "오류: 이름은 비어있을 수 없다. 이름을 변경하지 않는다." << endl;
		}
	}

	void Print() const
	{
		cout << "이름 : " << name << endl;
		cout << "나이 : " << age << endl;
		cout << "키 :  " << height << endl;
		cout << "몸무게 : " << weight << endl;
		cout << "혈액형 : " << blood_type << endl;
	}
	void Printget_set() const
	{
		
		cout << "이름 : " << getName() << endl; // getName() getter 호출
		cout << "나이 : " << getAge() << endl;   // getAge() getter 호출
		cout << "키 : " << getHeight() << endl; // getHeight() getter 호출
		cout << "몸무게 : " << getWeight() << endl; // getWeight() getter 호출
		cout << "혈액형 : " << getBloodType() << endl; // getBloodType() getter 호출
		
	}
};


int main()
{
	//Human man;
	//man.Print();
	cout << endl;
	Human man2(25,170,67,"최종현",'B'); // 매개변수가 있을 때 초기화 방법
	man2.Print();
	
	cout << endl;
	Human man;
	man.setAge(25);
	man.setHeight(150);
	man.setWeight(75);
	man.setName("홍길동");
	man.Printget_set();
	
	
	return 0;
}