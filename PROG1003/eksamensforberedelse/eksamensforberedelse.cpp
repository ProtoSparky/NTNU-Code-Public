#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <list>
using namespace std;
/*
class A {
protected:
	vector <string> navnene;
public:
	virtual void funk1(const string nvn) { navnene.push_back(nvn); }
	virtual void funk2() {
		for (auto const& val : navnene) cout << val << '\n';
	}
	void funk3() { cout << navnene.size(); }
	int funk4(const char ch) {
		int ant = 0;
		for (int i = 0; i < navnene.size(); i++)
			if (navnene[i].find(toupper(ch)) != string::npos ||
				navnene[i].find(tolower(ch)) != string::npos) ant++;
		return ant;
	}
};
class B : public A {
private:
	vector <int> moh;
public:
	void funk1(const string nvn, const int moh) {
		A::funk1(nvn); (this->moh).push_back(moh);
	}
	void funk2() {
		for (int i = 0; i < moh.size(); i++)
			cout << navnene[i] << '-' << moh[i] << " ";
	}
	void funk3() { cout << "Antall: "; A::funk3(); }
	int funk5(const int h1, const int h2) {
		int ant = 0;
		for (auto const& val : moh) if (val >= h1 && val <= h2) ant++;
		return ant;
	}
};
int main() {
	A* objA;
	B* objB = new B;
	objB->funk1("Mor", 345); objB->funk1("Ark", 123);
	objB->funk1("Far", 234); (*objB).funk2(); cout << '\n';
	objA = objB; objA->funk2(); cout << '\n';
	objB->funk1("Tur", 678); objB->funk1("Par", 567); objB->funk1("VAR", 789);
	objA->funk3(); cout << " "; objB->funk3(); cout << '\n';
	cout << objB->funk5(456, 765) << '\n';
	cout << objB->funk4('R') << " + " << objB->funk4('a') << '\n';
	return 0;
}
*/






/**
 * OPPGAVE 2.
 

#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;
int main() {
	map <int, char> m;
	queue <char> q;
	int antall = 0;
	string str;
	char ch;
	m[17] = 'N'; m[29] = 'L'; m[22] = 'A'; m[11] = 'S';
	m[7] = 'R'; m[15] = 'E'; m[6] = 'A';
	for (auto const& val : m) cout << val.second; cout << '\n';
	auto it = m.rbegin();
	while (it != m.rend()) q.push((it++)->second);
	for (int i = 0; i < q.size(); i++) {
		cout << q.front() << ' ';
		q.push(q.front()); q.pop();
	}
	cout << '\n';
	for (int i = 0; i < 4; i++) {
		str += q.front(); q.pop();
	}
	cout << str << '\n';
	auto it2 = m.begin(); advance(it2, 4);
	m.erase(it2, m.end());
	it2 = m.begin();
	while (it2 != m.end())
		cout << (it2++)->second;
	cout << '\n';
	for (int i = 0; i < str.length(); i++)
		for (auto const& val : m)
			if (val.second == str[i]) antall++;
	cout << antall << '\n';
	return 0;
}


*/


































int main(){
	list <int> tallliste;
	int siffer = 10225 % 10;

	for (int i = 10; i < (20 + siffer); i++) {
		if (!(i % 2)) {
			//i er partall 
			tallliste.push_front(i);
		}
		else {
			tallliste.push_back(i);
		}

	}

	for (auto nummer : tallliste) {

		cout << nummer << "\n"; 
	}
}
