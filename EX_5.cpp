#include <iostream>
#include <cstring>
#include "LinkedInProfile.h"
#include "Profile.h"
#include "TwitterProfile.h"

using namespace std;
int main()
{
	Profile* profiles[6];
	profiles[0] = new LinkedInProfile("Ahmed", "Cairo University", "IBM");
	profiles[1] = new LinkedInProfile("Mai", "Cairo University", "Student");
	profiles[2] = new LinkedInProfile("Omar", "Alexanderia University", "Microsoft");
	profiles[3] = new TwitterProfile("Adam");
	profiles[4] = new TwitterProfile("Kareem");
	profiles[5] = new TwitterProfile("Dina");

	// Ahmed Follows Mai and Omar
	profiles[1]->Follow(profiles[0]);
	profiles[2]->Follow(profiles[0]);
	
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
	profiles[0]->PrintInfo();
	profiles[1]->PrintInfo();
	profiles[2]->PrintInfo();
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";

	// Omar follows Mai
	profiles[1]->Follow(profiles[2]);

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
	profiles[0]->PrintInfo();
	profiles[1]->PrintInfo();
	profiles[2]->PrintInfo();
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";

	// Kareem made his profile private
	((TwitterProfile*)profiles[4])->setPrivate(1);

	// Kareem Follows Adam and Dina
	profiles[3]->Follow(profiles[4]);
	profiles[5]->Follow(profiles[4]);

	// Adam Follows back Kareem
	profiles[4]->Follow(profiles[3]);

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
	profiles[3]->PrintInfo();
	profiles[4]->PrintInfo();
	profiles[5]->PrintInfo();
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";

	// Kareem made his profile public
	((TwitterProfile*)profiles[4])->setPrivate(0);

	// Dina follows back Kareem
	profiles[4]->Follow(profiles[5]);

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
	profiles[3]->PrintInfo();
	profiles[4]->PrintInfo();
	profiles[5]->PrintInfo();
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";

	// Adam Unfollow Kareem
	profiles[3]->Unfollow(profiles[4]);

	// Check if Adam follows Kareem 
	bool test = profiles[3]->IsFollow(profiles[4]);
	if (test) cout << "Adam follows Kareem\n";
	else cout << "Adam does not follow Kareem\n";

	//check if Adam follows Dina
	test = profiles[3]->IsFollow(profiles[5]);
	if (test) cout << "Adam follows Dina\n";
	else cout << "Adam does not follow Dina\n";

	// Adam Follows Omar
	profiles[2]->Follow(profiles[3]);
	
	// Printing All Profiles
	for (int i = 0; i < 6; i++)
		profiles[i]->PrintInfo();

	// Deallocate all profiles
	for (int i = 0; i < 6; i++)
	{
		delete profiles[i];
		profiles[i] = NULL;
	}
	return 0;
}