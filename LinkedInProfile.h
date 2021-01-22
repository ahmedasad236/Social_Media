#pragma once
#include <iostream>
#include <cstring>
#include "Profile.h"
using namespace std;

class LinkedInProfile : public Profile
{
	char* University;
	char* Work;
public:
	LinkedInProfile(const char* name, const char* Uni, const char* W);

	//Setters & Getters
	void setUniversity(const char* n);
	void setWork(const char* n);
	const char* getUniversity() const;
	const char* getWork() const;

	//Virtual Functions
	virtual void AddToFollowers(Profile*);
	virtual void AddToFollowing(Profile*);
	virtual void Follow(Profile*);
	virtual void PrintInfo() const;

	~LinkedInProfile();

};

