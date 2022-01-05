/*#ifndef IOBSERVABLE
#define IOBSERVABLE

#include <vector>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class IObserver;

class ISubject
{
protected:
	std::vector<IObserver*> observersList;

public:
	ISubject();
	~ISubject() = default;

	virtual void attach(IObserver* observer) = 0;
	virtual void detach(IObserver* observer) = 0;

	virtual float getValue() = 0;
	virtual void setValue(float value) = 0;

	virtual void notifyAll() = 0;

	virtual  std::vector<IObserver*> getObserversList() = 0;

};

#endif
*/


