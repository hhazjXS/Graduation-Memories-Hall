#pragma once
#include<iostream>

using namespace std;


class Individual
{
private:
	string Name;
	string Password;
	string ID;

public:
	//���캯��
	Individual(string name, string password, string id) {
		Name = name;
		Password = password;
		ID = id;
	}
	//��������
	~Individual() {}

	virtual void Edit();

	virtual bool Login();

	virtual void Logout();

	virtual void Register();
};

