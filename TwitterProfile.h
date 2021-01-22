#pragma once
#include <iostream>
#include <cstring>
#include "Profile.h"
using namespace std;
class TwitterProfile : public Profile
{
	int tweets;
	bool IsPrivate;
public:
	TwitterProfile(const char* n);
	
	//Setters & Getters
	void setPrivate(bool p);
	void setTweets(int num);
	bool getPrivacy() const;
	int getTweets() const;

	//Virtual Functions
	virtual void AddToFollowers(Profile*);
	virtual void AddToFollowing(Profile*);
	virtual void Follow(Profile*);
	virtual void PrintInfo() const;
};

