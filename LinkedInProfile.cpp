#include "LinkedInProfile.h"

LinkedInProfile::LinkedInProfile(const char* name, const char* Uni, const char* W) : Profile(name)
{
	setUniversity(Uni);
	setWork(W);
}

void LinkedInProfile::setUniversity(const char* n)
{
	University = new char[strlen(n) + 1];
	strcpy(University, n);
}

void LinkedInProfile::setWork(const char* n)
{
	Work = new char[strlen(n) + 1];
	strcpy(Work, n);
}

const char* LinkedInProfile::getUniversity() const
{
	return University;
}

const char* LinkedInProfile::getWork() const
{
	return Work;
}

void LinkedInProfile::AddToFollowers(Profile* pPtr)
{
	LinkedInProfile* prof = dynamic_cast<LinkedInProfile*>(pPtr);
	if (prof == NULL)
	{
		cout << "Error : It is not a twitter Profile :(\n";
		return;
	}
	int followersNum = getFollowersNum();
	followers[followersNum] = pPtr;
	followersNum++;
	setFollowersNum(followersNum);
}

void LinkedInProfile::AddToFollowing(Profile* pPtr)
{
	LinkedInProfile* prof = dynamic_cast<LinkedInProfile*>(pPtr);
	if (prof == NULL)
	{
		cout << "Error : It is not a twitter Profile :(\n";
		return;
	}
	int followingNum = getFollowingNum();
	following[followingNum] = pPtr;
	followingNum++;
	setFollowingNum(followingNum);
}

void LinkedInProfile::Follow(Profile* pPtr)
{
	LinkedInProfile* prof = dynamic_cast<LinkedInProfile*>(pPtr);
	if (prof == NULL)
	{
		cout << "Error : It is not a LinkedIn profile :(\n";
		return;
	}

	if (strcmp(this->getUniversity(), prof->getUniversity()) == 0 || strcmp(this->getWork(), prof->getWork()) == 0)
	{
		// Add prof to the followers list of the current profile
		AddToFollowers(prof);

		// Add the current profile to the following list of prof
		prof->AddToFollowing(this);
	}

	else
		cout << "The profile " <<  prof->getName() << " and " << this->getName() 
		<< " are not in the same University or Work\n";
}

void LinkedInProfile::PrintInfo() const
{
	Profile::PrintInfo();
	cout << "University : " << University << "\n";
	cout << "Company Name : " << Work << "\n";
	cout << "-----------------------------------\n";

}

LinkedInProfile::~LinkedInProfile()
{
	delete[] University;
	delete[] Work;
}
