#include <iostream>
#include <bitset>
#include <algorithm>

using namespace std;
uint32_t reverseBits(uint32_t n) {
    string result="";
	while (n != 0)
	{
		result.append(to_string(n % 2));
		n /= 2;
	}
	while (result.size() <= 32) {
		result.push_back('0');
	}
	bitset<32> b(result);
	return (uint32_t)b.to_ulong();
}

int main()
{
    cout<<reverseBits(43261596)<<endl;
    return 0;
}