#include <iostream>
#include <vector>
using namespace std;

vector<int> arr(101, 0);
/*
	특정 숫자크기의 배열을 만든다.
*/

int main() {
	arr[1]=1;
	/*
		소수에서 1은 항상 예외 상황이므로 걸러준다.2
	*/
  for (int i = 2; i <= 100; i++) {
		/*
			여기서는 N개를 100으로 정했으므로 100이하의 숫자에서 체로 걸러내는 작업을 수행한다.
		*/
    if (arr[i] == 0) {
			/*
				만약 현재의 숫자가 한번도 걸러낸적이 없다면 현재 수는 소수이다.
			*/
      for (int j = 2; i * j <= 100; j++) {
        arr[i * j] = 1;
				/*
					현재 수 i는 소수이지만 i의 배수들은 당연히 소수가 아니다. 그러므로 미리 제거한다.
					중요한건 j를 1로 할 경우 현재 소수인 수도 제외되므로 주의할 필요가 있다.
				*/
      }
    }
  }
  for (int i = 1; i <= 100; i++) {
    cout << i << ":" << arr[i] << endl;
  }
  return 0;
}
