// P.S.: ������� ���������� � �������
// ������: ��� �����, �� ������� - ��� �����.
// ����� �� � ������� ������� ������� - �� ���� ����� � ��� �����.

#include <iostream>
#include <vector>
#include <algorithm>
#define it vector<int>::iterator
#define DELETED -1
#define UNDEFINED 0
using namespace std;

const int N_max = 1e6;

int V,
	E,
	v1,
	v2;
vector<int> G[N_max + 5];

int q[N_max + 5],
	l,
	r;
bool used[N_max + 5];

// ���������� ��� � ��������� UNDEFINED
int max_depth[N_max + 5],
	second_max[N_max + 5];

int longest_ways[N_max + 5],
	answer;

int get_max_depth(int);

int main() {
	// ������ ����
	cin >> V >> E;
	for (int i = 0; i < E; ++i) {
		cin >> v1 >> v2;
		G[v1].push_back(v2);
		G[v2].push_back(v1);
	}
	
	// ���������� ����������������� ���� � ������ (������� ������), ���������� �� ������ �������.
	// ����: ���� ����������� � ���, ��� ���� ������� ������� ��� ��������, �� ��� - ��� ��������,
	// ������� ����� �������.
	q[r++] = 1;
	used[1] = true;
	
	int current;
	while (l < r) {
		current = q[l++];
		// ���������� ������� ������� ����
		for (it i = G[current].begin(); i != G[current].end(); ++i)
			if (used[*i])
				*i = DELETED;
			else {
				q[r++] = *i;
				used[*i] = true;
			}
	}
	
	// ���������� max_depth[vertex] � second_max[vertex] ��� ���� vertex
	// (�� ����������� �������, ����� ���� ������� ����).
	// �������� �� �������� ����� �� ���� ������������ ��������� ����� (��������, �� ����, DFS-��).
	get_max_depth(1);
	
	for (int i = 1; i <= V; ++i)
		cout << "max[" << i << "] = " << max_depth[i] << "\tsecond_max[" << i << "] = " << second_max[i] << '\n';
	
	// �������� ������������� �������, �.�. � max_depth � second_max � �����
	// ������������ ���������� ������ ���� ("�������") � ������ �������.
	// ��������, ��� ����� "��������� �������" ����� �� ������� ������ "������� �������"
	// (������������� ���-�� ���� ����), ������� �������� �� ������� �� �������
	// (�� �������� � ��������� ������ � ������������� �������: ������ ���� ��������, � ������ - �����).
	for (int i = 1; i <= V; ++i)
		longest_ways[i] = max_depth[i] - 1 + second_max[i] - ( (second_max[i] == UNDEFINED) ? 0 : 1 );
	sort(longest_ways + 1, longest_ways + 1 + V);
	
	answer = longest_ways[V];
	cout << answer << '\n';
	
	return 0;
}

int get_max_depth(int vertex) {
	// �������� ������ ���, �.�. � ����� ������ � ���� �� ����� �������� ���� ���� �� ���� ����,
	// �.�. ����� ������� ������������ ����-�����, � ������� ��� ���� - DELETED.
	// � ����� ������ ����� ������� get_max_depth(*i) ��������� �� �����.
	// ����� ������� ������� ������ ������������� �������� ������� � ������, ���, �� ����, �������������� ������
	// (���� ���� �� ������).
	
	int tmp;
	for (it i = G[vertex].begin(); i != G[vertex].end(); ++i) {
		if (*i == DELETED)
			continue;
		
		tmp = get_max_depth(*i);
		
		if (max_depth[vertex] == UNDEFINED and second_max[vertex] == UNDEFINED)
			max_depth[vertex] = tmp + 1;
		else if (second_max[vertex] == UNDEFINED)
			second_max[vertex] = tmp + 1;
		else if (max_depth[vertex] < tmp + 1) {
			second_max[vertex] = max_depth[vertex];
			max_depth[vertex] = tmp + 1;
		} else if (second_max[vertex] < tmp + 1)
			second_max[vertex] = tmp + 1;
	}
	
	if (max_depth[vertex] == UNDEFINED)
		max_depth[vertex] = 1;
	return max_depth[vertex];
}
