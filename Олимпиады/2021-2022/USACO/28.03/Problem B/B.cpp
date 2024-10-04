#include <iostream>
#include <string>
using namespace std;

// Constants
const int Q_max = 1e5,
		  letters_amount = 26;

// Variables
string s,
	   t,
	   request;
int Q,
	s_size,
	t_size,
	request_size,
	s_letters[letters_amount + 5],
	t_letters[letters_amount + 5],
	s_letters_first_appear[letters_amount + 5],
	t_letters_first_appear[letters_amount + 5],
	s_letters_last_appear[letters_amount + 5],
	t_letters_last_appear[letters_amount + 5];
char _ans,
	 answers[Q_max + 5];
bool good_letters[letters_amount + 5];

// Functions
void input();
void solution();
void output(int);
void count_letters();
void clean_good_letters();
void mark_good_letters();
bool is_good_request();
int sum_of_letters(int*);
bool is_good_letters_amounts_equal();
bool is_letters_good_relative_pos();
bool check(int);

int main() {
	// Input
	cin >> s >> t >> Q;
	
	// Solution
	s_size = s.size();
	t_size = t.size();
	count_letters();
	
	for (int _q = 0; _q < Q; ++_q) {
		input();
		solution();
		output(_q);
	}
	
	// Output
	for (int i = 0; i < Q; ++i)
		cout << answers[i];
	cout << '\n';
	
	return 0;
}

void input() {
	cin >> request;
	return;
}

void solution() {
	request_size = request.size();
	clean_good_letters();
	mark_good_letters();
	
	_ans = (is_good_request() ? 'Y' : 'N');	
	return;
}

void output(int index) {
	answers[index] = _ans;	
	return;
}

void count_letters() {
	for (int i = 0; i < s_size; ++i) {
		if (!s_letters[s[i] - 'a'])
			s_letters_first_appear[s[i] - 'a'] = i;
		++s_letters[s[i] - 'a'];
		s_letters_last_appear[s[i] - 'a'] = i;
	}
	
	for (int i = 0; i < t_size; ++i) {
		if (!t_letters[t[i] - 'a'])
			t_letters_first_appear[t[i] - 'a'] = i;
		++t_letters[t[i] - 'a'];
		t_letters_last_appear[t[i] - 'a'] = i;
	}
	
	return;
}

void clean_good_letters() {
	for (int i = 0; i < letters_amount; ++i)
		good_letters[i] = false;
	return;
}

void mark_good_letters() {
	for (int i = 0; i < request_size; ++i)
		good_letters[request[i] - 'a'] = true;
	return;
}

bool is_good_request() {
	if (!is_good_letters_amounts_equal())
		return false;
	if (!is_letters_good_relative_pos())
		return false;
	if (!check(sum_of_letters(s_letters)))
		return false;
	return true;
}

int sum_of_letters(int *str_letters) {
	int counter = 0;
	for (int i = 0; i < request_size; ++i)
		counter += str_letters[request[i] - 'a'];
	return counter;
}

bool is_good_letters_amounts_equal() {
	for (int i = 0; i < request_size; ++i)
		if (s_letters[request[i] - 'a'] != t_letters[request[i] - 'a'])
			return false;
	return true;
}

bool is_letters_good_relative_pos() {
	for (int i = 0; i < request_size; ++i) {
		for (int j = i + 1; j < request_size; ++j) {
			if ( ( (s_letters_first_appear[request[i] - 'a'] < s_letters_first_appear[request[j] - 'a']) != (t_letters_first_appear[request[i] - 'a'] < t_letters_first_appear[request[j] - 'a']) )
			or ( (s_letters_last_appear[request[i] - 'a'] < s_letters_last_appear[request[j] - 'a']) != (t_letters_last_appear[request[i] - 'a'] < t_letters_last_appear[request[j] - 'a']) ) )
			return false;
		}
	}
	return true;
}

bool check(int good_letters_amount) {
	int s_index_begin = 0,
		t_index_begin = 0,
		s_index_end = s_size - 1,
		t_index_end = t_size - 1,
		founded = 0;
	bool flag = false;
	
	while (founded != good_letters_amount) {
		if (flag) {
			while (!good_letters[s[s_index_begin] - 'a'])
				++s_index_begin;
			while (!good_letters[t[t_index_begin] - 'a'])
				++t_index_begin;
			
			if (s[s_index_begin] != t[t_index_begin])
				return false;
			
			++s_index_begin;
			++t_index_begin;
		} else {
			while (!good_letters[s[s_index_end] - 'a'])
				--s_index_end;
			while (!good_letters[t[t_index_end] - 'a'])
				--t_index_end;
			
			if (s[s_index_end] != t[t_index_end])
				return false;
			
			--s_index_end;
			--t_index_end;
		}
		
		++founded;
		flag = !flag;
	}
	
	return true;
}
