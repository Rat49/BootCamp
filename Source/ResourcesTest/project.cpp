#include "ResourceManager.h"

int main()
{
	ResourceManager *rm = new ResourceManager();
	int counter = 0;

	// 1 get - 1 release	
	Picture* asteroid = rm->GetResource<Picture>("smallasteroid");
	counter = asteroid->GetRc();
	rm->ReleaseResource("smallasteroid");
	counter = asteroid->GetRc();

	// get > release
	counter = asteroid->GetRc();
	asteroid = rm->GetResource<Picture>("smallasteroid");
	asteroid = rm->GetResource<Picture>("smallasteroid");
	asteroid = rm->GetResource<Picture>("smallasteroid");
	asteroid = rm->GetResource<Picture>("smallasteroid");
	counter = asteroid->GetRc();
	rm->ReleaseResource("smallasteroid");
	rm->ReleaseResource("smallasteroid");
	counter = asteroid->GetRc();

	// get < release
	Audio* sound = rm->GetResource<Audio>("booom");
	sound = rm->GetResource<Audio>("booom");
	sound = rm->GetResource<Audio>("booom");
	sound = rm->GetResource<Audio>("booom");
	counter = sound->GetRc();
	rm->ReleaseResource("booom");
	rm->ReleaseResource("booom");
	rm->ReleaseResource("booom");
	rm->ReleaseResource("booom");
	counter = sound->GetRc();

	// release
	rm->ReleaseMemory();
	counter = sound->GetRc();
	counter = asteroid->GetRc();

	// release 
	while (asteroid->GetRc() != 0)
	{
		rm->ReleaseResource("smallasteroid");
	}

	// unvalid resourse key
	asteroid = rm->GetResource<Picture>("resourse");
	rm->ReleaseResource("resourse");

    return 0;
}

