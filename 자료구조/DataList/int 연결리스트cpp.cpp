#include <iostream> 
#include <vector>  
#include <initializer_list> // 중괄호 초기화 {1, 2, 3} 를 사용하기 위해 필요
using namespace std;
class intList {

private:
    // vector<int> 를 사용하여 정수들을 저장
    // vector는 필요에 따라 자동으로 크기가 조절되는 편리한 배열
    vector<int> data;

public:
    // 1. 생성자 (객체가 처음 만들어질 때 호출되는 함수들)
    // 기본 생성자: 아무런 초기값 없이 빈 리스트를 만든다.
    // 특별한 코드가 없어도 내부의 vector가 자동으로 비어있는 상태로 초기화한다.
    intList() {};

    // 초기화 리스트 생성자: 중괄호 { } 안에 값들을 넣어 리스트를 생성할 수 있게 한다.
    intList(initializer_list<int> init_list) : data(init_list) 
    {
        // 멤버 초기화 리스트(: data(init_list))를 사용해서
        // vector를 전달받은 초기값들로 바로 초기화한다.
    }

    // 2. 멤버 함수 (객체가 할 수 있는 기능들)

    // 리스트의 맨 뒤에 정수 값을 추가하는 함수
    void add_element(int value) 
    {
        // vector의 push_back 함수를 사용하여 맨 뒤에 요소를 추가.
        data.push_back(value);
    }

    // 리스트에 저장된 모든 정수를 출력하는 함수
    // 함수 뒤에 'const'를 붙이면 이 함수는 멤버 변수의 내용을
    // 변경하지 않는다는 약속이다.
    void print_list() const 
    {
        if (data.empty()) 
        { // vector가 비어있는지 확인
            cout << "리스트가 비어있습니다.";
        }
        else 
        {
            // 범위 기반 for 루프를 사용하여 vector의 모든 요소를 출력.
            for (int element : data) 
            {
                cout << element << " ";
            }
        }
        cout << endl; // 줄바꿈
    }

    // 리스트에 저장된 정수의 개수를 반환하는 함수
    size_t get_size() const {
        // vector의 size 함수를 사용하여 저장된 요소의 개수를 반환.
        // size_t는 보통 부호 없는 정수(unsigned int) 타입.
        return data.size();
    }

    // 3. 소멸자 (객체가 메모리에서 사라지기 직전에 호출되는 함수)
    // 이 클래스는 vector를 사용하고 vector가 메모리 관리를 해주므로,
    // 직접 new/delete를 쓰지 않았다면 특별히 작성할 코드는 없다.
    ~intList() {
        cout << "intList 객체가 소멸되었습니다." << endl;
    }
};



int main() {
   
    // 1. 초기화 리스트 생성자를 사용하여 List1 객체 생성
    intList List1 = { 10, 20, 30 };
    List1.print_list(); // 생성된 리스트 내용 출력
    cout << "List1의 크기: " << List1.get_size() << endl;
 
    // 2. add_element 멤버 함수를 사용하여 요소 추가
    List1.add_element(40);
    List1.add_element(50);
    List1.print_list(); // 변경된 리스트 내용 출력
    cout << "List1의 크기: " << List1.get_size() << endl;

    // 3. 기본 생성자를 사용하여 비어있는 List2 객체 생성
    intList List2;
    List2.print_list(); // 비어있는 리스트 출력
    cout << "List2의 크기: " << List2.get_size() << endl;
  
    // 4. 비어있는 myList2에 요소 추가

    List2.add_element(5);
    List2.add_element(15);
    List2.add_element(25);

    List2.print_list(); // 변경된 리스트 내용 출력
    cout << "myList2의 크기: " << List2.get_size() << endl;
    return 0;
}