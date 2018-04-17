#include "ResourceManager.h"
#include "ConfigManager.h"

int main()
{
	ResourceManager *rm = new ResourceManager();
	int counterPicture = 0;
	int counterImageSequence = 0;

	// get and release	
	PictureResource* asteroid = rm->GetResource<PictureResource>("smallasteroid");
	counterPicture = asteroid->GetRefCounter();

	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	window.clear();
	sf::Sprite* sprite = new sf::Sprite();
	
	//~~~~~~~~ This is a small test for ImageSequenceResource ~~~~~~~~~~
	ImageSequenceResource* girl = rm->GetResource<ImageSequenceResource>("girl");
	counterImageSequence = girl->GetRefCounter();
	std::vector<sf::Texture> _texturesGirl = girl->Get();

	sprite->setTexture(_texturesGirl[1]);
	window.draw(*sprite);
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	window.display();

	system("pause");

	rm->ReleaseResource("smallasteroid");
	counterPicture = asteroid->GetRefCounter();


	// uncomment for showing assert
	//window.clear();
	//img = asteroid->Get();
	//tx->loadFromImage(img);
	//sprite->setTexture(*tx);
	//window.draw(*sprite);
	//window.display();

	// release resouce with counter != 0
	counterPicture = asteroid->GetRefCounter();
	asteroid = rm->GetResource<PictureResource>("smallasteroid");
	asteroid = rm->GetResource<PictureResource>("smallasteroid");
	asteroid = rm->GetResource<PictureResource>("smallasteroid");
	asteroid = rm->GetResource<PictureResource>("smallasteroid");
	counterPicture = asteroid->GetRefCounter();
	rm->ReleaseResource("smallasteroid");
	rm->ReleaseResource("smallasteroid");
	counterPicture = asteroid->GetRefCounter();
	//rm->ReleaseAllResources();         // uncomment for showing assert

	// loading file not exist
	//AudioResource* sound = rm->GetResource<AudioResource>("booom");    // uncomment for showing assert

	// invalid resource key
	//AudioResource* sound = rm->GetResource<AudioResource>("booo");	 // uncomment for showing assert

	// release not loaded resource
	//rm->ReleaseResource("asteroid");            // uncomment for showing assert

	// release resource with invalid key
	//rm->ReleaseResource("aster");              // uncomment for showing assert

	// release 
	counterPicture = asteroid->GetRefCounter();
	while (asteroid->GetRefCounter() != 0)
	{
		rm->ReleaseResource("smallasteroid");
	}
	counterPicture = asteroid->GetRefCounter();

	// release resource with counter == 0
	counterPicture = asteroid->GetRefCounter();
	asteroid = rm->GetResource<PictureResource>("smallasteroid");
	asteroid = rm->GetResource<PictureResource>("smallasteroid");
	counterPicture = asteroid->GetRefCounter();
	rm->ReleaseResource("smallasteroid");
	rm->ReleaseResource("smallasteroid");
	//rm->ReleaseResource("smallasteroid");         // uncomment for showing assert
	counterPicture = asteroid->GetRefCounter();

	// uncorrect resource type
	//AudioResource* sound = rm->GetResource<AudioResource>("smallasteroid");         // uncomment for showing assert

	window.close();

    return 0;
}

