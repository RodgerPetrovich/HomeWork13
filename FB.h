#pragma once
#include<string>
#include <iostream>
#include <vector>
#define SIZE 10

using namespace std;

class FaceBook
{
public:
	struct Man
	{
		string name;
		int friendsCount;
		Man* friends[SIZE];
		Man(string name):name(name),friendsCount(0)
		{
			for (int i = 0; i < SIZE; i++)
			{
				friends[i] = 0;
			}
		}
	};
	FaceBook():peopleCount(0)
	{
		for (int i = 0; i < SIZE; i++)
		{
			people[i] = 0;
		}
	}

	void addMan(string name)
	{
		Man* man = new Man(name);
		people[peopleCount++] = man;
	}
	Man* getManByName(string name)
	{
		for (int i = 0; i < peopleCount; i++)
		{
			if (people[i]->name == name) return people[i];
		}
		return nullptr;
	}
	void addToFriend(string nameA,string nameB)
	{
		Man* a = getManByName(nameA);
		Man* b = getManByName(nameB);
		a->friends[a->friendsCount++] = b;
		b->friends[b->friendsCount++] = a;
	}
	void showFriends(string name)
	{
		Man* man = getManByName(name);
		for (int i = 0; i < man->friendsCount; i++)
		{
			cout << man->friends[i]->name<<", ";
		}
	}
	void HandShakeFriends(int num, string name)
	{
		string visited[SIZE];
		int visitNum = 0;
		cout << "друзья " << name << " до "<<num<<" рукопожатий - ";
		showFriendsFriends(num, name, visited,visitNum);
		cout << endl;
	}
	void showFriendsFriends(int num, string name, string* visited,int& visitNum)
	{

		if (num == 0)return;
		bool isVisit = false;
		visited[visitNum++] = name;
		Man* man = getManByName(name);
		for (int i = 0; i < man->friendsCount; i++)
		{
			for (int j = 0; j < visitNum; j++)
			{
				if (visited[j] == man->friends[i]->name) isVisit = true;
			}
			if (isVisit)continue;
			cout << man->friends[i]->name << " ";
			showFriendsFriends(num - 1, man->friends[i]->name, visited, visitNum);
		}
	}
	void showAllHandShakeFriends(int num)
	{
		for (int i = 0; i < peopleCount; i++)
		{
			HandShakeFriends(num,people[i]->name);
		}
	}

private:
	Man* people[SIZE];

	int peopleCount;
};